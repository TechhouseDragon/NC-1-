
 int pixelnum;
 int zipstep;
 int oldmode;
 int* zipcolnum;
 int* ziprownum;

void patternZips(){
  int ziprow = 0;
  int zipcol = 0;
  int _ziprow=0; int  _zipcol = 0;  
  int _a, _b;
  int zipmax; 
  

 if (lastPattern != currentPattern){
    seed = 1;
  }
  if(seed == 1) {
    memset(patternArray,0,sizeof(patternArray));
    oldmode = mode2;
    zipcolnum = new int[10];
    ziprownum = new int[10];
    pixelnum = 0;
    zipstep = 0;
    seed = 0; 
    
    lastPattern = currentPattern;
  }
  else{ 

    switch(mode % 4){
          case 0:
            _a = random(numCols-1);  
            _b =  0;
            ziprow = 1;
            if(int(((mode - 1) /4)) == 0) zipcol = 0;
            else zipcol = 1;
            zipmax = 32;
          break;
          case 1:
            _a = random(numCols-1);  
            _b =  31;
            ziprow = -1;
            if(int(((mode - 1) /4)) == 0) zipcol = 0;
            else zipcol = 1;
            zipmax = 32;
          break;
          case 2:
            _a = 0;  
            _b =  random(numRows-1);
            if(int(((mode - 1) /4)) == 0) ziprow = 0;
            else ziprow = 1;
            zipcol = 1;
            zipmax = 8;
          break;
          case 3:
            _a = 7;  
            _b =  random(numRows-1);
            if(int(((mode - 1) /4)) == 0) ziprow = 0;
            else ziprow = 1;
            zipcol = -1;
            zipmax = 8;
          break;
     }  

    if(pixelnum < mode2){
      if(zipstep == 0 || zipstep == zipmax/mode2){        
        zipcolnum[pixelnum] = _a;     
        ziprownum[pixelnum] = _b;        
        WriteBit(_a, _b, "patternArray", 1);  
        pixelnum = pixelnum +1; 
        zipstep = 0;        
      }
      oldmode = mode2;
    } 

    setOutputArray();
      memset(patternArray,0,sizeof(patternArray)); 
      for(int i = 0; i< 10; i++){        
       //  WriteBit(zipcolnum[i], ziprownum[i], "patternArray", 0);
      }

       for(int i = 0; i< pixelnum; i++){       
          zipcolnum[i] =  zipcolnum[i] + zipcol;
          ziprownum[i] =  ziprownum[i] + ziprow; 
          if (ziprownum[i] >= numRows){
            ziprownum[i] = 0;
            zipcolnum[i] = random(numCols-1);
          } else if (ziprownum[i] < 0 ){
            ziprownum[i] = numRows-1;
            zipcolnum[i] = random(numCols-1);
          }
          if (zipcolnum[i] >= numCols){
            ziprownum[i] = random(numRows-1);
            zipcolnum[i] = 0;
          }else if (zipcolnum[i] < 0){
            ziprownum[i] = random(numRows-1);
            zipcolnum[i] =numCols-1;
          }
      }
      
      for(int i = 0; i< pixelnum; i++){        
          WriteBit(zipcolnum[i], ziprownum[i], "patternArray", 1);
      }
    zipstep++;
    if(pixelnum == mode2){      
      zipstep = 0;  
    } 
    if(oldmode > mode2){
        pixelnum= pixelnum-1;
    }
  }

  lastPattern = currentPattern;
  seed = 0;
  triggernow = 0;


}
