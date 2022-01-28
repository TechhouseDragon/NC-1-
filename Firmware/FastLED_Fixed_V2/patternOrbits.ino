const int numRowsOrbits = numRows;
const int numColsOrbits = numCols;
int newRowOrbits;
int newColOrbits;
void patternOrbits(){
  int numLoops = 16;

//check if this is the first time through the pattern
if (lastPattern != currentPattern){
    seed = 1;
}

  //seed the pattern with a pixel
  if (seed == 1){
    frameloops = 0;
    pixelRow1 = 0;
    pixelCol1 = 0;
    pixelDir1 = 1;
    pixelRow2 = 1;
    pixelCol2 = 1;
    pixelDir2 = 1;
    pixelRow3 = 2;
    pixelCol3 = 2;
    pixelDir3 = 1;
    seed = 0;
    lastPattern = currentPattern;

  }
  //clear the pattern array
  memset(patternArray,0,sizeof(patternArray)); 

  //place the pixel in the pattern array   
  bitWrite(patternArray[divi(pixelCol1, pixelRow1,patternCols)], modi(pixelCol1, pixelRow1, patternCols), 1);  
 // patternArray[pixelCol1][pixelRow1] = 1;

 //  bitWrite(patternArray[divi((numCols-1) - pixelCol1, (numRows-1) - pixelRow1,patternCols )], modi((numCols-1) - pixelCol1, (numRows-1) - pixelRow1, patternCols), 1);  
if(looptimes>1){
 bitWrite(patternArray[divi((numCols-1) - pixelCol1, (numRows-1) - pixelRow1,patternCols)], modi((numCols-1) - pixelCol1, (numRows-1) - pixelRow1, patternCols), 1);  
//  patternArray[(numCols-1) - pixelCol1][(numRows-1) - pixelRow1] = 1;
  }
  if(mode>1){
    bitWrite(patternArray[divi(pixelCol2, pixelRow2,patternCols )], modi(pixelCol2, pixelRow2,patternCols), 1);  
  // patternArray[pixelCol2][pixelRow2] = 1;
  }
  if(looptimes>2){
    bitWrite(patternArray[divi((numCols-1) - pixelCol2, (numRows-1) - pixelRow2,patternCols )], modi((numCols-1) - pixelCol2, (numRows-1) - pixelRow2,patternCols ), 1);  
 // patternArray[(numCols-1) - pixelCol2][(numRows-1) - pixelRow2] = 1;
  }  
  if(mode>3){
    bitWrite(patternArray[divi(pixelCol3, pixelRow3,patternCols)], modi(pixelCol3, pixelRow3,patternCols), 1);  
  //patternArray[pixelCol3][pixelRow3] = 1;
  
    if(looptimes>3){
      bitWrite(patternArray[divi((numCols-1) - pixelCol3, (numRows-1) - pixelRow3,patternCols)], modi((numCols-1) - pixelCol3, (numRows-1) - pixelRow3,patternCols), 1); 
    //patternArray[(numCols-1) - pixelCol3][(numRows-1) - pixelRow3] = 1;
    }  

  }
setOutputArray();
 //PUSH PIXEL1
  dir = pixelDir1;
  setshift();
  pixelCol1 = pixelCol1 + colShift;
  pixelRow1 = pixelRow1 + rowShift;

  if (pixelDir1==1 && pixelCol1 == (numCols-1)){
    pixelDir1 = 2;
  }

  if (pixelDir1==2 && pixelRow1 == (numRows-1)){
    pixelDir1 = 3;
  }

  if (pixelDir1==3 && pixelCol1 == 0){
    pixelDir1 = 4;
  }

  if (pixelDir1==4 && pixelRow1 == 0){
    pixelDir1 = 1;
  }
  //PUSH PIXEL2
  dir = pixelDir2;
  setshift();
  pixelCol2 = pixelCol2 + colShift;
  pixelRow2 = pixelRow2 + rowShift;
  
  if (pixelDir2==2 && pixelRow2 == (numRows -1)){
    pixelDir2 = 1;
  }

  if (pixelDir2==1 && pixelCol2 == (numCols -1)){
    pixelDir2 = 4;
  }

  if (pixelDir2==4 && pixelRow2 == 0){
    pixelDir2 = 3;
  }

  if (pixelDir2==3 && pixelCol2 == 0){
    pixelDir2 = 2;
  }

  //PUSH PIXEL3
  dir = pixelDir3;
  setshift();
  pixelCol3 = pixelCol3 + colShift;
  pixelRow3 = pixelRow3 + rowShift;
  
  if (pixelDir3==1 && pixelCol3 == (numCols -3)){
    pixelDir3 = 2;
  }

  if (pixelDir3==2 && pixelRow3 == (numRows -3)){
    pixelDir3 = 3;
  }

  if (pixelDir3==3 && pixelCol3 == 2){
    pixelDir3 = 4;
  }

 if (pixelDir3==4 && pixelRow3 == 2){
    pixelDir3 = 1;
  }    
  triggernow = 0;
  frameloops = frameloops +1;

  if (frameloops == (2*numRowsOrbits + 2* numColsOrbits)-1){
    loopCount = loopCount +1; 
    frameloops = 0;
  }

  if (loopCount == numLoops){
    loopCount = 0;
    currentPattern = currentPattern +1;
  }  
}
