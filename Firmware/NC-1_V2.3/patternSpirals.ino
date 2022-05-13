
int SpiralRow, SpiralCol;
float CircleNumber;
void patternSpirals(){

  if (lastPattern != currentPattern){
    seed = 1;
  }
  if(mode2 <= 5){
    if(seed == 1){
      seed = 0;
      memset(patternArray,0,sizeof(patternArray));
      lastPattern = currentPattern;
      CurrentSize = mode % 4 + 1;
      SpiralCol = int(random(1,numCols - 1));
      SpiralRow = int(random(2,numRows)); 
      
      CircleNumber = 1;    
    }
        int SCol = SpiralCol+ (CircleNumber/3) * cos(CircleNumber);
        int SRow = SpiralRow + (CircleNumber/3) * sin(CircleNumber);
        if ( (SCol>=0) &&  (SCol< numCols) && (SRow>=0) && (SRow < numRows )){
          WriteBit(SCol, SRow, "patternArray", 1);           
        }
        setOutputArray();       
        memset(patternArray,0,sizeof(patternArray));   
    if(CircleNumber < 10){
      CircleNumber= CircleNumber+0.5;  
    }else{
      CircleNumber= CircleNumber+0.2;
    }
    triggernow = 0;
    if(CircleNumber >= CurrentSize * 10){
      seed = 1;
      CircleNumber = 1;
      currentPattern = currentPattern +1;
    } 
  }else{
    if(seed == 1){
      seed = 0;
      memset(patternArray,0,sizeof(patternArray));
      lastPattern = currentPattern;
      CurrentSize = mode % 4 + 1;
      SpiralCol = int(random(1,numCols - 1));
      SpiralRow = int(random(2,numRows)); 
      
      CircleNumber =  CurrentSize * 10;    
    }
        int SCol = SpiralCol+ (CircleNumber/3) * cos(CircleNumber);
        int SRow = SpiralRow + (CircleNumber/3) * sin(CircleNumber);
       if ( (SCol>=0) &&  (SCol< numCols) && (SRow>=0) && (SRow < numRows )){
          WriteBit(SCol, SRow, "patternArray", 1);
        } 
        setOutputArray();       
        memset(patternArray,0,sizeof(patternArray));  
    if(CircleNumber < 10){
      CircleNumber= CircleNumber-0.5;  
    }else{
      CircleNumber= CircleNumber-0.2;
    }
   triggernow = 0;
    if(CircleNumber <= 0){
      seed = 1;
      CircleNumber =  CurrentSize * 10;
      currentPattern = currentPattern +1;
    }
  }
}    