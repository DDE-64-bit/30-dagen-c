#include <stdio.h>
#include <ctype.h>

int main(){
    int key, ascii;
    char tekst[512];

    printf("key: ");
    scanf("%d", &key);
    
    getchar();

    printf("tekst: ");
    fgets(tekst, sizeof(tekst), stdin);

    for (int i = 0; tekst[i] != '\0'; i++){
        tekst[i] = toupper(tekst[i]);
        ascii = (int)tekst[i];

        if (ascii >= 65 && ascii <= 90){
            ascii += key;
            printf("%c", (char)ascii);
        }
    }
    
    printf("\n");

    return 0;
}