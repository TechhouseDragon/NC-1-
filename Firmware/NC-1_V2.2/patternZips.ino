const int numRowsZips = numRows+1;
const int numColsZips = numCols+1;

int newRowZips;
int newColZips;

void patternZips(){
  int frameloops = 16;
  int numLoops = 16;

    if (lastPattern != currentPattern){
    seed = 1;
  }
  //seed the pattern with a pixel
  if (seed == 1){
    frameloops = NumLEDs/2;
    pixelSeed1 = 1;
    pixelSeed2 = 1;
    pixelSeed3 = 1;
    pixelSeed4 = 1;
    seed = 0;
    lastPattern = currentPattern;
    frameStep = 0;
    loopCount = 0;
  }
  
  //PIXEL1
  if (pixelSeed1 == 1){
    pixelStep1 = 1;

if (mode==1){
    pixelDir1 = 1;
}

if (mode==2){
    pixelDir1 = 3;
}

if (mode==3){
    pixelDir1 = random(1,3)*2;
   }

if (mode==4){
    pixelDir1 = random(1,5);
}


    if (pixelDir1 == 1){
      pixelRow1 = random(numRows);
      pixelCol1 = 0;
    }
    if (pixelDir1 == 2){
      pixelRow1 = 0;
      pixelCol1 = random(numCols);
    }
    if (pixelDir1 == 3){
      pixelRow1 = random(numRows);
      pixelCol1 = numCols-1;
    }

    if (pixelDir1 == 4){
      pixelRow1 = numRows-1;
      pixelCol1 = random(numCols);
    }
    pixelSeed1 = 0;
  }


//Pixel 2
if ((mode2 > 1)&&(pixelSeed2 == 1)&& (pixelStep1 >= numRowsZips/mode2)){
    pixelStep2 = 1;

if (mode==1){
    pixelDir2 = 1;
}

if (mode==2){
    pixelDir2 = 3;
}

if (mode==3){
    pixelDir2 = random(1,3)*2;
   }

if (mode==4){
    pixelDir2 = random(1,5);
}
    if (pixelDir2 == 1){
      pixelRow2 = random(numRows);
      pixelCol2 = 0;
    }
    if (pixelDir2 == 2){
      pixelRow2 = 0;
      pixelCol2 = random(numCols);
    }
    if (pixelDir2 == 3){
      pixelRow2 = random(numRows);
      pixelCol2 = numCols-1;
    }

    if (pixelDir2 == 4){
      pixelRow2 = numRows-1;
      pixelCol2 = random(numCols);
    }
    pixelSeed2 = 0;
  }
  
   //Pixel 3
  if ((mode2 > 2)&&(pixelSeed3 == 1)&& (pixelStep2 >= numRowsZips/mode2)){
    pixelStep3 = 1;

if (mode==1){
    pixelDir3 = 1;
}

if (mode==2){
    pixelDir3 = 3;
}

if (mode==3){
    pixelDir3 = random(1,3)*2;
   }

if (mode==4){
    pixelDir3 = random(1,5);
}

    if (pixelDir3 == 1){
      pixelRow3 = random(numRows);
      pixelCol3 = 0;
    }
    if (pixelDir3 == 2){
      pixelRow3 = 0;
      pixelCol3 = random(numCols);
    }
    if (pixelDir3 == 3){
      pixelRow3 = random(numRows);
      pixelCol3 = numCols-1;
    }

    if (pixelDir3 == 4){
      pixelRow3 = numRows-1;
      pixelCol3 = random(numCols);
    }
    pixelSeed3 = 0;
  }
  
  //END PIXEL 3
  
  
   //Pixel 4
  if ((mode2 > 2)&&(pixelSeed4 == 1)&& (pixelStep3 >= numRowsZips/mode2)){
    pixelStep4 = 1;

if (mode==1){
    pixelDir4 = 1;
}

if (mode==2){
    pixelDir4 = 3;
}

if (mode==3){
    pixelDir4 = random(1,3)*2;
   }

if (mode==4){
    pixelDir4 = random(1,5);
}

    if (pixelDir4 == 1){
      pixelRow4 = random(numRows);
      pixelCol4 = 0;
    }
    if (pixelDir4 == 2){
      pixelRow4 = 0;
      pixelCol4 = random(numCols);
    }
    if (pixelDir4 == 3){
      pixelRow4 = random(numRows);
      pixelCol4 = numCols-1;
    }

    if (pixelDir4 == 4){
      pixelRow4 = numRows-1;
      pixelCol4 = random(numCols);
    }
    pixelSeed4 = 0;
  }
  
  //END PIXEL 4

  //clear the frame array
  memset(patternArray,0,sizeof(patternArray)); 

  //place the pixel in the frame array    
  WriteBit(pixelCol1, pixelRow1, "patternArray", 1);
  //patternArray[pixelCol1][pixelRow1] = 1;
WriteBit(pixelCol2, pixelRow2, "patternArray", 1);
  //patternArray[pixelCol2][pixelRow2] = 1;
WriteBit(pixelCol3, pixelRow3, "patternArray", 1);
 // patternArray[pixelCol3][pixelRow3] = 1;
  WriteBit(pixelCol4, pixelRow4, "patternArray", 1);
  //patternArray[pixelCol4][pixelRow4] = 1;


setOutputArray();

  //PUSH PIXEL1
  dir = pixelDir1;
  setshift();
  pixelCol1 = pixelCol1 + colShift;
  pixelRow1 = pixelRow1 + rowShift;
  pixelStep1 = pixelStep1 + 1;

  if ((pixelDir1%2 != 0) && (pixelStep1 > (numColsZips))){
    pixelSeed1 = 1;
  }
  if ((pixelDir1%2 == 0) && (pixelStep1 > (numRowsZips))){
    pixelSeed1 = 1;
  }
// END PUSH 1

  //PUSH PIXEL2
  dir = pixelDir2;
  setshift();
  pixelCol2 = pixelCol2 + colShift;
  pixelRow2 = pixelRow2 + rowShift;
  pixelStep2 = pixelStep2 + 1;

  if ((pixelDir2%2 != 0) && (pixelStep2 > numColsZips)){
    pixelSeed2 = 1;
  }
  if ((pixelDir2%2 == 0) && (pixelStep2 > numRowsZips)){
    pixelSeed2 = 1;
  }
//END PUSH 2

  //PUSH PIXEL3
  dir = pixelDir3;
  setshift();
  pixelCol3 = pixelCol3 + colShift;
  pixelRow3 = pixelRow3 + rowShift;
  pixelStep3 = pixelStep3 + 1;

  if ((pixelDir3%2 != 0) && (pixelStep3 > numColsZips)){
    pixelSeed3 = 1;
  }
  if ((pixelDir3%2 == 0) && (pixelStep3 > numRowsZips)){
    pixelSeed3 = 1;
  }
//END PUSH 3

  //PUSH PIXEL4
  dir = pixelDir4;
  setshift();
  pixelCol4 = pixelCol4 + colShift;
  pixelRow4 = pixelRow4 + rowShift;
  pixelStep4 = pixelStep4 + 1;

  if ((pixelDir4%2 != 0) && (pixelStep4 > numColsZips)){
    pixelSeed4 = 1;
  }
  if ((pixelDir4%2 == 0) && (pixelStep4 > numRowsZips)){
    pixelSeed4 = 1;
  }
//END PUSH 4

  triggernow = 0;
  
  frameStep = frameStep +1;

if (frameStep >= frameloops){ 
    frameStep = 0;
    seed=1;
    loopCount = loopCount +1; 
}

  if (loopCount >= numLoops){
   loopCount = 0;
//    currentPattern = currentPattern +1; 
  }
}
