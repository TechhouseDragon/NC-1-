void patternSpots2(){

  int a;
  float angle;
  int rippleCol;
  int rippleRow;
  int currentCol;
  int currentRow;
  int numLoops = 32;
  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }

  //seed the pattern - random drop
  if (seed == 1){
    frameloops = 32;

    maxRadius = (mode-1);
    dropCol=int(random(numCols));
    dropRow=int(random(numRows));
    rippleRadius = (mode-1) ;
    seed = 0;
    lastPattern = currentPattern;
    loopCount = loopCount +1;
  }



  for (angle = 0; angle<= 360; angle = angle+15){
    currentCol = rippleRadius * cos( angle * PI /180 ); //scaled for the spots pattern
    currentRow = rippleRadius * sin( angle * PI /180 ); //scaled for the spots pattern

    rippleCol = dropCol + currentCol;
    rippleRow = dropRow + currentRow;

    //  add ripple to the patternArray
    if(loopCount %2){
          if ( (rippleCol>=0) &&  (rippleCol< numCols) && (rippleRow>=0) && (rippleRow < numRows )){
             bitWrite(patternArray[divi(rippleCol,  rippleRow, patternCols )], modi(rippleCol,  rippleRow, patternCols), 1);
          //  patternArray[rippleCol][rippleRow] = 1;
          }
    }
  }



setOutputArray();

  // clear the current pattern array
  memset(patternArray,0,sizeof(patternArray)); 
  triggernow = 0;



  if (loopCount > numLoops){
    loopCount = 0;
    currentPattern = currentPattern +1;
  }


  if (rippleRadius >= maxRadius){
    seed = 1;
  } 
   rippleRadius = rippleRadius +1; 
}    
