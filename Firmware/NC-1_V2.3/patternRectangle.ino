  int startcol, startrow;
  int Rectnum, maxRect, minRect;
  int maxcol, maxrow;
  float RectDiv;
void patternRectangle(){ 
  
  if (lastPattern != currentPattern){
    seed = 1;
  }

  //seed the pattern - random drop
  if(mode2 <= 5 ){
    if (seed == 1){
      memset(patternArray,0,sizeof(patternArray));
      Rectnum = 1;
      maxRect = random(2,mode*2); 
      minRect = 0;
      startcol = random(numCols -1);
      startrow = random(numRows -1);
      RectDiv = (float) random(1, 100)/50.0f;
      seed = 0;
      lastPattern = currentPattern;
    }else{ 
      maxcol = Rectnum;
      maxrow = maxcol *RectDiv;
      for(int i = startcol; i<= startcol + maxcol/2; i++){
        WriteBit(i, startrow - maxrow/2, "patternArray", 1);
        WriteBit(i, startrow + maxrow/2, "patternArray", 1);
      }
      for(int i = startcol - maxcol/2; i<= startcol; i++){
        WriteBit(i, startrow - maxrow/2, "patternArray", 1);
        WriteBit(i, startrow + maxrow/2, "patternArray", 1);
      }
      for(int i = startrow; i<= startrow + maxrow/2; i++){        
          WriteBit(startcol - maxcol/2 , i, "patternArray", 1);
          WriteBit(startcol + maxcol/2, i, "patternArray", 1);
      }
      for(int i = startrow - maxrow/2; i<= startrow; i++){        
          WriteBit(startcol - maxcol/2, i, "patternArray", 1);
          WriteBit(startcol + maxcol/2, i, "patternArray", 1);
      }

    }  

    setOutputArray();
    memset(patternArray,0,sizeof(patternArray));   
    triggernow = 0;
    
    if(Rectnum > maxRect){   
      seed = 1;
      Rectnum = 1;
      currentPattern = currentPattern +1; 
    }
    Rectnum = Rectnum + 1;
  }else if(mode2>5){

    if (seed == 1){
      memset(patternArray,0,sizeof(patternArray));      
      maxRect = random(2, mode*2); 
      Rectnum = maxRect;
      minRect = 1;
      startcol = random(numCols -1);
      startrow = random(numRows -1);
      RectDiv = (float) random(1, 100)/50.0f;
      seed = 0;
      lastPattern = currentPattern;
    }else{ 
      maxcol = Rectnum;
      maxrow = maxcol * RectDiv;
      for(int i = startcol; i<= startcol + maxcol/2; i++){
        WriteBit(i, startrow - maxrow/2, "patternArray", 1);
        WriteBit(i, startrow + maxrow/2, "patternArray", 1);
      }
      for(int i = startcol - maxcol/2; i<= startcol; i++){
        WriteBit(i, startrow - maxrow/2, "patternArray", 1);
        WriteBit(i, startrow + maxrow/2, "patternArray", 1);
      }
      for(int i = startrow; i<= startrow + maxrow/2; i++){        
          WriteBit(startcol - maxcol/2 , i, "patternArray", 1);
          WriteBit(startcol + maxcol/2, i, "patternArray", 1);
      }
      for(int i = startrow - maxrow/2; i<= startrow; i++){        
          WriteBit(startcol - maxcol/2, i, "patternArray", 1);
          WriteBit(startcol + maxcol/2, i, "patternArray", 1);
      }

    }  

    setOutputArray();
    memset(patternArray,0,sizeof(patternArray));   
    triggernow = 0;
    
    if(Rectnum <= minRect){   
      seed = 1;
      Rectnum = maxRect;
      currentPattern = currentPattern +1; 
    }
    Rectnum = Rectnum - 1;
  }
}    