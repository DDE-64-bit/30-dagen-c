#include <stdio.h>

int main(){
    char string[64];
    int key, ascii;

    printf("Invoer: ");
    fgets(string, sizeof(string), stdin);

    printf("Geef een key om te encrypten: ");
    scanf("%d", &key);

    for (int i = 0; string[i] != '\0'; i++){
        string[i] = (int)string[i] + key;
    }

    printf("%s \n", string);

    return 0;
}