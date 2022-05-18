void patternPinball(){
  int numLoops = 32;

  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }

  
  
  //seed the pattern with a pixel
  if (seed == 1){
    currentmode = mode;
    frameloops = 0;
    //seed pixels
    pixelSeed1 = 1;
    pixelSeed2 = 1;
    pixelSeed3 = 1;
    seed = 0;
    lastPattern = currentPattern;
  }

  //GENERATE PIXELS
  //PIXEL1
  if (pixelSeed1 == 1){
    pixelStep1 = 1;
    pixelDir1 = random(2);
    if (pixelDir1 == 1){
      pixelDir1 = 5;
    }
    if (pixelDir1 == 0){
      pixelDir1 = 8;
    }
    pixelCol1 = 0;
    pixelRow1 = random(numRows);
    pixelSeed1 = 0;
  }

  //PIXEL2
  if(mode > 2){
    if (pixelSeed2 == 1){
      pixelStep2 = 1;
      pixelDir2 = random(2);
      if (pixelDir2 == 1){
        pixelDir2 = 5;
      }
      if (pixelDir2 == 0){
        pixelDir2 = 8;
      }
      pixelCol2 = 0;
      pixelRow2 = random(numRows);
      pixelSeed2 = 0;
    }
  }

  //PIXEL3
  if(mode > 3){
    if ((pixelSeed3 == 1)){
      pixelStep3 = 1;
      pixelDir3 = random(2);
      if (pixelDir3 == 1){
        pixelDir3 = 5;
      }
      if (pixelDir3 == 0){
        pixelDir3 = 8;
      }
      pixelCol3 = 0;
      pixelRow3 = random(numRows);
      pixelSeed3 = 0;
    }
  }



  //clear the frame array
  memset(patternArray,0,sizeof(patternArray)); 

  //place the pixel in the frame array   
  WriteBit(pixelCol1,pixelRow1, "patternArray", 1) ;
 // patternArray[pixelCol1][pixelRow1] = 1;
 WriteBit(pixelCol2,pixelRow2, "patternArray", 1) ;
 // patternArray[pixelCol2][pixelRow2] = 1;
  WriteBit(pixelCol3,pixelRow3, "patternArray", 1) ;
 // patternArray[pixelCol3][pixelRow3] = 1;

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


  //PUSH PIXEL3
  dir = pixelDir3;
  setshift();
  pixelCol3 = pixelCol3 + colShift;
  pixelRow3 = pixelRow3 + rowShift;
  pixelStep3 = pixelStep3 + 1;
  


  ////BOUNCE THE PIXELS OFF THE WALLS (we do this first to fix end of loop shift off the array)
  //BOUNCE PIXEL1
  if ((pixelDir1 == 8) && (pixelRow1 == 0)){
    pixelDir1 = 5;
  }

  if ( (pixelDir1 == 5) && (pixelRow1 == numRows-1)){
    pixelDir1 = 8;
  }

  if (pixelCol1 >= numCols){
    pixelSeed1 = 1;
  } 
  //BOUNCE PIXEL2
  if ((pixelDir2 == 8) && (pixelRow2 == 0)){
    pixelDir2 = 5;
  }

  if ( (pixelDir2 == 5) && (pixelRow2 == numRows-1)){
    pixelDir2 = 8;
  }

  if (pixelCol2 >= numCols){
    pixelSeed2 = 1;
  } 
  //BOUNCE PIXEL3
  if ((pixelDir3 == 8) && (pixelRow3 == 0)){
    pixelDir3 = 5;
  }

  if ( (pixelDir3 == 5) && (pixelRow3 == numRows-1)){
    pixelDir3 = 8;
  }

  if (pixelCol3 >= numCols){
    pixelSeed3 = 1;
  }
  
    triggernow = 0;
  frameloops = frameloops +1;

  if (frameloops >= (numRows + numCols)/2){
    loopCount = loopCount +1; 
    frameloops = 0;
  }

  if (loopCount >= numLoops){
    loopCount = 0;
    currentPattern = currentPattern +1;
  }
}
