

void patternStrobe(){

  while (digitalRead(Strobe1Pin)==1){ 
    strobespeed = 1023 - analogRead(SpeedPin);
    //seed the pattern   
    if (seed == 1){

      glowArray[random(numCols)][random(numRows)] = 1;
      glowArray[random(numCols)][random(numRows)] = 1;
      glowArray[random(numCols)][random(numRows)] = 1;
      glowArray[random(numCols)][random(numRows)] = 1;
      glowArray[random(numCols)][random(numRows)] = 1;
      glowArray[random(numCols)][random(numRows)] = 1;

      flashStart = millis();
      seed = 0;
    }
    WriteLEDArray();

    flashElapsed = millis() - flashStart;

    if (flashElapsed > flashTime){
      memset(glowArray,0,sizeof(glowArray)); 

    }


    if (flashElapsed  > (flashTime + strobespeed)){
      seed = 1; 
    }  
  }
}
