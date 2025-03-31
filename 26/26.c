#include <stdio.h>
#include <stdlib.h>
#include <capstone/capstone.h>

void disassemble(const uint8_t *code, size_t codeSize, uint64_t address) {
    csh handle;
    cs_insn *insn;
    size_t count;

    if (cs_open(CS_ARCH_X86, CS_MODE_32, &handle) != CS_ERR_OK) {
        printf("Fout bij openen van Capstone\n");
        return;
    }

    count = cs_disasm(handle, code, codeSize, address, 0, &insn);
    if (count > 0) {
        for (size_t i = 0; i < count; i++) {
            printf("0x%"PRIx64":\t%s\t%s\n", insn[i].address, insn[i].mnemonic, insn[i].op_str);
        }
        cs_free(insn, count);
    } else {
        printf("Kon niet disassembleren\n");
    }

    cs_close(&handle);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Gebruik: %s <bestand>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Fout bij openen van bestand");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    uint8_t *buffer = malloc(fileSize);
    if (!buffer) {
        perror("Memory allocatie faalde");
        fclose(file);
        return 1;
    }

    fread(buffer, 1, fileSize, file);
    fclose(file);

    disassemble(buffer, fileSize, 0x1000);
    free(buffer);
    return 0;
}
