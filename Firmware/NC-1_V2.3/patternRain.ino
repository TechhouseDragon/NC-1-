

void patternRain(){
  maxRadius =random(mode*2);
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
      WriteBit(rippleCol, rippleRow,"patternArray", 1);
    //  patternArray[rippleCol][rippleRow] = 1;
    }
  }




   setOutputArray();
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
