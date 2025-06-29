#include <stdio.h>
#include <stdlib.h>

int main() {
int vetor[5] = {1, 2, 3, 4, 5};
int *pv;
for(pv = vetor; pv < vetor + 5; pv++) {
printf("%d ", *pv);
}
getchar();
return 0;
}