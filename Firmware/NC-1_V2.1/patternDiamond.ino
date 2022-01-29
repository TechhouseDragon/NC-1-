const int numRowsDiamond = numRows*2;
const int numColsDiamond = numCols*2;
int newRowDiamond;
int newColDiamond;

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
        dir = random(4);
   
    for (col = 0; col < numColsDiamond; col = col + 1){
      bitWrite(patternArray[divi(col,  col*numRows/numCols,patternCols)], modi(col,  col*numRows/numCols ,patternCols), 1);
      //patternArray[col][col*numRows/numCols] = 1;
      bitWrite(patternArray[divi(col,  2*numRows - 1 - col*numRows/numCols, patternCols)], modi(col,  2*numRows - 1 - col*numRows/numCols, patternCols), 1);
      //patternArray[col][2*numRows - 1 - col*numRows/numCols] = 1;
    }
  
    lastPattern = currentPattern;
    seed = 0;
  }
  //LAY THE FRAME ARRAY OVER THE LED ARRAY
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){
        bitWrite(LEDArray[divi(col,  row, numCols)], modi(col, row, numCols), bitRead(patternArray[divi(col,  row, patternCols)],modi(col, row, patternCols)));
    //  LEDArray[col][row] = patternArray[col][row];
    }
  }
  //SHIFT THE PATTERN
  

  setshift();
  for (row = 0; row < numRowsDiamond; row++){
    for (col = 0; col < numColsDiamond; col++){
      newRowDiamond = row + rowShift;
      newColDiamond = col + colShift;

      if (newRowDiamond >= numRowsDiamond){
        newRowDiamond = newRowDiamond - numRowsDiamond;
      }
      if (newColDiamond >= numColsDiamond){
        newColDiamond = newColDiamond - numColsDiamond;
      } 
      if (newRowDiamond < 0 ){
        newRowDiamond = newRowDiamond + numRowsDiamond;
      }     
      if (newColDiamond < 0){
        newColDiamond = newColDiamond + numColsDiamond;
      }  
        bitWrite(nextpatternArray[divi(newColDiamond,  newRowDiamond, patternCols)], modi(newColDiamond, newRowDiamond, patternCols), bitRead(patternArray[divi(col,  row, patternCols)], modi(col, row, patternCols)));
      //nextpatternArray[newColDiamond][newRowDiamond] = patternArray[col][row] ;
    }
  }
 //     }  
  //update the LEDArray from the nextLEDArray
  for (row = 0; row < numRowsDiamond; row++){
    for (col = 0; col < numColsDiamond; col++){
      bitWrite(patternArray[divi(col,  row, patternCols)], modi(col, row, patternCols), bitRead(nextpatternArray[divi(col,  row, patternCols)], modi(col, row, patternCols)));
     // patternArray[col][row] = nextpatternArray[col][row] ;
    }
  }

  //update glowArray
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){      
      glowArray[col][row] = glowArray[col][row]*glow ;      
         glowArray[col][row] = glowArray[col][row]+bitRead(LEDArray[divi(col,  row, numCols)], modi(col, row, numCols));      
   //   glowArray[col][row] = glowArray[col][row]+LEDArray[col][row];
      constrain(glowArray[col][row], 0, 1);
      if (bitRead(LEDArray[divi(col,  row, numCols)],  modi(col, row, numCols)) == 1 ){
        colourArray[col][row] [r] = redintensity;
        colourArray[col][row] [g] = greenintensity;
        colourArray[col][row] [b] = blueintensity;
      }
    }
  }
 
  triggernow = 0;
  frameloops = frameloops +1;
  if (frameloops == numRowsDiamond){
    loopCount = loopCount +1; 
    frameloops = 0;
    dir = random(4);
  }
  if (loopCount > numLoops){
    loopCount = 0;
    currentPattern = currentPattern +1;

  }
}
