void WriteLEDArray() {
  //Get the current colour input

  setcolour();
  setglow();
  setmode();

  //Transform Frame Intensity Array to LED Linear Array
  for (row = 0; row < numRows; row++){
    for (col = 0; col < numCols; col++ ){
      if ((row % 2) == 0){
        k = row*numCols + col;
        j = glowArray[col][row];   
        LEDChannels[k][r] = j*redintensity;
        LEDChannels[k][g] = j*greenintensity;
        LEDChannels[k][b] = j*blueintensity;
      }
      if (row % 2){
        k =  (row+1)*numCols-col-1;
        j = glowArray[col][row]; 
        LEDChannels[k][r] = j*redintensity;
        LEDChannels[k][g] = j*greenintensity;
        LEDChannels[k][b] = j*blueintensity;
      }
    }
  }
  //  patternAllon();
    FastLED.show();
}
