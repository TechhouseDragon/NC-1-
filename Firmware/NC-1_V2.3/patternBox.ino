const int numRowsBox = numRows*1;
const int numColsBox = numCols*2;
int newRowBox2;
int newColBox2;

void patternBox(){
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
    lastPattern = currentPattern;
    seed = 0;
    colShift=0;
    rowShift=0;
  }

//Draw a box
    for (col = 0; col < numColsBox; col = col + (mode2 % 3) + 1){
      WriteBit((col+colShift)%numColsBox, (numRowsBox-1+rowShift)%numRowsBox, "patternArray", 1);
      //patternArray[col][numRowsBox-1] = 1;
    }
    for (row = 0; row < numRowsBox; row = row + (mode2 % 3) + 1){
      WriteBit((numColsBox-1+colShift)%numColsBox, (row+rowshift)%numRowsBox, "patternArray", 1);
      //patternArray[numColsBox-1][row] = 1;      
    }
  
  
  //SHIFT THE PATTERN
    setshift2();
    if(colShift <0){
      colShift = colshift + numColsBox;
    }
    if(rowShift<0){
      rowShift = rowShift+ numRowsBox;
    }
    
  setOutputArray();
  
  triggernow = 0;
  frameloops = frameloops +1;
  if (frameloops == numRowsBox/2){
    loopCount = loopCount +1; 
    frameloops = 0;
    dir = random(8);
  }
  if (loopCount > numLoops){
    loopCount = 0;
    seed=1;
   currentPattern = currentPattern +1;
  }
memset(patternArray,0,sizeof(patternArray)); 
}
