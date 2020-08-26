#include <stdio.h>
#include <string.h>

int main() {
    char string[1000];
    char newstring[1000];
    fgets(string, sizeof(string), stdin);
    for (int i = 0; i < strlen(string); i++){
        newstring[i] = string[strlen(string) - 1 - i];
    }
    printf(newstring);
    return 0;
}
