const int numRowsDiamond2 = numRows*2;
const int numColsDiamond2 = numCols*2;


void patternDiamond(){
  int numLoops = 16;

  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }

  //seed the pattern - line across row 0
  if (seed == 1){
    memset(patternArray,0,sizeof(patternArray)); 
    frameloops = 0;     
    dir = random(8);
    colShift = 0;
    rowShift = 0;
    lastPattern = currentPattern;
    seed = 0;

  }



//DRAW A DIAMOND
    for (col = 0; col < numColsDiamond2; col = col + 1){
      WriteBit((col+colShift)%numColsDiamond2, ((col*numRows/(4 * (mode2 % 8 + 1)))+rowShift)%numRowsDiamond2, "patternArray", 1);
      WriteBit((col+colShift)%numColsDiamond2,  ((2*numRows - 1 - col*numRows/(4 * (mode2 % 8 + 1)))+rowShift)%numRowsDiamond2, "patternArray", 1); 
    }
 
  setOutputArray();
 
  triggernow = 0;
  frameloops = frameloops +1;
  
  //SHIFT THE PATTERN
    memset(patternArray,0,sizeof(patternArray)); 
    setshift2();
    if(colShift <0){
      colShift = colshift + numColsDiamond2;
    }
    if(rowShift<0){
      rowShift = rowShift+ numRowsDiamond2;
    }
    
  if (frameloops >= numRows){
    loopCount = loopCount +1; 
    frameloops = 0;
    dir = random(8);
    Serial.print("dir:   ");Serial.println(dir); 
  }

}
