#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Gebruik dit programma met 2 argumenten. \n");
        return 1;
    }

    char text = argv[1];

    // Schrijf een functie die een string in-place omkeert zonder extra geheugen te gebruiken.


    // h a l l o
    // 0 1 2 3 4
    // 
    // i =
    // 0: o a l l h | i & -1
    // 1: o l l a h | i & -2
    // 2: o l l a h | oneven dus middelste behouden

    for (int i = 0; i < sizeof(text) / 2; i++){
        
    }

    return 0;
}
