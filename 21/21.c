#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xorEncryptDecrypt(const char *inputFile, const char *outputFile, const char *key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");

    if (!inFile || !outFile) {
        printf("Kan bestand niet openen\n");
        exit(1);
    }

    int keyLen = strlen(key);
    int i = 0;
    char buffer;

    while (fread(&buffer, 1, 1, inFile) == 1) {
        buffer ^= key[i % keyLen];
        fwrite(&buffer, 1, 1, outFile);
        i++;
    }

    fclose(inFile);
    fclose(outFile);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Gebruik: %s <inputbestand> <outputbestand> <sleutel> <mode>\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *key = argv[3];
    const char *mode = argv[4];

    xorEncryptDecrypt(inputFile, outputFile, key);

    if (strcmp(mode, "decrypt") == 0) {
        printf("Bestand ontsleuteld\n");
    } else if (strcmp(mode, "encrypt") == 0) {
        printf("Bestand versleuteld\n");
    } else {
        printf("Ongeldige modus\n");
    }

    return 0;
}
