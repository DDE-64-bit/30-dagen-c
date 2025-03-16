#include <stdio.h>

int main(){
    FILE *bestand;
    char buffer[255];

    bestand = fopen("data.txt", "r");

    if (bestand == NULL){
        perror("Dit hoort niet te gebeuren ): \n");
        return 1;
    }

    //fprintf(bestand, "1234567890\n");

    for (int i = 0; i < 12; i++){
        fgets(buffer, sizeof(buffer), bestand);
        printf("%s", buffer);
    }

    fclose(bestand);

    return 0;
}
