void patternStarburst(){
  int a;
  float angle;
  int rippleCol;
  int rippleRow;
  int currentCol;
  int currentRow;
  int numLoops = 32;
  int dir = 0;
  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }

  if(mode2 <= 5 ){
    //seed the pattern - random drop
    if (seed == 1){
      frameloops = 32;

      maxRadius = mode;
      
      rippleRadius = 0 ;
      seed = 0;
      lastPattern = currentPattern;
      loopCount = loopCount +1;
      dropRow=int(random(1,numRows));
      dropCol=int(random(1,numCols));    
    }
    
      for (angle = 0; angle<= 360; angle = angle+ 45){
        currentCol = rippleRadius * cos( angle * PI /180 ); //scaled for the spots pattern
        currentRow = rippleRadius* sin( angle * PI /180 ); //scaled for the spots pattern
        rippleCol = dropCol + currentCol;
        rippleRow = dropRow + currentRow;
        if ( (rippleCol>=0) &&  (rippleCol< numCols) && (rippleRow>=0) && (rippleRow < numRows )){
            WriteBit(rippleCol, rippleRow, "patternArray", 1);
        }
      }

    setOutputArray();

    // clear the current pattern array
    triggernow = 0;
    rippleRadius = rippleRadius +1.0;

    if (rippleRadius >= maxRadius){  
      memset(patternArray,0,sizeof(patternArray)); 
      currentPattern = currentPattern +1;
      rippleRadius = 0;
      seed = 1;
    } 
  }else{
    if (seed == 1){
      frameloops = 32;

      maxRadius = mode;
      
      rippleRadius = maxRadius;
      seed = 0;
      lastPattern = currentPattern;
      loopCount = loopCount +1;
      dropRow=int(random(1,numRows));
      dropCol=int(random(1,numCols));    
    }
    
      for (angle = 0; angle<= 360; angle = angle+ 45){
        currentCol = rippleRadius * cos( angle * PI /180 ); //scaled for the spots pattern
        currentRow = rippleRadius* sin( angle * PI /180 ); //scaled for the spots pattern
        rippleCol = dropCol + currentCol;
        rippleRow = dropRow + currentRow;
        if ( (rippleCol>=0) &&  (rippleCol< numCols) && (rippleRow>=0) && (rippleRow < numRows )){
            WriteBit(rippleCol, rippleRow, "patternArray", 1);
        }
      }

    setOutputArray();

    // clear the current pattern array
    triggernow = 0;
    rippleRadius = rippleRadius  - 1.0;

    if (rippleRadius < 0){  
      memset(patternArray,0,sizeof(patternArray)); 
      currentPattern = currentPattern +1;
      rippleRadius = maxRadius;
      seed = 1;
    } 
  }
  
}    