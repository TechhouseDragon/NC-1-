double deltaCol;
double deltaRow;
int worm1Row[numRows];
int worm1Col[numCols];
int worm2Row[numRows];
int worm2Col[numCols];
int worm3Row[numRows];
int worm3Col[numCols];
int worm4Row[numRows];
int worm4Col[numCols];

void patternWorms(){
  int a;
  float angle;
  int currentCol;
  int currentRow;
  int wormlength = 4;
  int numLoops = 96;

  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }
  if (seed == 1){
    worm1Col[0]=int(random(numCols));
    worm1Row[0]=int(random(numRows));
    worm2Col[0]=int(random(numCols));
    worm2Row[0]=int(random(numRows));
    worm3Col[0]=int(random(numCols));
    worm3Row[0]=int(random(numRows));
    worm4Col[0]=int(random(numCols));
    worm4Row[0]=int(random(numRows));
    seed = 0;
    lastPattern = currentPattern;  
    
  }

  for (i = 0; i<wormlength; i++){
     bitWrite(patternArray[divi(worm1Col[i],  worm1Row[i],patternCols )], modi(worm1Col[i],  worm1Row[i], patternCols), 1);
    //patternArray[worm1Col[i]][worm1Row[i]] = 1;
  }

  if (mode > 1){
    for (i = 0; i<wormlength; i++){
       bitWrite(patternArray[divi(worm2Col[i],  worm2Row[i],patternCols )], modi(worm2Col[i],  worm2Row[i], patternCols), 1);
   //   patternArray[worm2Col[i]][worm2Row[i]] = 1;
    }    
  }
  if (mode > 2){
    for (i = 0; i<wormlength; i++){
       bitWrite(patternArray[divi(worm3Col[i],  worm3Row[i],patternCols )], modi(worm3Col[i],  worm3Row[i], patternCols), 1);
     // patternArray[worm3Col[i]][worm3Row[i]] = 1;
    }    
  }
    if (mode > 3){
    for (i = 0; i<wormlength; i++){
       bitWrite(patternArray[divi(worm4Col[i],  worm4Row[i],patternCols )], modi(worm4Col[i],  worm4Row[i], patternCols), 1);
     // patternArray[worm4Col[i]][worm4Row[i]] = 1;
    }    
  }
  //LAY THE PATTERN ARRAY OVER THE LED ARRAY
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){
      bitWrite(LEDArray[divi(col,  row, numCols)], modi(col, row, numCols), bitRead(patternArray[divi(col,  row, patternCols)],modi(col, row, patternCols)));
      //LEDArray[col][row] = patternArray[col][row];
    }
  }

  //update glowArray & colourArray
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++){      
      glowArray[col][row] = glowArray[col][row]*glow ;            
      glowArray[col][row] = glowArray[col][row]+bitRead(LEDArray[divi(col,  row, numCols)], modi(col, row, numCols));

      constrain(glowArray[col][row], 0, 1);
      if (bitRead(LEDArray[divi(col,  row, numCols)],  modi(col, row, numCols)) == 1 ){
        colourArray[col][row] [r] = redintensity;
        colourArray[col][row] [g] = greenintensity;
        colourArray[col][row] [b] = blueintensity;
      }
    }
  }

  // clear the current pattern array
  memset(patternArray,0,sizeof(patternArray)); 
  triggernow = 0;

  //worm1

    for (i = 0; i<wormlength; i++){
  worm1Col[i+1] = worm1Col[i];
  worm1Row[i+1] = worm1Row[i];
    } 
    
  angle = random(360) * PI /180;
  deltaCol = sin(angle)+0.5;
  deltaRow = cos(angle)+0.5;
  newCol = worm1Col[0] + deltaCol;
  newRow = worm1Row[0] + deltaRow; 

  if (newCol == worm1Col[1]){    
    newCol = worm1Col[0];
  }
  if (newRow == worm1Row[1]){
    newRow = worm1Row[0];
  }
  if (newCol == numCols){
    newCol = newCol-2;
  }
  if (newRow == numRows){
    newRow = newRow-2;
  }
  if (newCol < 0){
    newCol = newCol+2;
  }
  if (newRow < 0){
    newRow = newRow+2;
  }  
  worm1Col[0] = newCol;
  worm1Row[0] = newRow;
  //end - worm1

  //worm2
    for (i = 0; i<wormlength; i++){
  worm2Col[i+1] = worm2Col[i];
  worm2Row[i+1] = worm2Row[i];
    } 
    
  angle = random(360) * PI /180;
  deltaCol = sin(angle)+0.5;
  deltaRow = cos(angle)+0.5;
  newCol = worm2Col[0] + deltaCol;
  newRow = worm2Row[0] + deltaRow; 

  if (newCol == worm2Col[1]){    
    newCol = worm2Col[0];
  }
  if (newRow == worm2Row[1]){
    newRow = worm2Row[0];
  }
  if (newCol == numCols){
    newCol = newCol-2;
  }
  if (newRow == numRows){
    newRow = newRow-2;
  }
  if (newCol < 0){
    newCol = newCol+2;
  }
  if (newRow < 0){
    newRow = newRow+2;
  }   
  worm2Col[0] = newCol;
  worm2Row[0] = newRow;
  //end - worm2

  //worm3
    for (i = 0; i<wormlength; i++){
  worm3Col[i+1] = worm3Col[i];
  worm3Row[i+1] = worm3Row[i];
    } 
    
  angle = random(360) * PI /180;
  deltaCol = sin(angle)+0.5;
  deltaRow = cos(angle)+0.5;
  newCol = worm3Col[0] + deltaCol;
  newRow = worm3Row[0] + deltaRow; 

  if (newCol == worm3Col[1]){    
    newCol = worm3Col[0];
  }
  if (newRow == worm3Row[1]){
    newRow = worm3Row[0];
  }
  if (newCol == numCols){
    newCol = newCol-2;
  }
  if (newRow == numRows){
    newRow = newRow-2;
  }
  if (newCol < 0){
    newCol = newCol+2;
  }
  if (newRow < 0){
    newRow = newRow+2;
  }   
  worm3Col[0] = newCol;
  worm3Row[0] = newRow;
  //end - worm3
  
    //worm4
    for (i = 0; i<wormlength; i++){
  worm4Col[i+1] = worm4Col[i];
  worm4Row[i+1] = worm4Row[i];
    } 
    
  angle = random(360) * PI /180;
  deltaCol = sin(angle)+0.5;
  deltaRow = cos(angle)+0.5;
  newCol = worm4Col[0] + deltaCol;
  newRow = worm4Row[0] + deltaRow; 

  if (newCol == worm4Col[1]){    
    newCol = worm4Col[0];
  }
  if (newRow == worm4Row[1]){
    newRow = worm4Row[0];
  }
  if (newCol == numCols){
    newCol = newCol-2;
  }
  if (newRow == numRows){
    newRow = newRow-2;
  }
  if (newCol < 0){
    newCol = newCol+2;
  }
  if (newRow < 0){
    newRow = newRow+2;
  }   
  worm4Col[0] = newCol;
  worm4Row[0] = newRow;
  //end - worm4
  
//  if (loopCount > numLoops){
//    loopCount = 0;
//    currentPattern = currentPattern +1; 
//  }
  loopCount = loopCount +1;
}    
