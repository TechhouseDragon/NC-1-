
/*
mode2.
patternDots() 
patternRectangle()
new pattern patternStarburst()
new patternMatrix()
new pattern
patternDots() - in reverse max size -> 0
patternRectangle() - in reverse maxsize -> 0
patternStarburst() - in revers
patternMatrix - in reverse
new pattern in reverse

*/
void pattern1(){
int pattern1numer = mode2 % 5 + 1;
  switch (pattern1numer)
  {
  case 2:
    patternDots();
    break;
  case 3:
    patternRectangle();
    break;
  case 4:
    patternStarburst();
    break;
  case 5:
    patternMatrix();
    break;
  case 1:
    patternSpirals();
    break;
  default:
    break;
  }
}    
