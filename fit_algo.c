#include <stdio.h>
#include <stdbool.h>

typedef struct MemoryBlock {
    int id;
    int size;
    struct MemoryBlock* next;
} MemoryBlock;

MemoryBlock* memory = NULL;

// Function to initialize memory blocks
void initializeMemory(int numBlocks, int* blockIds, int* blockSizes) {
    memory = (MemoryBlock*)malloc(sizeof(MemoryBlock));
    memory->id = -1;
    memory->size = blockSizes[0];
    memory->next = NULL;
    MemoryBlock* current = memory;

    for (int i = 1; i < numBlocks; i++) {
        MemoryBlock* newBlock = (MemoryBlock*)malloc(sizeof(MemoryBlock));
        newBlock->id = -1;
        newBlock->size = blockSizes[i];
        newBlock->next = NULL;
        current->next = newBlock;
        current = newBlock;
    }
}

// Function to display the memory blocks
void displayMemory() {
    MemoryBlock* current = memory;
    while (current != NULL) {
        printf("Block ID: %d, Size: %d\n", current->id, current->size);
        current = current->next;
    }
}

// Function to simulate the Worst-fit allocation
MemoryBlock* worstFit(int requestedSize) {
    MemoryBlock* current = memory;
    MemoryBlock* worstFitBlock = NULL;
    int maxFreeSize = 0;

    while (current != NULL) {
        if (current->id == -1 && current->size >= requestedSize) {
            if (current->size > maxFreeSize) {
                maxFreeSize = current->size;
                worstFitBlock = current;
            }
        }
        current = current->next;
    }

    return worstFitBlock;
}

// Function to simulate the Best-fit allocation
MemoryBlock* bestFit(int requestedSize) {
    MemoryBlock* current = memory;
    MemoryBlock* bestFitBlock = NULL;
    int minFreeSize = 500 + 1; // Initialize to a large value

    while (current != NULL) {
        if (current->id == -1 && current->size >= requestedSize) {
            if (current->size < minFreeSize) {
                minFreeSize = current->size;
                bestFitBlock = current;
            }
        }
        current = current->next;
    }

    return bestFitBlock;
}

// Function to simulate the First-fit allocation
MemoryBlock* firstFit(int requestedSize) {
    MemoryBlock* current = memory;

    while (current != NULL) {
        if (current->id == -1 && current->size >= requestedSize) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to allocate memory
void allocateMemory(MemoryBlock* block, int id, int requestedSize) {
    if (block == NULL || block->size < requestedSize) {
        printf("Memory allocation failed for ID: %d with size: %d\n", id, requestedSize);
        return;
    }

    block->id = id;
    if (block->size > requestedSize) {
        MemoryBlock* newBlock = (MemoryBlock*)malloc(sizeof(MemoryBlock));
        newBlock->id = -1;
        newBlock->size = block->size - requestedSize;
        newBlock->next = block->next;
        block->next = newBlock;
    }
    block->size = requestedSize;

    printf("Memory allocated successfully for ID: %d with size: %d\n", id, requestedSize);
}

// Function to deallocate memory
void deallocateMemory(int id) {
    MemoryBlock* current = memory;

    while (current != NULL) {
        if (current->id == id) {
            current->id = -1;
            // Merge free blocks if possible
            if (current->next != NULL && current->next->id == -1) {
                current->size += current->next->size;
                MemoryBlock* temp = current->next;
                current->next = current->next->next;
                free(temp);
            }
            break;
        }
        current = current->next;
    }

    printf("Memory deallocated successfully for ID: %d\n", id);
}

int main() {
    int numBlocks;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    int* blockIds = (int*)malloc(numBlocks * sizeof(int));
    int* blockSizes = (int*)malloc(numBlocks * sizeof(int));

    for (int i = 0; i < numBlocks; i++) {
        printf("Enter the ID and size of block %d: ", i + 1);
        scanf("%d %d", &blockIds[i], &blockSizes[i]);
    }

    initializeMemory(numBlocks, blockIds, blockSizes);

    int choice;
    int id = 1;

    do {
        printf("\nMemory Allocation Techniques:\n");
        printf("1. Worst-fit\n");
        printf("2. Best-fit\n");
        printf("3. First-fit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int requestedSize;
        switch (choice) {
        case 1:
            printf("Enter the size you want to allocate: ");
            scanf("%d", &requestedSize);
            allocateMemory(worstFit(requestedSize), id++, requestedSize);
            break;
        case 2:
            printf("Enter the size you want to allocate: ");
            scanf("%d", &requestedSize);
            allocateMemory(bestFit(requestedSize), id++, requestedSize);
            break;
        case 3:
            printf("Enter the size you want to allocate: ");
            scanf("%d", &requestedSize);
            allocateMemory(firstFit(requestedSize), id++, requestedSize);
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\nCurrent Memory Status:\n");
        displayMemory();

    } while (choice != 4);

    free(blockIds);
    free(blockSizes);

    return 0;
}
