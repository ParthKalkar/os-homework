#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++){
        int k;
        for (k = 0; k < n - i; k++){
            printf("%c", ' ');
        }
        for (k = 0; k < 2 * i - 1; k++){
            printf("%c", '*');
        }
        for (k = 0; k < n - i; k++){
            printf("%c", ' ');
        }
        printf("\n");
    }
}
