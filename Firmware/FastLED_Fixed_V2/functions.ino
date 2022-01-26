int rowShift;
int colShift;
//SET OUTPUT Array
void setOutputArray(){
    //LAY THE FRAME ARRAY OVER THE LED ARRAY
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){
      bitWrite(LEDArray[divi(col,  row, numCols)], modi(col, row, numCols), bitRead(patternArray[divi(col,  row, patternCols)], modi(col, row, numCols)));
   //   LEDArray[col][row] = patternArray[col][row];
    }
  }
  //UPDATE THE GLOW ARRAY
  for (row = 0; row <numRows; row++){
    for (col = 0; col < numCols; col++){      
      glowArray [col][row]= glowArray[col][row]*glow ;            
     // glowArray [col][row] = glowArray[col][row]+LEDArray[col][row];
      glowArray [col][row] = glowArray[col][row]+bitRead(LEDArray[divi(col,  row ,numCols)], modi(col, row, numCols));
      if (bitRead(LEDArray[divi(col,  row, numCols)],  modi(col, row, numCols)) == 1 ){
        colourArray[col][row] [r] = redintensity;
        colourArray[col][row] [g] = greenintensity;
        colourArray[col][row] [b] = blueintensity;
      }
    }
  }
}
void setshift(){

  //East  
  if (dir == 1){  
    colShift = 1;
    rowShift = 0;
  }
  //North  
  if (dir == 2){
    colShift = 0;
    rowShift = 1;
  }
  //West  
  if (dir == 3){
    colShift = -1;
    rowShift = 0;
  }
  //South  
  if (dir == 4){
    colShift = 0;
    rowShift = -1;
  }
  //NE
  if (dir == 5){
    colShift = 1;
    rowShift = 1;
  }
  //NW
  if (dir == 6){
    colShift = -1;
    rowShift = 1;
  }
  //SW
  if (dir == 7){
    colShift = -1;
    rowShift = -1;
  }
  //SE
  if (dir == 8){
    colShift = 1;
    rowShift = -1;
  }  
}

int trigger(){

  //READ AND AVERAGE SPEED KNOB INPUT
  speedinput = analogRead(BPMPin);
   speedinput = map(speedinput, 0, 1023, 1023, 0);
  // subtract the last reading:
  Stotal= Stotal - Sreadings[Sindex];         
  // read from the sensor:  
  Sreadings[Sindex] = speedinput; 
  // add the reading to the total:
  Stotal= Stotal + Sreadings[Sindex];       
  // advance to the next position in the array:  
  Sindex = Sindex + 1;                    
  // if we're at the end of the array...
  if (Sindex >= numReadings)              
    // ...wrap around to the beginning: 
    Sindex = 0; 
  // calculate the average:
  Saverage = Stotal / numReadings;
  loopspeed = 200/(Saverage/1023);
  if (digitalRead(Speed1)==1 && (digitalRead(Speed2)==0) && (digitalRead(Speed3)==0)){
    loopspeed = loopspeed * 4;
  }
  if (digitalRead(Speed1)==1 && (digitalRead(Speed2)==1) && (digitalRead(Speed3)==0)){
    loopspeed = loopspeed * 2;
  }
  if (digitalRead(Speed1)==0 && (digitalRead(Speed2)==1) && (digitalRead(Speed3)==1)){
    loopspeed = loopspeed / 2;
  }
  if (digitalRead(Speed1)==0 && (digitalRead(Speed2)==0) && (digitalRead(Speed3)==1)){
    loopspeed = loopspeed / 4;
  }
  //Serial.print("loopspeed:    ");
  //Serial.print(loopspeed);

  telapsed = millis()-lastTrigger;
  if (telapsed >= loopspeed) {
    triggernow = 1;
    lastTrigger = millis();
  }
  return triggernow;
} 

//GLOW ENGINE
void setglow(){

  //READ AND AVERAGE COLOR GLOW INPUT
  glowinput = analogRead(GlowPin);
  glowinput = map(glowinput, 0, 1023, 1023, 0);
  // subtract the last reading:
  Gtotal= Gtotal - Greadings[Gindex];         
  // read from the sensor:  
  Greadings[Gindex] = glowinput; 
  // add the reading to the total:
  Gtotal= Gtotal + Greadings[Gindex];       
  // advance to the next position in the array:  
  Gindex = Gindex + 1;                    
  // if we're at the end of the array...
  if (Gindex >= numReadings)              
    // ...wrap around to the beginning: 
    Gindex = 0; 
  // calculate the average:
  Gaverage = Gtotal / numReadings;
  glow = (Gaverage/1023);
}




//SET PATTERN MODES
void setmode(){
   int val = analogRead(modePin); 
    digitalWrite(resetPin1, HIGH);
    digitalWrite(resetPin2, HIGH);
   int tmp =10 -val/100;
   mode = tmp;

   if(tmp == 0) Mode_LED(10);
   else Mode_LED(tmp);

  val = analogRead(loopsPin);  
  tmp =10- val/100;
  looptimes = tmp;  
  Loops_LED(tmp);

}

void Mode_LED(int led_number)
{  
 // digitalWrite(latchPin2, 0);

  if(led_number <= 2){
     digitalWrite(latchPin2, LOW);
      shiftOut(dataPin2, clockPin2, MSBFIRST,0);
      shiftOut(dataPin2, clockPin2, MSBFIRST,pow(2, led_number-1));
      shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
      digitalWrite(latchPin2, HIGH);    
  }
  else  if(led_number >2 && led_number <=8){
     digitalWrite(latchPin2, LOW);
      shiftOut(dataPin2, clockPin2, MSBFIRST,0);
      shiftOut(dataPin2, clockPin2, MSBFIRST,pow(2, led_number-1)+1);
      shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
      digitalWrite(latchPin2, HIGH);    
  }
  else if(led_number>8 && led_number<= 10)
  {
    led_number = led_number-8;
   digitalWrite(latchPin2, LOW);
   shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
   shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
   shiftOut(dataPin2, clockPin2, MSBFIRST,pow(2, led_number-1));
   digitalWrite(latchPin2, HIGH);
  }
 // digitalWrite(latchPin2, 1);
}
void Loops_LED(int led_number)
{
   digitalWrite(latchPin2, LOW);
  
  if(led_number <= 6){
    led_number = led_number+2;
    shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
    shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
    shiftOut(dataPin2, clockPin2, MSBFIRST, pow(2, led_number-1)+1);    
  }
  else if(led_number>6 && led_number<= 8)
  {
     led_number = led_number - 6;
    shiftOut(dataPin2, clockPin2, MSBFIRST,  pow(2, led_number-1));
    shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
    shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
  }else if(led_number>8 && led_number<= 10)
  {
     led_number = led_number - 6;
    shiftOut(dataPin2, clockPin2, MSBFIRST,  pow(2, led_number-1)+1);
    shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
    shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
  }
  digitalWrite(latchPin2, HIGH);
}
