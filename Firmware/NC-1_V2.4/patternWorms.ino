double wormdeltaCol, wormCol0;
double wormdeltaRow, wormRow0;
int wormRow[10][10];
int wormCol[10][10]; //[number][length]
int wormLength, wormNumber;


void patternWorms(){
  
  int angle;  
  
  int numLoops = 96;

  //check if this is the first time through the pattern
  if (lastPattern != currentPattern){
    seed = 1;
  }
  if (seed == 1){
    wormNumber = mode;
    wormLength = mode2;
    for(int i = 0; i< 10; i++){
      wormCol[i][0]=int(random(numCols-1));
      wormRow[i][0]=int(random(numRows-1));
    }    
    seed = 0;
    lastPattern = currentPattern;      
  }
  wormNumber = mode;
    wormLength = mode2;
  for(int i = 0; i< wormNumber; i++){
      for(int j = wormLength - 1 ; j>=1 ; j--)  {
        wormCol[i][j] = wormCol[i][j-1];
        wormRow[i][j] = wormRow[i][j-1];
        WriteBit(wormCol[i][j], wormRow[i][j], "patternArray", 1);
      }
  }
  for(int i = 0; i< wormNumber; i++) {    
    do
    {
      angle = int(random(1,5));
      switch (angle)
      {
      case 1:
        wormdeltaCol = 1;
        wormdeltaRow = 0;
        break;
      case 2:
        wormdeltaCol = 0;
        wormdeltaRow = 1;
        break;
      case 3:
        wormdeltaCol = -1;
        wormdeltaRow = 0;
        break;
      case 4:
        wormdeltaCol = 0;
        wormdeltaRow = -1;
        break;
      case 5:
        wormdeltaCol = -1;
        wormdeltaRow = -1;
        break;
      case 6:
        wormdeltaCol = 1;
        wormdeltaRow = 1;
        break;
      default:
        wormdeltaCol = -1;
        wormdeltaRow = -1;
        break;
      }
      wormCol0=wormCol[i][0]+wormdeltaCol;
      wormRow0=wormRow[i][0]+wormdeltaRow;
      if (wormCol0 == numCols){
      wormCol0 = wormCol[i][0];
      }
      if (wormRow0 == numRows){
        wormRow0 = 0;
      }
      if (wormCol0 < 0){
        wormCol0 = numCols - 1;
      }
      if (wormRow0 < 0){
        wormRow0 = numRows - 1;
      } 
    } while (wormCol0 == wormCol[i][1] && wormRow0 == wormRow[i][1] || wormCol0 == wormCol[i][2] && wormRow0 == wormRow[i][2] || wormCol0 == wormCol[i][3] && wormRow0 == wormRow[i][3] || wormCol0 == wormCol[i][4] && wormRow0 == wormRow[i][4]); 
      wormCol[i][0]=wormCol0;
      wormRow[i][0]=wormRow0;
      WriteBit(wormCol[i][0], wormRow[i][0], "patternArray", 1);
  } 
  
 
  setOutputArray();
  // clear the current pattern array
  memset(patternArray,0,sizeof(patternArray)); 
  triggernow = 0;

}    
