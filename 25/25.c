#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

void printElfInfo(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Fout bij openen van bestand");
        return;
    }

    Elf64_Ehdr elfHeader;

    if (fread(&elfHeader, 1, sizeof(elfHeader), file) != sizeof(elfHeader)) {
        perror("Fout bij lezen van ELF-header");
        fclose(file);
        return;
    }

    if (elfHeader.e_ident[EI_MAG0] != ELFMAG0 ||
        elfHeader.e_ident[EI_MAG1] != ELFMAG1 ||
        elfHeader.e_ident[EI_MAG2] != ELFMAG2 ||
        elfHeader.e_ident[EI_MAG3] != ELFMAG3) {
        printf("Geen geldig ELF-bestand\n");
        fclose(file);
        return;
    }

    printf("Geldig ELF-bestand\n");
    printf("Class: %s-bit\n", elfHeader.e_ident[EI_CLASS] == ELFCLASS64 ? "64" : "32");
    printf("Endian: %s\n", elfHeader.e_ident[EI_DATA] == ELFDATA2LSB ? "Little Endian" : "Big Endian");
    printf("Type: ");
    switch (elfHeader.e_type) {
        case ET_EXEC: printf("Executable\n"); break;
        case ET_DYN: printf("Shared Object\n"); break;
        case ET_REL: printf("Relocatable\n"); break;
        default: printf("Onbekend (%x)\n", elfHeader.e_type); break;
    }

    printf("Machine: ");
    switch (elfHeader.e_machine) {
        case EM_X86_64: printf("x86-64\n"); break;
        case EM_386: printf("x86\n"); break;
        case EM_ARM: printf("ARM\n"); break;
        case EM_AARCH64: printf("AArch64\n"); break;
        default: printf("Onbekend (%x)\n", elfHeader.e_machine); break;
    }

    printf("Entrypoint: 0x%lx\n", elfHeader.e_entry);

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Gebruik: %s <elf-bestand>\n", argv[0]);
        return 1;
    }

    printElfInfo(argv[1]);
    return 0;
}
