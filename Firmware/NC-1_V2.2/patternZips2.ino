const int numRowsZips2 = numRows+1;
const int numColsZips2 = numCols+1;

void patternZips2(){
  int frameloops = 16;
  int numLoops = 16;

    if (lastPattern != currentPattern){
    seed = 1;
  }
  //seed the pattern with a pixel
  if (seed == 1){
//    frameloops = NumLEDs/2;
    for (i=0;i<numSeeds;i++){
      pixelSeed[i]=1;
    }
    seed = 0;
    lastPattern = currentPattern;
    frameStep = 0;
    loopCount = 0;
  }

//SET SHIFT DIRECTIONS
  switch(mode){
    case 1:
      pixelDir[0] = 1;
      frameloops = numCols;
      break;
    case 2:
      pixelDir[0] = 3;
      frameloops = numCols;
      break;
    case 3:
      pixelDir[0] = random(1,3)*2;
      frameloops = numRows;
      break;
    case 4:
      pixelDir[0] = random(1,5);
      frameloops = numRows;
      break;
  }

//PLACE SEED PIXELS
  for(i=0;i<numSeeds;i++){
    if (pixelSeed[i] == 1){
      switch(pixelDir[0]){
      case 1:
      if(i == numCols/mode2){
        pixelRow[i] = random(numRows);
        pixelCol[i] = 0;
        pixelSeed[i]=0;
        pixelStep[i] = 1;
      }
      break;  
      case 2:  
        pixelRow[i] = 0;
        pixelCol[i] = random(numCols);
        pixelSeed[i]=0;
        pixelStep[i] = 1;
      break;
      case 3:
        pixelRow[i] = random(numRows);
        pixelCol[i] = numCols-1;
        pixelSeed[i]=0;
        pixelStep[i] = 1;
      break;
      case 4:
        pixelRow[i] = numRows-1;
        pixelCol[i] = random(numCols);
        pixelSeed[i]=0;
        pixelStep[i] = 1;
      break;
      }
    
    }
  }
 
  //place the pixel in the frame array  
  for(i=0;i<mode2;i++){  
    WriteBit(pixelCol[i], pixelRow[i], "patternArray", 1);
  }

setOutputArray();
memset(patternArray,0,sizeof(patternArray)); 

  //PUSH PIXEL
  for(i=0;i<numSeeds;i++){
  dir = pixelDir[i];
  setshift();
  pixelCol[i] = pixelCol[i] + colShift;
  pixelRow[i] = pixelRow[i] + rowShift;
  pixelStep[i] = pixelStep[i] + 1;

  if ((pixelDir[0]%2 != 0) && (pixelStep[i] > (numColsZips))){
    pixelSeed[i] = 1;
  }
  if ((pixelDir[0]%2 == 0) && (pixelStep[i] > (numRowsZips))){
    pixelSeed[i] = 1;
  }
  }
  
// END PUSH

  triggernow = 0;
  
  frameStep++;

if (frameStep >= frameloops){ 
    frameStep = 0;
    loopCount = loopCount +1; 
}

  if (loopCount >= numLoops){
   loopCount = 0;
  }
}
