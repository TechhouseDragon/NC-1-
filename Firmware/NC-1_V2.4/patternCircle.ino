void patternCircle(){
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

  //seed the pattern - random drop
  if (seed == 1){
    frameloops = 32;

    maxRadius = mode;
    
    rippleRadius = 0 ;
    seed = 0;
    lastPattern = currentPattern;
    loopCount = loopCount +1;
    dir = random(4);
    if(dir == 0){
      dropCol=0;
      dropRow=int(random(numRows));
    }else if(dir == 1){
      dropCol=numCols-1;
      dropRow=int(random(numRows));
    }else if(dir == 2){
      dropCol=int(random(numCols));
      dropRow=0;
    }else if(dir == 3){
      dropCol=int(random(numCols));
      dropRow=numRows-1;
    }
  }
  

  for(int i = 0; i< mode2; i++){
    for (angle = 0; angle<= 360; angle = angle+ 5){
      currentCol = (rippleRadius + i*(maxRadius/mode2)) * cos( angle * PI /180 ); //scaled for the spots pattern
      currentRow = (rippleRadius + i*(maxRadius/mode2)) * sin( angle * PI /180 ); //scaled for the spots pattern

      rippleCol = dropCol + currentCol;
      rippleRow = dropRow + currentRow;
      if ( (rippleCol>=0) &&  (rippleCol< numCols) && (rippleRow>=0) && (rippleRow < numRows )){
          WriteBit(rippleCol, rippleRow, "patternArray", 1);
      }
    }
  }


setOutputArray();

  // clear the current pattern array
  memset(patternArray,0,sizeof(patternArray)); 
  triggernow = 0;
  rippleRadius = rippleRadius +1.0;

  if (rippleRadius >= maxRadius){  
    currentPattern = currentPattern +1;
    rippleRadius = 0;
    seed = 1;
  } 
  
}    