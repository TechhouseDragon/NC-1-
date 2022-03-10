const int numRowsDiamond2 = numRows*2;
const int numColsDiamond2 = numCols*2;


void patternDiamond2(){
  int numLoops = 16;

  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }
//  //seed the pattern - line across row 0
//  if (seed == 1){
//    memset(patternArray,0,sizeof(patternArray)); 
//    frameloops = 0;
//    dir = random(4);   
//    for (col = 0; col < numColsDiamond; col = col + 1){
//      WriteBit(col, col*numRows/numCols, "patternArray", 1);      
//      //patternArray[col][col*numRows/numCols] = 1;
//      WriteBit(col,  2*numRows - 1 - col*numRows/numCols, "patternArray", 1);      
//      //patternArray[col][2*numRows - 1 - col*numRows/numCols] = 1;
//    }

  //seed the pattern - line across row 0
  if (seed == 1){
    memset(patternArray,0,sizeof(patternArray)); 
    frameloops = 0;
    //dir = random(8);   
    dir = random(8);
//    dir = dir*2+1;
    colShift = 0;
    rowShift = 0;
    lastPattern = currentPattern;
    seed = 0;
    

  }



//DRAW A DIAMOND
    for (col = 0; col < numColsDiamond2; col = col + 1){
      WriteBit((col+colShift)%numColsDiamond2, ((col*numRows/numCols)+rowShift)%numRowsDiamond2, "patternArray", 1);      
      //patternArray[col][col*numRows/numCols] = 1;
      WriteBit((col+colShift)%numColsDiamond2,  ((2*numRows - 1 - col*numRows/numCols)+rowShift)%numRowsDiamond2, "patternArray", 1);      
      //patternArray[col][2*numRows - 1 - col*numRows/numCols] = 1;
    }
 
  //LAY THE FRAME ARRAY OVER THE LED ARRAY
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){
      WriteBit(col, row, "LEDArray", ReadBit(col, row, "patternArray"));        
    }
  }

  //update glowArray
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){      
      glowArray[col][row] = glowArray[col][row]*glow ;      
      glowArray[col][row] = glowArray[col][row]+ ReadBit(col, row, "LEDArray"); 
      constrain(glowArray[col][row], 0, 1);
      if (ReadBit(col, row, "LEDArray") == 1 ){
        colourArray[col][row] [r] = redintensity;
        colourArray[col][row] [g] = greenintensity;
        colourArray[col][row] [b] = blueintensity;
      }
    }
  }
 
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
