#include <stdio.h>
#include <stdlib.h>

int main(){
    //int *pointer = (int*) malloc(20 * sizeof(int));

    // int *pointer = (int*) calloc(20, sizeof(int));

    // for (int i = 0; i < 20; i++){
    //     pointer[i] += i + 10;
    //     printf("%d ", pointer[i]);
    // }
    // printf("\n");

    // int *temp = (int*) realloc(pointer, 10 * sizeof(int));

    // if (temp == NULL){
    //     printf("Verkleinen mislukt ): \n");
    //     free(pointer);
    //     return 1;
    // }
    // pointer = temp;

    // for (int i = 0; i < 10; i++){
    //     printf("%d ", pointer[i]);
    // }
    // printf("\n");



    // int *temp1 = (int*) realloc(pointer, 20 * sizeof(int));

    // if (temp1 == NULL){
    //     printf("Vergroten mislukt ): \n");
    //     free(pointer);
    //     return 1;
    // }
    // pointer = temp1;

    // for (int i = 0; i < 20; i++){
    //     printf("%d ", pointer[i]);
    // }
    // printf("\n");

    // free(pointer);

    // return 0;



    // int *pointer = (int*) malloc(5 * sizeof(int));

    // for (int i = 0; i < 5; i++){
    //     pointer[i] = 8;
    //     printf("%d ", pointer[i]);
    // }
    // printf("\n");

    // for (int i = 0; i < 50; i++){
    //     printf("%d ", pointer[i]);
    // }
    // printf("\n");

    // free(pointer);

    // return 0;


    int *pointer = (int*) malloc(25 * sizeof(int));

    for (int i = 0; i < 25; i++){
        pointer[i] = i + 10;
        printf("%d ", pointer[i]);
    }
    printf("\n");

    free(pointer);

    return 0;    
}