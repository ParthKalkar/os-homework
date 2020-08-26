#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;
    printf("i is: %d", a);
    printf(", and size of i is: %lu", sizeof(a));
    printf("\nf is: %f", b);
    printf(", and size of f is: %lu", sizeof(b));
    printf("\nd is: %lf", c);
    printf(", and size of d is: %lu", sizeof(c));
    return 0;
}
