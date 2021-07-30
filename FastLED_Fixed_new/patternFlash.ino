int flashes = 20; //flashes once per this many triggers
int flashTime = 5; //length of the flash

void patternFlash(){
  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
     seed = 1;
  }

 if(seed ==1){ 
  flashStart = millis();
  seed = 0;
  lastPattern = currentPattern;
  flashCount = 1;
  loopCount = 0;
  glow =0.5;
 }
 
if(flashCount == 1){
    for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){   
      bitWrite(patternArray[divi(col,  row,patternCols )], modi(col, row, patternCols), 1);            
      //patternArray[col][row] = 1;
    }
  }

setOutputArray();
  WriteLEDArray();
  while (flashElapsed < flashTime){
    flashElapsed = millis() - flashStart;    
  }  
}

  memset(patternArray,0,sizeof(patternArray)); 

  setOutputArray();

  flashCount = flashCount +1;
    if(flashCount == flashes){
    loopCount = loopCount +1;
    flashCount = 0;
  }
  triggernow = 0;
}
