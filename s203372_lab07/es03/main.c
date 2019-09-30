#include <stdio.h>
#include <stdlib.h>
int main(){
  int v[4] = {5,6,7,8}, q,w,e, somma;
  for (q = 0; q<4; q++)
    for (w = 0; w<4; w++)
        for (e = 0; e<4; somma = v[q]*100 + v[w]*10 + v[e],e++, (!(somma%7) ? printf("%d\n", somma):1));
        return 0;}
