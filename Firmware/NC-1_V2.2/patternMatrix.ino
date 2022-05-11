int matcolnum[10];
int matrownum[10];
int matnumber, matstep;
void patternMatrix(){

  if (lastPattern != currentPattern){
    seed = 1;
  }
  if(mode2 <= 5) {
    if(seed == 1){
      seed = 0;
      memset(patternArray,0,sizeof(patternArray));
      memset(patternArray,0,sizeof(matcolnum));
      memset(patternArray,0,sizeof(matrownum));
      lastPattern = currentPattern;
      matnumber = random(1, mode);     
      matstep = 0;
      for(int i = 0; i< matnumber; i++){
        matcolnum[i] = random(0, numCols - 1);
        matrownum[i] = random(0, numRows - 1);
      }
    }
      for(int i = 0; i< matnumber; i++){
        int MCol = matcolnum[i] + matstep;
        int MRow = matrownum[i];
        if ( (MCol>=0) &&  (MCol< numCols) && (MRow>=0) && (MRow < numRows )){
          if(ReadBit(MCol, MRow , "patternArray") != 1)  WriteBit(MCol, MRow, "patternArray", 1);        
        }
         MCol = matcolnum[i] - matstep;
         MRow = matrownum[i];
        if ( (MCol>=0) &&  (MCol< numCols) && (MRow>=0) && (MRow < numRows )){
          if(ReadBit(MCol, MRow , "patternArray") != 1)  WriteBit(MCol, MRow, "patternArray", 1);
        }
         MCol = matcolnum[i];
         MRow = matrownum[i] + matstep;
        if ( (MCol>=0) &&  (MCol< numCols) && (MRow>=0) && (MRow < numRows )){
          if(ReadBit(MCol, MRow , "patternArray") != 1)  WriteBit(MCol, MRow, "patternArray", 1);
        }
         MCol = matcolnum[i];
         MRow = matrownum[i] - matstep;
        if ( (MCol>=0) &&  (MCol< numCols) && (MRow>=0) && (MRow < numRows )){
          if(ReadBit(MCol, MRow , "patternArray") != 1)  WriteBit(MCol, MRow, "patternArray", 1);
        }
      }
    setOutputArray();
    matstep = matstep + 1;
    if(matstep >= random(1, 8)){
      seed = 1; 
      matstep = 0;
      currentPattern = currentPattern +1;
    }
  } else{
    if(seed == 1){
      seed = 0;
      memset(patternArray,0,sizeof(patternArray));      
      memset(patternArray,0,sizeof(matcolnum));
      memset(patternArray,0,sizeof(matrownum));   
      lastPattern = currentPattern;
      matnumber = random(1, mode);   
      matstep = random(1, 8);
      for(int i = 0; i< matnumber; i++){
        matcolnum[i] = random(0, numCols - 1);
        matrownum[i] = random(0, numRows - 1);
      }
    }
      for(int i = 0; i< matnumber; i++){
        int MCol = matcolnum[i] + matstep;
        int MRow = matrownum[i];
        if ( (MCol>=0) &&  (MCol< numCols) && (MRow>=0) && (MRow < numRows )){
          if(ReadBit(MCol, MRow , "patternArray") != 1)  WriteBit(MCol, MRow, "patternArray", 1);        
        }
         MCol = matcolnum[i] - matstep;
         MRow = matrownum[i];
        if ( (MCol>=0) &&  (MCol< numCols) && (MRow>=0) && (MRow < numRows )){
          if(ReadBit(MCol, MRow , "patternArray") != 1)  WriteBit(MCol, MRow, "patternArray", 1);
        }
         MCol = matcolnum[i];
         MRow = matrownum[i] + matstep;
        if ( (MCol>=0) &&  (MCol< numCols) && (MRow>=0) && (MRow < numRows )){
          if(ReadBit(MCol, MRow , "patternArray") != 1)  WriteBit(MCol, MRow, "patternArray", 1);
        }
         MCol = matcolnum[i];
         MRow = matrownum[i] - matstep;
        if ( (MCol>=0) &&  (MCol< numCols) && (MRow>=0) && (MRow < numRows )){
          if(ReadBit(MCol, MRow , "patternArray") != 1)  WriteBit(MCol, MRow, "patternArray", 1);
        }
      }
    setOutputArray();
    matstep = matstep - 1;
    if(matstep <= 0){
      seed = 1; 
      matstep = random(1, 8);
      currentPattern = currentPattern +1;
    }
  }
  
}    