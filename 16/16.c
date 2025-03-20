#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

void file_opening_error() {
    FILE *file = fopen("non_existent_file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        printf("Errno code: %d\n", errno);
    } else {
        fclose(file);
    }
}

void memory_allocation_error() {
    size_t huge_size = 1024 * 1024 * 1024 * 10L;
    int *ptr = malloc(huge_size);
    if (ptr == NULL) {
        perror("Memory allocation failed");
        printf("Errno code: %d\n", errno);
    }
}

void assertion_failure() {
    int a = 5;
    int b = 0;
    assert(b != 0);
    int result = a / b;
    printf("Result: %d\n", result);  
}

int main() {
    printf("Starting error testing...\n\n");

    printf("Testing file opening error:\n");
    file_opening_error();

    printf("\nTesting memory allocation error:\n");
    memory_allocation_error();

    printf("\nTesting assertion failure:\n");
    assertion_failure();

    return 0;
}
