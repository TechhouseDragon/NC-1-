int cloudcol ;  
int cloudrow ;
void patternClouds2(){
  if (lastPattern != currentPattern){
    seed = 1;
  }
  //check if this is the first time through the pattern
  if (seed == 1){ 
    memset(patternArray,0,sizeof(patternArray)); 
    frameloops = 0; 
    colShift = 0;
    rowShift = 0;
    dir=random(8);    
    setshift2();    
    lastPattern = currentPattern;       
    for (i =0 ; i<mode;i++){
      int _a = random(numCols);
      int _b = random(numRows);
      WriteBit(_a, _b, "patternArray", 1);         
    }
  }else{
    if(rowShift<0 && colShift < 0 ){
      for (int prow = 0; prow < numRows; prow++){
        for (int pcol = 0; pcol <numCols; pcol++){
          if(ReadBit(pcol, prow, "patternArray") == 1){        
          cloudrow = prow + rowShift;
          cloudcol = pcol + colShift;
          if (cloudrow >= numRows){
            cloudrow = 0;
          } else if (cloudrow < 1 ){
          cloudrow = numRows-1;
          }
          if (cloudcol >= numCols){
            cloudcol = 0;
          }else if (cloudcol < 0){
          cloudcol =numCols-1;
          }    
          WriteBit(cloudcol, cloudrow, "patternArray", 1);  
          WriteBit(pcol, prow, "patternArray", 0);      
          }
        }
      }
    } else if(rowShift>=0 && colShift < 0  ){
      for (int prow = numRows-1; prow >= 0; prow--){
        for (int pcol = 0; pcol <numCols; pcol++){
          if(ReadBit(pcol, prow, "patternArray") == 1){        
          cloudrow = prow + rowShift;
          cloudcol = pcol + colShift;
          if (cloudrow >= numRows){
            cloudrow = 0;
          } else if (cloudrow < 1 ){
          cloudrow = numRows-1;
          }
          if (cloudcol >= numCols){
            cloudcol = 0;
          }else if (cloudcol < 0){
          cloudcol =numCols-1;
          }
          WriteBit(cloudcol, cloudrow, "patternArray", 1);  
          WriteBit(pcol, prow, "patternArray", 0);      
          }
        }
      }
    } else if(rowShift<0 && colShift >= 0  ){
       for (int prow = 0; prow < numRows; prow++){
        for (int pcol = numCols-1; pcol >=0; pcol--){
          if(ReadBit(pcol, prow, "patternArray") == 1){        
          cloudrow = prow + rowShift;
          cloudcol = pcol + colShift;
          if (cloudrow >= numRows){
            cloudrow = 0;
          } else if (cloudrow < 1 ){
          cloudrow = numRows-1;
          }
          if (cloudcol >= numCols){
            cloudcol = 0;
          }else if (cloudcol < 0){
          cloudcol =numCols-1;
          }
          WriteBit(cloudcol, cloudrow, "patternArray", 1);  
          WriteBit(pcol, prow, "patternArray", 0);      
          }
        }
      }
    }else if(rowShift>=0 && colShift >=0  ){
      for (int prow = numRows-1; prow >= 0; prow--){
        for (int pcol = numCols-1; pcol >=0; pcol--){
          if(ReadBit(pcol, prow, "patternArray") == 1){        
          cloudrow = prow + rowShift;
          cloudcol = pcol + colShift;
          if (cloudrow >= numRows){
            cloudrow = 0;
          } else if (cloudrow < 1 ){
          cloudrow = numRows-1;
          }
          if (cloudcol >= numCols){
            cloudcol = 0;
          }else if (cloudcol < 0){
          cloudcol =numCols-1;
          }
          WriteBit(cloudcol, cloudrow, "patternArray", 1);  
          WriteBit(pcol, prow, "patternArray", 0);      
          }
        }
      }
    }
     
  }
  seed = 0;
  setOutputArray();  
  frameloops = frameloops +1;
  triggernow = 0;
  if (frameloops >= mode2){
    seed = 1;
    currentPattern = currentPattern +1;  
  }
}
