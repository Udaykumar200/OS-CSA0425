#include <stdio.h>

#define MAX_PROCESS 10
#define MAX_MEMORY 100

struct Process {
    int id;
    int size;
};

struct MemoryBlock {
    int id;
    int size;
    int allocated;
};

void worstFit(struct Process processes[], int numProcesses, struct MemoryBlock memoryBlocks[], int numBlocks) {
    int i, j;
    for (i = 0; i < numProcesses; i++) {
        int worstIdx = -1;
        for (j = 0; j < numBlocks; j++) {
            if (memoryBlocks[j].allocated == 0 && memoryBlocks[j].size >= processes[i].size) {
                if (worstIdx == -1 || memoryBlocks[j].size > memoryBlocks[worstIdx].size) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            memoryBlocks[worstIdx].allocated = 1;
            memoryBlocks[worstIdx].id = processes[i].id;
        }
    }
}

void printMemoryBlocks(struct MemoryBlock memoryBlocks[], int numBlocks) {
    printf("\nMemory Blocks:\n");
    printf("Block ID\tBlock Size\tProcess ID\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("%d\t\t%d\t\t", memoryBlocks[i].id, memoryBlocks[i].size);
        if (memoryBlocks[i].allocated)
            printf("%d\n", memoryBlocks[i].id);
        else
            printf("Not allocated\n");
    }
}

int main() {
    struct Process processes[MAX_PROCESS];
    struct MemoryBlock memoryBlocks[MAX_MEMORY];
    int numProcesses, numBlocks;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    printf("Enter the details of each memory block:\n");
    for (int i = 0; i < numBlocks; i++) {
        memoryBlocks[i].id = i + 1;
        memoryBlocks[i].allocated = 0;
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &memoryBlocks[i].size);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the details of each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        processes[i].id = i + 1;
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &processes[i].size);
    }

    worstFit(processes, numProcesses, memoryBlocks, numBlocks);

    printMemoryBlocks(memoryBlocks, numBlocks);

    return 0;
}
