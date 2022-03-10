const int numRowsBox2 = numRows*1;
const int numColsBox2 = numCols*2;
int newRowBox2;
int newColBox2;

void patternBox2(){
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
    for (col = 0; col < numColsBox; col = col + 1){
      WriteBit((col+colShift)%numColsBox2, (numRowsBox-1+rowShift)%numRowsBox2, "patternArray", 1);
      //patternArray[col][numRowsBox-1] = 1;
    }
    for (row = 0; row < numRowsBox; row = row + 1){
      WriteBit((numColsBox-1+colShift)%numColsBox2, (row+rowshift)%numRowsBox2, "patternArray", 1);
      //patternArray[numColsBox-1][row] = 1;      
    }

  
  //LAY THE FRAME ARRAY OVER THE LED ARRAY
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){
      WriteBit(col, row, "LEDArray", ReadBit(col, row, "patternArray"));       
   //   LEDArray[col][row] = patternArray[col][row];
    }
  }
  //SHIFT THE PATTERN
    setshift2();
    if(colShift <0){
      colShift = colshift + numColsBox2;
    }
    if(rowShift<0){
      rowShift = rowShift+ numRowsBox2;
    }
    
  //update glowArray
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){      
      glowArray[col][row] = glowArray[col][row]*glow ;            
      //glowArray[col][row] = glowArray[col][row]+LEDArray[col][row];
      glowArray[col][row] = glowArray[col][row]+ ReadBit(col, row, "LEDArray");// bitRead(LEDArray[divi(col,  row, numCols)], modi(col, row, numCols));
      constrain(glowArray[col][row], 0, 1);
      //if (LEDArray[col][row] == 1 ){
      if (ReadBit(col, row, "LEDArray") == 1 ){
        colourArray[col][row] [r] = redintensity;
        colourArray[col][row] [g] = greenintensity;
        colourArray[col][row] [b] = blueintensity;
      }
    }
  }
  
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
