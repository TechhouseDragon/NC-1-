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
        if(digitalRead(ColorModePin) == 0 && instrobe == 0){
        LEDChannels[k][r] = j*colourArray[col][row][r];
        LEDChannels[k][g] = j*colourArray[col][row][g];
        LEDChannels[k][b] = j*colourArray[col][row][b];
        }
        else{
        LEDChannels[k][r] = j*redintensity;
        LEDChannels[k][g] = j*greenintensity;
        LEDChannels[k][b] = j*blueintensity;
        }
      }
      if (row % 2){
        k =  (row+1)*numCols-col-1;
        j = glowArray[col][row]; 
        if(digitalRead(ColorModePin) == 0 && instrobe == 0){
        LEDChannels[k][r] = j*colourArray[col][row][r];
        LEDChannels[k][g] = j*colourArray[col][row][g];
        LEDChannels[k][b] = j*colourArray[col][row][b];
        }
        else{
        LEDChannels[k][r] = j*redintensity;
        LEDChannels[k][g] = j*greenintensity;
        LEDChannels[k][b] = j*blueintensity;
        }
      }      
    }
  }
  //  patternAllon();
    FastLED.show();
}
