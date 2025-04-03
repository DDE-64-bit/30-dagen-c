#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secretFunction() {
    printf("Gefeliciteerd, je hebt de secretFunction bereikt!\n");
    system("/bin/sh");
}

void vulnerableFunction() {
    char buffer[64];
    printf("Voer wat in:\n");
    gets(buffer);
    printf("Je invoer was: %s\n", buffer);
}

int main() {
    vulnerableFunction();
    return 0;
}
