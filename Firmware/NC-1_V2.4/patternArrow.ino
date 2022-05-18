int MaxArrow;
int ArrowRow, ArrowCol, CurrentSize, ArrowStep;
void patternArrow(){

  if (lastPattern != currentPattern){
    seed = 1;
  }

  //seed the pattern - random drop
  
  if(mode2 <= 5){
    if (seed == 1){
      ArrowRow = int(random(numRows));
      ArrowStep = int(random(1,4));
      ArrowCol = int(random(2,numCols-2));    
      MaxArrow = mode + 3;
      CurrentSize = 0;
      seed = 0;
      lastPattern = currentPattern;
    }
    for(int i = 0; i < CurrentSize; i = i + 1){
          int SCol = ArrowCol+ 1 * i;
          int SRow = ArrowRow - 1 * i;
          if ( (SCol>=0) &&  (SCol< numCols) && (SRow>=0) && (SRow < numRows )){
              WriteBit(SCol, SRow, "patternArray", 1);
          }
    }
    for(int i = 0; i < CurrentSize; i = i + 1){
          int SCol = ArrowCol - 1 * i;
          int SRow = ArrowRow - 1 * i;
          if ( (SCol>=0) &&  (SCol< numCols) && (SRow>=0) && (SRow < numRows )){
              WriteBit(SCol, SRow, "patternArray", 1);
          }
    }   
    setOutputArray();  
    memset(patternArray,0,sizeof(patternArray));
    triggernow = 0;
    ArrowRow = ArrowRow + ArrowStep;
    CurrentSize = CurrentSize + ArrowStep;

    if(CurrentSize >= MaxArrow){
      seed = 1;
      CurrentSize = 0;
      currentPattern = currentPattern +1;
    }
  }
  else{
    if (seed == 1){
      ArrowRow = int(random(numRows));
      ArrowStep = int(random(1,4));
      ArrowCol = int(random(2,numCols-2));    
      MaxArrow = mode + 3;
      CurrentSize = MaxArrow;
      seed = 0;
      lastPattern = currentPattern;
    }
    for(int i = 0; i < CurrentSize; i = i + 1){
          int SCol = ArrowCol - 1 * i;
          int SRow = ArrowRow + 1 * i;
          if ( (SCol>=0) &&  (SCol< numCols) && (SRow>=0) && (SRow < numRows )){
              WriteBit(SCol, SRow, "patternArray", 1);
          }
    }
    for(int i = 0; i < CurrentSize; i = i + 1){
          int SCol = ArrowCol + 1 * i;
          int SRow = ArrowRow + 1 * i;
          if ( (SCol>=0) &&  (SCol< numCols) && (SRow>=0) && (SRow < numRows )){
              WriteBit(SCol, SRow, "patternArray", 1);
          }
    }   
    setOutputArray();  
    memset(patternArray,0,sizeof(patternArray));
    triggernow = 0;
    ArrowRow = ArrowRow - ArrowStep;
    CurrentSize = CurrentSize - ArrowStep;

    if(CurrentSize < 0){
      seed = 1;
      CurrentSize = MaxArrow;
      currentPattern = currentPattern +1;
    }
  }
}    