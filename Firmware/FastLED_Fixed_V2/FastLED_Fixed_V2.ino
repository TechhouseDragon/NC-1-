#include "FastLED.h"

int latchPin2 = 25;  // Latch pin of 74HC595 is connected to Digital pin 25 RCLK
int clockPin2 = 27; // Clock pin of 74HC595 is connected to Digital pin 27 SRCLK
int dataPin2 = 23;  // Data pin of 74HC595 is connected to Digital pin 23 SER
int resetPin2 = 29; // 290SRCLK#
///
// Pattern Select LED pins
int latchPin1 = 48;  // Latch pin of 74HC595 is connected to Digital pin 48 RCLK
int clockPin1 = 50; // Clock pin of 74HC595 is connected to Digital pin 50 SRCLK
int dataPin1 = 46;  // Data pin of 74HC595 is connected to Digital pin 46 SER
int resetPin1 = 52; // 520SRCLK#
/// 

int YellowLED = 31;  // Power LED color Yellow
int RedLED = 33;  // Power LED color Red

int LEDPot = 4;  // normal LED pin

// Pallete Button Pins 
int BUTTONR = 7; // Red color LED
int BUTTONG = 6; // Green Color LED
int BUTTONB = 5; // Blue Color LED
int PalletePin = 42; // Pallete Button Pin
///
/// color mode toggle Pin
int ColorModePin = 3;
///
int BTN[10] ={22, 24, 26, 28, 30, 32, 34, 36, 39, 40}; // Pattern Select Buttons

int modePin = A15;  // Mode Rotary Pin
int loopsPin = A14; // Loop Rotary Pin

int RedColorPin = A0;
int GreenColorPin = A1;
int BlueColorPin = A2;
int ColorPin = A3;
int BPMPin = A4;
int GlowPin = A5;
int VolumePin = A6;
int SpeedPin = A7;
int Speed1 = 35;
int Speed2 = 37;
int Speed3 = 38;
int Speed4 = 41;
int BlackOutPin = 2;
int Strobe1Pin = 43;
int Strobe2Pin = 45;


#define r 0
#define g 1
#define b 2
#define NumLEDs 256
//Array Variables
const int numRows = 32;
const int numCols = 8;
const int patternRows = 2*numRows;
const int patternCols = 2*numCols;


#define numReadings 3 
#define colorSamples 8

//FastLED STUFF
#define DATA_PIN 47
#define CLOCK_PIN 13
// Define the array of leds
CRGB LEDChannels[NumLEDs];




//speed control
double loopspeed = 100;
double strobespeed;




//int LEDChannels[NumLEDs][3] = {
//  0};


byte LEDArray[(numCols * numRows ) / 8 +1] ={
  0};
int8_t nextLEDArray[(numCols  * numRows) / 8 +1] = {
  000000};
int8_t patternArray[(patternCols *patternRows) /8 +1]={
  0};
int8_t nextpatternArray[(patternCols* patternRows) /8 +1] = {
  0};
int8_t glowArray[numCols][numRows] = {
  0};
int8_t colourArray[numCols][numRows][3] = {
0};


//pattern variables
int numPatterns = 10;
int currentPattern = 1;
int lastPattern=1;
int instrobe = 0;
int strobePattern;
int frameloops;
int frameStep;
int pixelStep;
int colorStep =1;
int loopCount = 0;
int seed =1;
int row;
int col;
int rowshift;
int colshift;
int newRow;
int newCol;
int currentCol;
int currentRow;
int maxRadius;


int flash;
int flashCount;
int flashElapsed;
int flashStart;



int8_t dropRow;
int8_t dropCol;
int8_t deltaCol;
int8_t deltaRow;
int8_t rippleRadius;
int dir;
int scanCol;

int pixelRow1;
int pixelCol1;
int pixelDir1;
int pixelStep1;
int pixelSeed1;
int pixelRow2;
int pixelCol2;
int pixelDir2;
int pixelStep2;
int pixelSeed2;
int pixelRow3;
int pixelCol3;
int pixelDir3;
int pixelStep3;
int pixelSeed3;
int pixelRow4;
int pixelCol4;
int pixelDir4;
int pixelStep4;
int pixelSeed4;


int i;
double j;
int k;
int l;


double colorinput = 0;
double color = 0;
double volumeinput;
double volume = 0;
double glowinput = 0;
double glow = 0;
double modeinput = 0;
int mode = 0;
int currentmode = 0;
int lastmode = 0;
double loopinput = 0;
int looptimes = 0;


//speed control variables
double speedinput;

double strobeinput;


double lastTrigger;
double telapsed;
int triggernow;
double Cloopspeed;
double Celapsed;
float Clooplength;
double Cloopstart;

// knob read variables: V = Volume C = Color S = Speed G = Glow

int REFreadings[numReadings];      // the readings from the analog input
int REFindex;                  // the index of the current reading
int REFtotal;                  // the running total
double REFaverage;                // the average


int Creadings[colorSamples];      // the readings from the analog input
int Cindex;                  // the index of the current reading
int Ctotal;                  // the running total
double Caverage;                // the average

int Vreadings[numReadings];      // the readings from the analog input
int Vindex;                  // the index of the current reading
int Vtotal;                  // the running total
double Vaverage;                // the average

int Sreadings[numReadings];      // the readings from the analog input
int Sindex;                  // the index of the current reading
int Stotal;                  // the running total
double Saverage;                // the average

int Rreadings[numReadings];      // the readings from the analog input
int Rindex;                  // the index of the current reading
int Rtotal;                  // the running total
double Raverage;                // the average

int Grnreadings[numReadings];      // the readings from the analog input
int Grnindex;                  // the index of the current reading
int Grntotal;                  // the running total
double Grnaverage;                // the average

int Blureadings[numReadings];      // the readings from the analog input
int Bluindex;                  // the index of the current reading
int Blutotal;                  // the running total
double Bluaverage;                // the average

int Greadings[numReadings];      // the readings from the analog input
int Gindex;                  // the index of the current reading
int Gtotal;                  // the running total
double Gaverage;                // the average

int STRreadings[numReadings];      // the readings from the analog input
int STRindex;                  // the index of the current reading
int STRtotal;                  // the running total
double STRaverage;                // the average
int OldPattern[10] = {0,0,0,0,0,0,0,0,0,0};
int PatternValue[10] = {0,0,0,0,0,0,0,0,0,0};
typedef void (*SimplePatternList[])();
int patternnumber;

void setup() {

  pinMode(latchPin1, OUTPUT);
  pinMode(resetPin1, OUTPUT);
  pinMode(clockPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);
  
  pinMode(latchPin2, OUTPUT);
  pinMode(resetPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
  
  pinMode(YellowLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(LEDPot, OUTPUT);
  pinMode(BUTTONR, OUTPUT);
  pinMode(BUTTONG, OUTPUT);
  pinMode(BUTTONB, OUTPUT);
  
  pinMode(RedColorPin, INPUT);
  pinMode(GreenColorPin, INPUT);
  pinMode(BlueColorPin, INPUT);
  pinMode(ColorPin, INPUT);
  pinMode(BPMPin, INPUT);
  pinMode(GlowPin, INPUT);
  pinMode(VolumePin, INPUT);
  pinMode(SpeedPin, INPUT);
  pinMode(Speed1, INPUT);
  pinMode(Speed2, INPUT);
  pinMode(Speed3, INPUT);
  pinMode(Speed4, INPUT);
  pinMode(ColorModePin, INPUT_PULLUP);
  pinMode(BlackOutPin, INPUT_PULLUP);
  for(int i = 0; i<10; i++){
    pinMode(BTN[i], INPUT);
  }
  Serial.begin(9600);
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(LEDChannels, NumLEDs);
  patternnumber = 0;
}

SimplePatternList Mode1 = { patternZips,patternAnglezips, patternBox, patternCentreZips, patternClouds, patternDiamond, patternDots,patternDrivingrain, patternFlash,patternRain};
SimplePatternList Mode2 = { patternBox, patternCentreZips, patternClouds, patternDiamond, patternDots,patternDrivingrain, patternFlash,patternOrbits,patternZips,patternRain};
SimplePatternList Mode3 = { patternCentreZips, patternClouds, patternDiamond, patternDots,patternDrivingrain, patternFlash,patternOrbits,patternZips,patternRain,patternSpots2};
SimplePatternList Mode4 = { patternClouds, patternDiamond, patternDots,patternDrivingrain, patternFlash,patternOrbits,patternZips,patternRain,patternSpots2,patternSteps};
SimplePatternList Mode5 = { patternDiamond, patternDots,patternDrivingrain, patternFlash,patternOrbits,patternZips,patternRain,patternSpots2,patternSteps,patternWorms};
SimplePatternList Mode6 = { patternDots,patternDrivingrain, patternFlash,patternOrbits,patternZips,patternRain,patternSpots2,patternSteps,patternWorms,patternZips};
SimplePatternList Mode7 = { patternDrivingrain, patternFlash,patternOrbits,patternZips,patternRain,patternDiamond,patternSpots2,patternSteps,patternWorms,patternDrivingrain};
SimplePatternList Mode8 = { patternRain,patternDrivingrain, patternDiamond, patternOrbits,patternZips,patternClouds,patternFlash,patternSpots2,patternSteps,patternDots};
SimplePatternList Mode9 = { patternSpots2, patternDrivingrain, patternClouds, patternFlash,patternOrbits,patternDots,patternZips,patternRain,patternCentreZips,patternDiamond};
SimplePatternList Mode10 = {patternRain, patternClouds,patternCentreZips,patternFlash, patternDiamond, patternDots,patternDrivingrain,patternOrbits,patternZips, patternBox};





void loop() {
 digitalWrite(RedLED, 1);
 digitalWrite(LEDPot, HIGH);
  UpdatePattern();
  WriteLEDArray(); 
  
  if (digitalRead(Strobe1Pin)==1){
    seed = 1;
    instrobe = 1;
    patternStrobe(); 
  }
  // look for a trigger event
    if (trigger()){      
      if (digitalRead(BlackOutPin)==0){
         currentPattern = 11;
      }else{
      //  patternZips();
        AutoPattern();  
      }
    }
}  



int nNumber = 1;

void AutoPattern(){
 int time_tmp = 10*looptimes;  
 EVERY_N_SECONDS( time_tmp ) {
   nNumber++;  
   currentPattern = 1;
   lastPattern=1;
   loopCount = 0;
   seed =1;
 } // change patterns periodically
 if(nNumber >9) nNumber = 0;
  if(PatternValue[nNumber] == 1){
    switch(mode){
      case 1:
        Mode1[nNumber]();
      break;
      case 2:
        Mode2[nNumber]();
      break;
      case 3:
        Mode3[nNumber]();
      break;
      case 4:
        Mode4[nNumber]();
      break;
      case 5:
        Mode5[nNumber]();
      break;
      case 6:
        Mode6[nNumber]();
      break;
      case 7:
        Mode7[nNumber]();
      break;
      case 8:
        Mode8[nNumber]();
      break;
      case 9:
        Mode9[nNumber]();
      break;
      case 10:
        Mode10[nNumber]();
      break;
      default:
           memset(patternArray,0,sizeof(patternArray)); 
            setOutputArray();
      break;
    }
  }else {
    nNumber++;
      currentPattern = 1;
      lastPattern=1;
      loopCount = 0;
      seed =1;
      memset(patternArray,0,sizeof(patternArray)); 
      setOutputArray();
   }


  
}

void UpdatePattern(){
    for(int i = 0; i<10; i++){
      int val = digitalRead(BTN[i]);
       if(val == 0 && val != OldPattern[i]) {
          
          if(PatternValue[i] == 1){
            for(int j = 0; j<10; j++){
                PatternValue[j]  = 0;
              }
            patternnumber = 0;
            PatternValue[i] = 0;
          } 
          else{ 
            for(int j = 0; j<10; j++){
                PatternValue[j]  = 0;
             }
            patternnumber = i+1;
            PatternValue[i] = 1;  
          }   
          Serial.print("patternnumber : "); Serial.println(patternnumber);      
       }
        OldPattern[i] = val;
      
    }
    Pattern_LED();   
}
byte b1 = 0b00000000;
byte b2 = 0b00000000;
byte b3 = 0b00000000;

void Pattern_LED()
{  
     digitalWrite(latchPin1, LOW);
     for(int i = 0; i<4; i++){
        if(PatternValue[i] == 1) {
          bitWrite(b1, i*2,0);
          bitWrite(b1, i*2+1,1);  
        }else {
          bitWrite(b1, i*2,0);
          bitWrite(b1, i*2+1,0);  
        }
     }
      for(int i = 0; i<4; i++){
        if(PatternValue[i+4] == 1) {
          bitWrite(b2, i*2,0);
          bitWrite(b2, i*2+1,1);  
        }else{
          bitWrite(b2, i*2,0);
          bitWrite(b2, i*2+1,0);  
        }
     }
      for(int i = 0; i<4; i++){
        if(PatternValue[i+8] == 1) {
          bitWrite(b3, i*2,0);
          bitWrite(b3, i*2+1,1);  
        }else{
          bitWrite(b3, i*2,0);
          bitWrite(b3, i*2+1,0);  
        }
     }
 
     shiftOut(dataPin1, clockPin1, MSBFIRST,b3); 
     shiftOut(dataPin1, clockPin1, MSBFIRST,b2); 
     shiftOut(dataPin1, clockPin1, MSBFIRST,b1);      
     digitalWrite(latchPin1, HIGH);
}
int divi(int a1, int a2, int n ){  
  int a3= a1 + a2*n;
  int a4 = a3 % 8;
  int a5 = a3 - a4;
  return (int)(a5/8);
}
int modi(int a1, int a2, int n){
  int a3= a1 + a2*n;
  int a4 = a3 % 8;
  return a4;
}
