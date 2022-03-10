const int numRowsClouds = numRows*2;
const int numColsClouds = numCols*2;
int newRowClouds;
int newColClouds;


void patternClouds(){
  if (lastPattern != currentPattern){
    seed = 1;
  }
  int numLoops = 3;


  //check if this is the first time through the pattern
  if (seed == 1){
        frameloops = 64;
    memset(patternArray,0,sizeof(patternArray)); 
    frameloops = 0;
        mode=2;
  for (i =0 ; i<2*mode;i++){
    int _a = random(numColsClouds);
    int _b = random(numRowsClouds);
    WriteBit(_a, _b, "patternArray", 1);
    //  bitWrite(patternArray[divi(_a,_b,patternCols )], modi(_a,_b, patternCols), 1);
  }
    lastPattern = currentPattern;
    dir=random(1,9);
    seed = 0;
  }
  

  //SHIFT THE PATTERN
  setshift();
  for (row = 0; row < numRowsClouds; row++){
    for (col = 0; col < numColsClouds; col++){
      newRowClouds = row + rowShift;
      newColClouds = col + colShift;
      if (newRowClouds >= numRowsClouds){
        newRowClouds = newRowClouds - numRowsClouds;
      }
      if (newColClouds >= numColsClouds){
        newColClouds = newColClouds - numColsClouds;
      } 
      if (newRowClouds < 0 ){
        newRowClouds = newRowClouds + numRowsClouds;
      }     
      if (newColClouds < 0){
        newColClouds = newColClouds + numColsClouds;
      }  
      WriteBit(newColClouds, newRowClouds, "nextpatternArray", ReadBit(col, row, "patternArray"));       
      //nextpatternArray[newColClouds][newRowClouds] = patternArray[col][row] ;
    }
  }

  //update the patternArray from the nextpatternArray
  for (row = 0; row < numRowsClouds; row++){
    for (col = 0; col < numColsClouds; col++){
      WriteBit(col, row, "patternArray", ReadBit(col, row, "nextpatternArray"));         
      //patternArray[col][row] = nextpatternArray[col][row] ;
    }
  }

setOutputArray();
  if(lastmode != mode){
    seed = 1;
    lastmode = mode;
  }
  
  triggernow = 0;
  frameloops = frameloops +1;
  
  if (frameloops == numRowsClouds){
    loopCount = loopCount +1; 
    frameloops = 0;
    dir = random(1,9);
  }
  if (loopCount > numLoops){
    loopCount = 0;
    currentPattern = currentPattern +1;
  }
}
