int flashes = 4; //flashes once per this many triggers

int numLoops = 8; //number of flashes before moving on to the next loop



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
 
 }
 
if(flashCount == 1){
    for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){   
      WriteBit(col, row, "LEDArray", 1);
      //LEDArray[col][row] = 1;
    }
  }

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

 // WriteLEDArray();
 while (flashElapsed < flashTime){
    flashElapsed = millis() - flashStart;    
  }  

}
  memset(LEDArray,0,sizeof(LEDArray)); 

   for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){      
      glowArray[col][row] = glowArray[col][row]*glow ;            
      glowArray[col][row] = glowArray[col][row]+ReadBit(col, row, "LEDArray");
      if (ReadBit(col, row, "glowArray") > 1){
        glowArray[col][row] = 1;
      }
    }
  }

  if(loopCount > numLoops){
    seed = 1;
    currentPattern = currentPattern +1;
  }
  flashCount = flashCount +1;
    if(flashCount == flashes){
    loopCount = loopCount +1;
    flashCount = 0;
  }
  triggernow = 0;
}

