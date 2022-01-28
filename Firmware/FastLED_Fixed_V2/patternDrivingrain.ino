
void patternDrivingrain(){
  int numLoops = 32;

  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }

  //seed the pattern with a pixel
  if (seed == 1){    
    currentmode = mode;
    frameloops = 0;
    //seed pixels
    pixelSeed1 = 1;
    pixelSeed2 = 1;
    pixelSeed3 = 1;
    pixelSeed4 = 1;
    seed = 0;
    lastPattern = currentPattern;
  }

  //GENERATE PIXELS
  //PIXEL1
  if (pixelSeed1 == 1){
        pixelDir1 = random(2);
    if (pixelDir1 == 1){
      pixelDir1 = 5;
    }
    if (pixelDir1 == 0){
      pixelDir1 = 8;
    }
    pixelCol1 = 0;
    pixelRow1 = random(numRows);
    pixelSeed1 = 0;
  }

  //PIXEL2
  if(looptimes > 1){
    if (pixelSeed2 == 1 && (pixelCol1 > numCols/looptimes)){
      pixelDir2 = random(2);
      if (pixelDir2 == 1){
        pixelDir2 = 5;
      }
      if (pixelDir2 == 0){
        pixelDir2 = 8;
      }
      pixelCol2 = 0;
      pixelRow2 = random(numRows);
      pixelSeed2 = 0;
    }
  }

  //PIXEL3
  if(mode > 2){
    if ((pixelSeed3 == 1) && (pixelCol2 > numCols/looptimes)){
      pixelDir3 = random(2);
      if (pixelDir3 == 1){
        pixelDir3 = 5;
      }
      if (pixelDir3 == 0){
        pixelDir3 = 8;
      }
      pixelCol3 = 0;
      pixelRow3 = random(numRows);
      pixelSeed3 = 0;
    }
  }

  //PIXEL4
  if(mode > 3){
    if ((pixelSeed4 == 1) && (pixelCol3 > numCols/looptimes)){
      pixelDir4 = random(2);
      if (pixelDir4 == 1){
        pixelDir4 = 5;
      }
      if (pixelDir4 == 0){
        pixelDir4 = 8;
      }
      pixelCol4 = 0;
      pixelRow4 = random(numRows);
      pixelSeed4 = 0;
    }
  }

   
  //clear the frame array
  memset(patternArray,0,sizeof(patternArray)); 

  //place the pixel in the frame array    
  //patternArray[pixelCol1][pixelRow1] = 1;
  bitWrite(patternArray[divi(pixelCol1, pixelRow1,patternCols )], modi(pixelCol1, pixelRow1, patternCols), 1);
  if(looptimes >1){
    bitWrite(patternArray[divi(pixelCol2, pixelRow2,patternCols )], modi(pixelCol2, pixelRow2, patternCols), 1);
  //patternArray[pixelCol2][pixelRow2] = 1;
  }
  if(looptimes >2){
    bitWrite(patternArray[divi(pixelCol3, pixelRow3,patternCols )], modi(pixelCol3, pixelRow3, patternCols), 1);
  //patternArray[pixelCol3][pixelRow3] = 1;
  }
  if(looptimes >3){
    bitWrite(patternArray[divi(pixelCol4, pixelRow4,patternCols )], modi(pixelCol4, pixelRow4, patternCols), 1);
  //patternArray[pixelCol4][pixelRow4] = 1;
  }
  
  //LAY THE FRAME ARRAY OVER THE LED ARRAY
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){
      bitWrite(LEDArray[divi(col,  row, numCols)], modi(col, row, numCols), bitRead(patternArray[divi(numCols - 1 - col,  row, patternCols)],modi(numCols - 1 - col, row, patternCols)));
      //LEDArray[col][row] = patternArray[numCols - 1 - col][row];
    }
  }

  //update glowArray
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){      
      glowArray[col][row] = glowArray[col][row]*glow ;            
      glowArray[col][row] = glowArray[col][row]+bitRead(LEDArray[divi(col,  row, numCols)], modi(col, row, numCols));
      constrain(glowArray[col][row], 0, 1);
      if (bitRead(LEDArray[divi(col,  row, numCols)],  modi(col, row, numCols)) == 1 ){
        colourArray[col][row] [r] = redintensity;
        colourArray[col][row] [g] = greenintensity;
        colourArray[col][row] [b] = blueintensity;
      }
    }
  }

  //SEED PIXELS THAT FALL OFF

  //BOUNCE PIXEL1
  if ((pixelDir1 == 8) && (pixelRow1 == 0)){
    pixelSeed1 = 1;
  }

  if ( (pixelDir1 == 5) && (pixelRow1 == numRows-1)){
    pixelSeed1 = 1;
  }

  if (pixelCol1 >= numCols){
    pixelSeed1 = 1;
  } 
  //BOUNCE PIXEL2
  if ((pixelDir2 == 8) && (pixelRow2 == 0)){
    pixelSeed2 = 1;
  }

  if ( (pixelDir2 == 5) && (pixelRow2 == numRows-1)){
    pixelSeed2 = 1;
  }

  if (pixelCol2 >= numCols){
    pixelSeed2 = 1;
  } 
  //BOUNCE PIXEL3
  if ((pixelDir3 == 8) && (pixelRow3 == 0)){
    pixelSeed3 = 1;
  }

  if ( (pixelDir3 == 5) && (pixelRow3 == numRows-1)){
    pixelSeed3 = 1;
  }

  if (pixelCol3 >= numCols){
    pixelSeed3 = 1;
  } 
  //BOUNCE PIXEL4
  if ((pixelDir4 == 8) && (pixelRow4 == 0)){
    pixelSeed4 = 1;
  }

  if ( (pixelDir4 == 5) && (pixelRow4 == numRows-1)){
    pixelSeed4 = 1;
  }

  if (pixelCol4 >= numCols){
    pixelSeed4 = 1;
  } 

  //PUSH PIXEL1
  dir = pixelDir1;
  if (mode == 1){
    dir = 5;
  }
  if (mode == 2) {
    dir = 8;
  }
  setshift();
  pixelCol1 = pixelCol1 + colShift;
  pixelRow1 = pixelRow1 + rowShift;
  pixelStep1 = pixelStep1 + 1;

  //PUSH PIXEL2

  dir = pixelDir2;
  if (mode == 1){
    dir = 5;
  }
  if (mode == 2) {
    dir = 8;
  }
  setshift();
  pixelCol2 = pixelCol2 + colShift;
  pixelRow2 = pixelRow2 + rowShift;



  //PUSH PIXEL3
  dir = pixelDir3;
    if (mode == 1){
    dir = 5;
  }
  if (mode == 2) {
    dir = 8;
  }
  setshift();
  pixelCol3 = pixelCol3 + colShift;
  pixelRow3 = pixelRow3 + rowShift;
  
  //PUSH PIXEL4
  dir = pixelDir4;
    if (mode == 1){
    dir = 5;
  }
  if (mode == 2) {
    dir = 8;
  }
  setshift();
  pixelCol4 = pixelCol4 + colShift;
  pixelRow4 = pixelRow4 + rowShift;
      
  triggernow = 0;
  frameloops = frameloops +1;

  if (frameloops == (numRows + numCols)/2){
    loopCount = loopCount +1; 
    frameloops = 0;
  }

  if (loopCount == numLoops){
    loopCount = 0;
    currentPattern = currentPattern +1; 

  }
}
