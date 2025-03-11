#include <stdio.h>

int main(){
    char wachtwoord[50];
    
    printf("Wachtwoord: ");
    fgets(wachtwoord, sizeof(wachtwoord), stdin);

    int counter[3] = {0};

    // tekens, cijfer, hoofdletter, '\0'
    // 0       1       2            3

    int ascii;

    for (int i = 0; wachtwoord[i] != '\n'; i++){
        ascii = (int)wachtwoord[i];
        //printf("%d ", ascii);
        if (ascii >= 65 && ascii <= 90){
            counter[2]++;
            counter[0]++;
        }
        else if (ascii >= 97 && ascii <= 122){
            counter[0]++;
        }
        else if (ascii >= 48 && ascii <= 57){
            counter[0]++;
            counter[1]++;
        }
    }
    //printf("\n");

    if (counter[0] >= 8 && counter[1] >= 1 && counter[2] >= 1){
        printf("Wachtwoord veilig!! \n");
    }
    else{
        printf("Wachtwoord is nog niet veilig genoeg ): \n");
    }

    return 0;
}