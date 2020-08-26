#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int *n1, int *n2){
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main (){
  int n1;
  int n2;
  scanf("%d", &n1);
  scanf("%d", &n2);
  swap(&n1, &n2);
  printf("%d", n1);
  printf(" ");
  printf("%d", n2);
  return 0;
}
