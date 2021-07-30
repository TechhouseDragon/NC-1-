

void patternRain(){
  maxRadius =random(numCols*2);
  int a;
  float angle;
  int rippleCol;
  int rippleRow;
  int currentCol;
  int currentRow;
  int numLoops = 32;
  const int numRows1 = numRows;
  const int numCols1 = numCols;

  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }

  //seed the pattern - line across row 0
  if (seed == 1){
    dropCol=random(numCols);
    dropRow=random(numRows);
    rippleRadius = 0;
    seed = 0;
    lastPattern = currentPattern;
    loopCount = loopCount +1;
  }

  rippleRadius = rippleRadius +1.0;

  for (angle = 0; angle<= 360; angle = angle+12){
    currentCol = rippleRadius * cos( angle * PI /180 );
    currentRow = rippleRadius * sin( angle * PI /180 );

    rippleCol = dropCol + currentCol;
    rippleRow = dropRow + currentRow;

    //  add ripple to the patternArray
    if ( (rippleCol>=0) &&  (rippleCol< numCols) && (rippleRow>=0) && (rippleRow < numRows )){
      bitWrite(patternArray[divi(rippleCol, rippleRow,patternCols )], modi(rippleCol,  rippleRow, patternCols), 1);
    //  patternArray[rippleCol][rippleRow] = 1;
    }
  }




  //LAY THE PATTERN ARRAY OVER THE LED ARRAY
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
      }
    }
  }

  // clear the current pattern array
  memset(patternArray,0,sizeof(patternArray)); 
  triggernow = 0;


  if (rippleRadius >= maxRadius){
    seed = 1;
  }
  if (loopCount > numLoops){
    loopCount = 0;
    currentPattern = currentPattern +1;
    seed = 1;
  }


}    
