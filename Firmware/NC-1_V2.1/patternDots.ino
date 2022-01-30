

void patternDots(){


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

  //seed the pattern - random drop
  if (seed == 1){
    maxRadius = random(mode*2.5);
    dropCol=int(random(numCols));
    dropRow=int(random(numRows));
    rippleRadius = maxRadius-2;
    seed = 0;
    lastPattern = currentPattern;
    loopCount = loopCount +1;
    frameloops = 64;
  }



  for (angle = 0; angle<= 360; angle = angle+18){
    currentCol = rippleRadius * cos( angle * PI /180 );
    currentRow = rippleRadius * sin( angle * PI /180 );

    rippleCol = dropCol + currentCol;
    rippleRow = dropRow + currentRow;

    //  add ripple to the patternArray
    
      if ( (rippleCol>=0) &&  (rippleCol< numCols) && (rippleRow>=0) && (rippleRow < numRows )){
        WriteBit(rippleCol, rippleRow, "patternArray", 1);         
      //  patternArray[rippleCol][rippleRow] = 1;
      }
    
  }

  setOutputArray();                                //output the pattern array
  memset(patternArray,0,sizeof(patternArray));     // clear the current pattern array
  triggernow = 0;                                  //reset the trigger



  if (loopCount > numLoops){
    loopCount = 0;
    currentPattern = currentPattern +1;
  }


  if (rippleRadius >= maxRadius){
    seed = 1;
  } 
   rippleRadius = rippleRadius +1.0; 
}    
