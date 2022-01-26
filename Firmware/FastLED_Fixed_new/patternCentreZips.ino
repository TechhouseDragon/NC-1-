const int numRowsCentreZips = numRows;
const int numColsCentreZips = numCols;

int newRowCentreZips;
int newColCentreZips;

void patternCentreZips(){
  int frameloops = 16;
  int numLoops = 16;

  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }

  //seed the pattern with a pixel
  if (seed == 1){
    pixelSeed1 = 1;
    pixelSeed2 = 1;
    pixelSeed3 = 1;
    pixelSeed4 = 1;
    seed = 0;
    lastPattern = currentPattern;
    frameStep = 0;
    loopCount = 0;
  }

  //GENERATE PIXELS
  
  //PIXEL1
  if (pixelSeed1 == 1){
    pixelStep1 = 1;

if (mode==1){
    pixelDir1 = random(3)*2;
}

if (mode==2){
    pixelDir1 = random(5,9);
}

if (mode>=3){
    pixelDir1 = random(2,9);
    if (pixelDir1 == 3){
      pixelDir1 = 4;
    }
   }

    pixelRow1 = 5;
    pixelCol1 = random(numCols+1);
    pixelSeed1 = 0;
  }


//Pixel 2
if ((looptimes > 1)&&(pixelSeed2 == 1)&& (pixelStep1 >= numRowsCentreZips/looptimes)){
    pixelStep2 = 1;

if (mode==1){
    pixelDir2 = random(3)*2;
}
if (mode==2){
    pixelDir2 = random(5,9);
}
if (mode>=3){
    pixelDir2 = random(2,9);
    if (pixelDir2 == 3){
      pixelDir2 = 4;
    }
   }
    pixelRow2 = 5;
    pixelCol2 = random(numCols+1);
    pixelSeed2 = 0;
  }

   
   //Pixel 3
  if ((looptimes > 2)&&(pixelSeed3 == 1)&& (pixelStep2 >= numRowsCentreZips/looptimes)){
    pixelStep3 = 1;

if (mode==1){
    pixelDir3 = random(3)*2;
}
if (mode==2){
    pixelDir3 = random(5,9);
}
if (mode>=3){
    pixelDir3 = random(2,9);
    if (pixelDir3 == 3){
      pixelDir3 = 4;
    }
   }
    pixelRow3 = 5;
    pixelCol3 = random(numCols+1);
    pixelSeed3 = 0;
  }

   
  //END PIXEL 3
  
  
   //Pixel 4
  if ((looptimes > 2)&&(pixelSeed4 == 1)&& (pixelStep3 >= numRowsCentreZips/looptimes)){
    pixelStep4 = 1;

if (mode==1){
    pixelDir4 = random(3)*2;
}
if (mode==2){
    pixelDir4 = random(5,9);
}
if (mode>=3){
    pixelDir4 = random(2,9);
    if (pixelDir4 == 3){
      pixelDir4 = 4;
    }
   }
   
    pixelRow4 = 5;
    pixelCol4 = random(numCols+1);
    pixelSeed4 = 0;
  }
  
  //END PIXEL 4

  //clear the frame array
  memset(patternArray,0,sizeof(patternArray)); 

  //place the pixel in the frame array    
//  patternArray[pixelCol1][pixelRow1] = 1;
  bitWrite(patternArray[divi(pixelCol1,  pixelRow1,patternCols )], modi(pixelCol1,  pixelRow1, patternCols), 1);
  if (mode==4){
    bitWrite(patternArray[divi(pixelCol1,  11-pixelRow1,patternCols )], modi(pixelCol1,  11-pixelRow1, patternCols), 1);
      //patternArray[pixelCol1][11-pixelRow1] = 1;
  }
  if (looptimes > 1){
     bitWrite(patternArray[divi(pixelCol2,  pixelRow2,patternCols )], modi(pixelCol2,  pixelRow2, patternCols), 1);
//      patternArray[pixelCol2][pixelRow2] = 1;
    if (mode==4){  
        bitWrite(patternArray[divi(pixelCol2,  11-pixelRow2,patternCols )], modi(pixelCol2,  11-pixelRow2, patternCols), 1);     
    //    patternArray[pixelCol2][11-pixelRow2] = 1;
    }
  }
  if (looptimes > 2){
    bitWrite(patternArray[divi(pixelCol3,  pixelRow3,patternCols )], modi(pixelCol3,  pixelRow3, patternCols), 1);
  //  patternArray[pixelCol3][pixelRow3] = 1;
      if (mode==4){
        bitWrite(patternArray[divi(pixelCol3,  11-pixelRow3,patternCols )], modi(pixelCol3,  11-pixelRow3, patternCols), 1);
    //    patternArray[pixelCol3][11-pixelRow3] = 1;
  }
  }
  if (looptimes > 3){
    bitWrite(patternArray[divi(pixelCol4,  pixelRow4,patternCols )], modi(pixelCol4,  pixelRow4, patternCols), 1);
 //   patternArray[pixelCol4][pixelRow4] = 1;
      if (mode==4){
        bitWrite(patternArray[divi(pixelCol4,  11-pixelRow4,patternCols )], modi(pixelCol4,  11-pixelRow4, patternCols), 1);
 //       patternArray[pixelCol4][11-pixelRow4] = 1;
  }
  }

  //LAY THE FRAME ARRAY OVER THE LED ARRAY
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){
      bitWrite(LEDArray[divi(col,  row, numCols)], modi(col, row, numCols), bitRead(patternArray[divi(col,  row, patternCols)],modi(col, row, patternCols)));
      //LEDArray[col][row] = patternArray[col][row];
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
      }    }
  }

  //PUSH PIXEL1
  dir = pixelDir1;
  setshift();
  pixelCol1 = pixelCol1 + colShift;
  pixelRow1 = pixelRow1 + rowShift;
  pixelStep1 = pixelStep1 + 1;

  if ((pixelDir1%2 != 0) && (pixelStep1 > (numColsCentreZips))){
    pixelSeed1 = 1;
  }
  if ((pixelDir1%2 == 0) && (pixelStep1 > (numRowsCentreZips))){
    pixelSeed1 = 1;
  }
// END PUSH 1

  //PUSH PIXEL2
  dir = pixelDir2;
  setshift();
  pixelCol2 = pixelCol2 + colShift;
  pixelRow2 = pixelRow2 + rowShift;
  pixelStep2 = pixelStep2 + 1;

  if ((pixelDir2%2 != 0) && (pixelStep2 > numColsCentreZips)){
    pixelSeed2 = 1;
  }
  if ((pixelDir2%2 == 0) && (pixelStep2 > numRowsCentreZips)){
    pixelSeed2 = 1;
  }
//END PUSH 2

  //PUSH PIXEL3
  dir = pixelDir3;
  setshift();
  pixelCol3 = pixelCol3 + colShift;
  pixelRow3 = pixelRow3 + rowShift;
  pixelStep3 = pixelStep3 + 1;

  if ((pixelDir3%2 != 0) && (pixelStep3 > numColsCentreZips)){
    pixelSeed3 = 1;
  }
  if ((pixelDir3%2 == 0) && (pixelStep3 > numRowsCentreZips)){
    pixelSeed3 = 1;
  }
//END PUSH 3

  //PUSH PIXEL4
  dir = pixelDir4;
  setshift();
  pixelCol4 = pixelCol4 + colShift;
  pixelRow4 = pixelRow4 + rowShift;
  pixelStep4 = pixelStep4 + 1;

  if ((pixelDir4%2 != 0) && (pixelStep4 > numColsCentreZips)){
    pixelSeed4 = 1;
  }
  if ((pixelDir4%2 == 0) && (pixelStep4 > numRowsCentreZips)){
    pixelSeed4 = 1;
  }
//END PUSH 4

  triggernow = 0;
  frameStep = frameStep +1;

if (frameStep >= frameloops){ 
    frameStep = 0;
    loopCount = loopCount +1; 
}

  if (loopCount >= numLoops){
    loopCount = 0;
    currentPattern = currentPattern +1; 
  }
}
