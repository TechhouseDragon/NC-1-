// COLOUR ENGINE

double redintensity = 0;
double blueintensity = 0;
double greenintensity = 0;
int RValue = 1023;
int GValue = 1023;
int BValue = 1023;

int palletselect = 1;
int palletchange = 0;
int pallet = 1;
int Cloopcnt = 0;


void setcolour(){
  colorinput = analogRead(ColorPin);
  colorinput = map(colorinput, 0, 1023, 1023, 0);
  //color = colorinput/1023;

  Ctotal= Ctotal - Creadings[Cindex];         
  // read from the sensor:  
  Creadings[Cindex] = colorinput; 
  // add the reading to the total:
  Ctotal= Ctotal + Creadings[Cindex];       
  // advance to the next position in the array:  
  Cindex = Cindex + 1;                    
  // if we're at the end of the array...
  if (Cindex >= colorSamples)              
  // ...wrap around to the beginning: 
    Cindex = 0; 
  // calculate the average:
  Caverage = Ctotal / colorSamples;
  Cloopspeed = Caverage/1023;
  
  //LOOK FOR PALLET CHANGE 
  palletselect = digitalRead(PalletePin); 
  if (palletselect > palletchange){
    pallet = pallet + 1;
    if (pallet > 4){
      pallet = 1;
    }
  }
  
  palletchange = palletselect;

if (digitalRead(ColorModePin) == 0){  
  RValue = 1023;
  GValue = 1023;
  BValue = 1023;
  Clooplength = 2500/Cloopspeed;
  Clooplength = constrain (Clooplength,1,128000);
  Celapsed = millis()-Cloopstart;
  if (Celapsed > Clooplength) {
    Celapsed = Clooplength;
    Cloopstart = millis();
    Cloopcnt ++;    
  }
  color = (Celapsed/Clooplength);
  if(Cloopcnt % 2 == 1){
    color = 1 - color;     
  }
  if(color == 0.0) color = 1;
  else if(color == 1.0) color = 0;


  //Grab Color From Current Pallet

  //PALETTE 1 - RAINBOW

  if (pallet==1){  
    if (color<=0.3){      
      redintensity = RValue;
      greenintensity = GValue*(0.3-color); //green shifts from 1 to 0
      blueintensity = BValue*(0.3-color);  //blue shifts from 1 to 0
    }

    if (color >0.3 && color <=0.7){
      redintensity = RValue*(0.7-color)/(0.7-0.25);  //red shifts from 1 to 0 
      greenintensity = GValue*(color-0.25)/(0.7-0.25);  //green shifts from 0 to 1
      blueintensity = 0;
    }                
    if (color >0.7 && color <=0.85){
      redintensity = 0;
      greenintensity = GValue*(0.85-color)/(0.85-0.6);  //green shifts from 1 to 0
      blueintensity = BValue*(color-0.6)/(0.85-0.6);  //blue shifts from 0 to 1
    }
    if (color >0.85 && color <=0.95){
      redintensity = RValue*(color-0.85)/(0.95-0.85);  //red shifts from 0 to 1
      greenintensity = 0;  
      blueintensity = BValue;
    }
    if (color >0.95){
      redintensity = RValue;
      greenintensity = GValue*(color-0.95)/(1-0.95);  //green shifts from 0 to 1
      blueintensity = BValue;
    }
  }

  //PALLET 2 - fire
  if (pallet==2){  
    blueintensity = 20;

    if (color<0.45){
      redintensity = RValue;
      greenintensity = GValue*(0.45-color);  // green shifts from 1 to 0
    }
    if (color >=0.45 && color <=0.55){
      redintensity = RValue;
      greenintensity = 0;
    }
    
    if (color>0.55){
      redintensity = RValue;
      greenintensity = GValue*(color-0.55)/(1-0.55); // green shifts from 0 to 1
    }   
   greenintensity = greenintensity*0.5; //add some attenuation for yellow balance                           
  }

  //PALLET 3 - SPACE

  if (pallet==3){              
    greenintensity=20; 
    blueintensity = BValue*(color);  //blue shifts from 0 to 1
    blueintensity = map(blueintensity,0,1023,30,1023);
    redintensity = RValue*(1-color); // red shifts from 1 to 0
    redintensity = map(redintensity,0,1023,30,1023);
    if(redintensity > blueintensity) redintensity = blueintensity;
    if(redintensity > greenintensity) redintensity = greenintensity;

  } 
   

  //PALLET 4 - UNDER THE SEA

  if (pallet==4){              
    redintensity=20;     
    if (color<0.5){  
      blueintensity = BValue*(0.5-color); //blue shifts from 1 to 0
      greenintensity = GValue;
    }
    if (color >=0.5 && color <=0.9){
      blueintensity = BValue*(color-0.5)/(0.9-0.5); //blue shifts from 0 to 1
      greenintensity = GValue*(0.9-color)/(0.9-0.5); // green shifts from 1 to 0
    }
    if(color > 0.9){
      blueintensity = BValue;
      greenintensity = GValue*(color - 0.9)/(1-0.9);  // green shifts from 0 to 1
    } 
  }  
}

else{
    int valr = analogRead(RedColorPin);
    redintensity = map(valr, 0, 1023, 1023, 0);
    int valg = analogRead(GreenColorPin);
    greenintensity = map(valg, 0, 1023, 1023, 0);
    int valb = analogRead(BlueColorPin);
    blueintensity = map(valb, 0, 1023, 1023, 0);

    if (pallet == 2){
      blueintensity = 20;
      if (redintensity < greenintensity){
          greenintensity = redintensity;
        }
    }
    if (pallet == 3){
      greenintensity = 20;
    }
    if (pallet == 4){
      redintensity = 20;
    }   
}

//Set the Pallette button color
  UpdatePalleteLED();  

  //READ AND AVERAGE VOLUME KNOB INPUT  

  volumeinput = analogRead(VolumePin);
  volumeinput = map(volumeinput, 0, 1023, 1023, 0);
  // subtract the last reading:
  Vtotal= Vtotal - Vreadings[Vindex];         
  // read from the sensor:  
  Vreadings[Vindex] = volumeinput; 
  // add the reading to the total:
  Vtotal= Vtotal + Vreadings[Vindex];       
  // advance to the next position in the array:  
  Vindex = Vindex + 1;                    
  // if we're at the end of the array...
  if (Vindex >= numReadings)              
  // ...wrap around to the beginning: 
    Vindex = 0; 
  // calculate the average:
  Vaverage = Vtotal / numReadings;
  volume = (Vaverage/1023);  //0.8 Attenuation for power and brightness at the PAL//
  volume = volume*0.05;
//  constrain (volume, 0, 1023);
  
  //Set Colour Intensities
  //red attenuation (0-255)
  redintensity = redintensity*volume;
  //blue attenuation (0-255)
  blueintensity = blueintensity*volume;
  //green attenuation (0-255)
  greenintensity = greenintensity*volume;
    
  if (instrobe == 1){
    redintensity = 1023;
    blueintensity = 1023;
    greenintensity = 1023;
  }
} 

void UpdatePalleteLED(){

  int Rpallete = map(redintensity, 0, 1023, 255, 200);
  int Gpallete = map(greenintensity, 0, 1023, 255, 100);
  int Bpallete = map(blueintensity, 0, 1023, 255, 100);
  analogWrite(BUTTONR, Rpallete);
  analogWrite(BUTTONG, Gpallete);
  analogWrite(BUTTONB, Bpallete);  
} 
