#include <stdio.h>

int main(){
    char string[64], spatieloos[64];
    int j = 0;

    printf("Invoer: ");
    fgets(string, sizeof(string), stdin);

    for (int i = 0; string[i] != '\0'; i++){
        if ((int)string[i] == 32){
            continue;
        }

        spatieloos[j] = string[i];
        j++;
    }
    spatieloos[j] = '\0';

    printf("%s \n", spatieloos);

    return 0;
}