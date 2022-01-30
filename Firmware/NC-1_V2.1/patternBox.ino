const int numRowsBox = numRows+8;
const int numColsBox = numCols+8;
int newRowBox;
int newColBox;

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
        dir = random(4,9);
   
    for (col = 0; col < numColsBox; col = col + 1){
      WriteBit(col, numRowsBox-1, "patternArray", 1);
      //patternArray[col][numRowsBox-1] = 1;
    }

    for (row = 0; row < numRowsBox; row = row + 1){
      WriteBit(numColsBox-1, row, "patternArray", 1);
      //patternArray[numColsBox-1][row] = 1;      
    }
  
  
    lastPattern = currentPattern;
    seed = 0;
  }
  //LAY THE FRAME ARRAY OVER THE LED ARRAY
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){
      WriteBit(col, row, "LEDArray", ReadBit(col, row, "patternArray"));       
   //   LEDArray[col][row] = patternArray[col][row];
    }
  }
  //SHIFT THE PATTERN
  setshift();
  for (row = 0; row < numRowsBox; row++){
    for (col = 0; col < numColsBox; col++){
      newRowBox = row + rowShift;
      newColBox = col + colShift;

      if (newRowBox >= numRowsBox){
        newRowBox = newRowBox - numRowsBox;
      }
      if (newColBox >= numColsBox){
        newColBox = newColBox - numColsBox;
      } 
      if (newRowBox < 0 ){
        newRowBox = newRowBox + numRowsBox;
      }     
      if (newColBox < 0){
        newColBox = newColBox + numColsBox;
      }  
     // nextpatternArray[newColBox][newRowBox] = patternArray[col][row] ;
     WriteBit(newColBox, newRowBox, "nextpatternArray", ReadBit(col, row, "patternArray"));       
    }
  }

  //update the LEDArray from the nextLEDArray
  for (row = 0; row < numRowsBox; row++){
    for (col = 0; col < numColsBox; col++){
      //patternArray[col][row] = nextpatternArray[col][row] ;
      WriteBit(col, row, "patternArray", ReadBit(col, row, "nextpatternArray"));      
    }
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
  if (frameloops == numRowsBox){
    loopCount = loopCount +1; 
    frameloops = 0;
    dir = random(4,9);
  }
  if (loopCount > numLoops){
    loopCount = 0;
    seed=1;
   currentPattern = currentPattern +1;

  }
}
