#include <stdio.h>
#include <stdlib.h>

int main(){
    char command[64];
    char exitCommand[] = "exit";

    while (1){
        printf("$ ");
        fgets(command, sizeof(command), stdin);

        for (int i = 0; exitCommand[i] != '\0'; i++){
            if (command[i] != exitCommand[i]){
                //printf("Geen exit \n");
                break;
            }
            else{
                return 0;
            }
        }

        system(command);
    }

    return 0;
}