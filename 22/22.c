#include <stdio.h>
#include <string.h>

int main() {
    char input[50];
    char secretCode[] = "SuperSecret123";

    printf("Voer de geheime code in: ");
    scanf("%49s", input);

    if (strcmp(input, secretCode) == 0) {
        printf("Toegang geaccepteerd!\n");
    } else {
        printf("Foutieve code!\n");
    }
    return 0;
}
