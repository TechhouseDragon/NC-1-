
/*
patternDiamond2() + patternBox2()
mode1
1 patternDiamond2()
2 patternBox2()

mode2
pixel skip?
shrink?
rotate?


*/
void pattern2(){
int pattern1numer = mode % 2 + 1;
  switch (pattern1numer)
  {
  case 2:
    patternDiamond();
    break;
  case 1:
    patternBox();
    break;
  default:
    break;
  }
}    
