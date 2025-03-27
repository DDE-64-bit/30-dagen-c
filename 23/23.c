#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define HEAP_SIZE 1024 * 1024

static char heap[HEAP_SIZE];
static char *heapEnd = heap;

struct block {
    size_t size;
    int free;
    struct block *next;
};

#define BLOCK_SIZE sizeof(struct block)

static struct block *freeList = NULL;

void *mallocCustom(size_t size) {
    if (size <= 0 || size + BLOCK_SIZE > HEAP_SIZE) return NULL;

    struct block *current = freeList;
    struct block *previous = NULL;

    while (current) {
        if (current->free && current->size >= size) {
            current->free = 0;
            return (void*)((char*)current + BLOCK_SIZE);
        }
        previous = current;
        current = current->next;
    }

    if ((heapEnd + size + BLOCK_SIZE) > (heap + HEAP_SIZE)) return NULL;

    struct block *newBlock = (struct block*)heapEnd;
    newBlock->size = size;
    newBlock->free = 0;
    newBlock->next = NULL;

    if (previous) previous->next = newBlock;
    else freeList = newBlock;

    heapEnd += size + BLOCK_SIZE;

    return (void*)((char*)newBlock + BLOCK_SIZE);
}

void freeCustom(void *ptr) {
    if (!ptr) return;

    struct block *blockPtr = (struct block*)((char*)ptr - BLOCK_SIZE);
    blockPtr->free = 1;
}

int main() {
    char *ptr1 = (char*)mallocCustom(100);
    strcpy(ptr1, "Hallo, wereld!");
    printf("Gealloceerd geheugen zegt: %s\n", ptr1);

    freeCustom(ptr1);

    char *ptr2 = (char*)mallocCustom(200);
    if (ptr2) {
        printf("Nieuwe allocatie na vrijgeven succesvol.\n");
    }

    return 0;
}