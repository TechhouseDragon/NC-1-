

void patternStrobe(){

  while (digitalRead(Strobe1Pin)==1){ 
     instrobe = 1;
     WriteLEDArray();
     setOutputArray();
     strobespeed = analogRead(SpeedPin);
     strobespeed = map(strobespeed,0,1023,0,500);
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
    else{
     

      flashElapsed = millis() - flashStart;

      if (flashElapsed > flashTime){
        memset(glowArray,0,sizeof(glowArray)); 

      }

      if (flashElapsed  > (flashTime + strobespeed)){
        seed = 1; 
      }  
    }
    
  }
}
