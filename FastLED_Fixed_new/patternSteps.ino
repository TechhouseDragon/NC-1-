void patternSteps(){
  int numLoops = 4;
  int _mode = random(numCols);
  //check if this is the first time through the pattern  
  if (lastPattern != currentPattern){
    seed = 1;
  }

  //seed the pattern - line across row 0
  if (seed == 1){
    memset(patternArray,0,sizeof(patternArray)); 
    frameloops = 0;
    frameStep = 0;
    pixelStep = 1;
    lastPattern = currentPattern;
    seed = 0;
  }


  //Draw a 4pixel spot
  currentCol = frameStep;
  if (pixelStep == 1){
    currentRow = random(numRows);
  }

  if (pixelStep <= _mode){
     bitWrite(patternArray[divi(currentCol,  currentRow,patternCols )], modi(currentCol,  currentRow, patternCols), 1);
   // patternArray[currentCol][currentRow]=1;
    if (currentRow < numRows/2){
      bitWrite(patternArray[divi(currentCol,  currentRow+1,patternCols )], modi(currentCol,  currentRow+1, patternCols), 1);
   //   patternArray[currentCol][currentRow+1]=1;
    }

    if (currentRow > numRows/2){
      bitWrite(patternArray[divi(currentCol,  currentRow-1,patternCols )], modi(currentCol,  currentRow-1, patternCols), 1);
      //patternArray[currentCol][currentRow-1]=1;
    }
  }

if(pixelStep == _mode){
  //LAY THE FRAME ARRAY OVER THE LED ARRAY
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){
          bitWrite(LEDArray[divi(col,  row, numCols)], modi(col, row, numCols), bitRead(patternArray[divi(col,  row, patternCols)],modi(col, row, patternCols)));
          //LEDArray[col][row] = patternArray[col][row];    
    }
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

  triggernow = 0;
  frameStep = frameStep + 1;
  pixelStep = pixelStep + 1;

  if (pixelStep > _mode){
    memset(patternArray,0,sizeof(patternArray));
    memset(LEDArray,0,sizeof(LEDArray));
    pixelStep = 1;
  }

  if (frameStep > numCols){
    loopCount = loopCount +1; 
    frameStep = 0;
  }
  if (loopCount > numLoops){
    loopCount = 0;
    currentPattern = currentPattern +1;
  }

}
