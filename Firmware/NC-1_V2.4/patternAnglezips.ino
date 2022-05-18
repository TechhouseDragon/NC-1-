const int numRowsAnglezips = numRows+1;
const int numColsAnglezips = numCols+1;
///
///
//you need to finish updating all of the array callouts

int newRowAnglezips;
int newColAnglezips;

void patternAnglezips(){
  int numLoops = 2;

  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }

  //seed the pattern with a pixel
  if (seed == 1){
    frameloops = 0;
     memset(patternArray,0,sizeof(patternArray));
     memset(nextpatternArray,0,sizeof(nextpatternArray));
    //seed pixels
    pixelSeed1 = 1;
    pixelSeed2 = 1;
    seed = 0;
    lastPattern = currentPattern;
  }

  //GENERATE PIXELS

  if (pixelSeed1 == 1){
    pixelStep1 = 1;
    pixelDir1 = random(5,9);
    if (pixelDir1 == 5){
      pixelRow1 = 0;
      pixelCol1 = random(numCols-3);
    }
    if (pixelDir1 == 6){
      pixelRow1 = 0;
      pixelCol1 = random(numCols-3);
    }
    if (pixelDir1 == 7){
      pixelRow1 = numRows-1;
      pixelCol1 = random(3,numCols);
    }

    if (pixelDir1 == 8){
      pixelRow1 = numRows-1;
      pixelCol1 = random(3,numCols);
    }
    pixelSeed1 = 0;
  }

  if (pixelSeed2 == 1){
    pixelStep2 = 1;
    pixelDir2 = random(5,9);
    if (pixelDir2 == 5){
      pixelRow2 = 0;
      pixelCol2 = random(numCols-3);
    }
    if (pixelDir2 == 6){
      pixelRow2 = 0;
      pixelCol2 = random(numCols-3);
    }
    if (pixelDir2 == 7){
      pixelRow2 = numRows-1;
      pixelCol2 = random(3,numCols);
    }

    if (pixelDir2 == 8){
      pixelRow2 = numRows-1;
      pixelCol2 = random(3,numCols);
    }
    pixelSeed2 = 0;
  }
  
  //Delay the first pixel2 if this is the first time through the loop
  if(pixelStep1<sqrt(numRows*numCols)&&(lastPattern != currentPattern)){
    pixelRow2 = pixelRow1;
    pixelCol2 = pixelCol1;
    pixelSeed2 = 1;
  }


  //clear the frame array
  memset(patternArray,0,sizeof(patternArray)); 
  WriteBit(pixelCol1, pixelRow1, "patternArray", 1);
  WriteBit(pixelCol2, pixelRow2, "patternArray", 1);
  
       if(pixelCol1 <= numCols/2){
         WriteBit(pixelCol1+mode*2,  pixelRow1, "patternArray", 1);
          
        }
        if(pixelCol1 > numCols/2){
          WriteBit(pixelCol1-mode*2,  pixelRow1, "patternArray", 1);
       //   bitWrite(patternArray[divi(pixelCol1-mode*2,  pixelRow1,patternCols )], modi(pixelCol1-mode*2,  pixelRow1, patternCols), 1);
        }
        if(pixelCol2 <= numCols/2){ 
          WriteBit(pixelCol2+mode*2,  pixelRow2, "patternArray", 1);
        //  bitWrite(patternArray[divi(pixelCol2+mode*2,  pixelRow2,patternCols )], modi(pixelCol2+mode*2,  pixelRow2, patternCols), 1);
        }
        if(pixelCol2 > numCols/2){ 
          WriteBit(pixelCol2-mode*2,  pixelRow2, "patternArray", 1);
          //bitWrite(patternArray[divi(pixelCol2-mode*2,  pixelRow2,patternCols )], modi(pixelCol2-mode*2,  pixelRow2, patternCols), 1);
        }
  
  setOutputArray();
  //PUSH PIXEL1
  dir = pixelDir1;
  setshift();
  pixelCol1 = pixelCol1 + colShift;
  pixelRow1 = pixelRow1 + rowShift;
  pixelStep1 = pixelStep1 + 1;

  //PUSH PIXEL2
  dir = pixelDir2;
  setshift();
  pixelCol2 = pixelCol2 + colShift;
  pixelRow2 = pixelRow2 + rowShift;
  pixelStep2 = pixelStep2 + 1;


  if ((pixelCol1 >= numCols) or (pixelRow1 >= numRows)){
    pixelSeed1 = 1;
  }

  if ( (pixelCol1 < 0) or (pixelRow1 < 0)){
    pixelSeed1 = 1;
  }

  if ((pixelCol2 >= numCols) or (pixelRow2 >= numRows)){
    pixelSeed2 = 1;
  } 

  if ((pixelCol2 < 0) or (pixelRow2 < 0)){
    pixelSeed2 = 1;
  }

  triggernow = 0;
  frameloops = frameloops +1;

  if (frameloops == (numRowsAnglezips + numColsAnglezips)/2){
    loopCount = loopCount +1; 
    frameloops = 0;
  }

  if (loopCount == numLoops){
    loopCount = 0;
   // currentPattern = currentPattern +1; 
  }
}
