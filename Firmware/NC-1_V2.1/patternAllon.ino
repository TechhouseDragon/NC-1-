void patternAllon(){
 
 if(seed ==1){ 
  seed = 0;
  lastPattern = currentPattern;
 }
    for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){
if (col%2){      
      WriteBit(col, row, "patternArray", 1);
      //patternArray[col][row] = 1;
    }
    else{
      WriteBit(col, row, "patternArray", 1);    
    //patternArray[col][row] = 0;
    }
    }
  }
setOutputArray();  
}
