#include<stdio.h>
#include<stdlib.h>

#define Max 10

int blockSize[Max], processSize[Max];

void firstfit(int n, int m) {
    int blockAllocated[Max], used[Max] = {0};

    for(int i = 0; i < m; i++) {
        blockAllocated[i] = -1;
        for(int j = 0; j < n; j++) {
            if(!used[j] && processSize[i] <= blockSize[j]) {
                blockAllocated[i] = j;
                used[j] = 1;
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock Allocated\n");
    for(int i = 0; i < m; i++) {
        if(blockAllocated[i] != -1)
            printf("P%d\t%d\tBlock %d\n", i, processSize[i], blockAllocated[i]);
        else
            printf("P%d\t%d\tNot Allocated\n", i, processSize[i]);
    }
}

void bestfit(int n, int m) {
    int blockAllocated[Max], used[Max] = {0};
    int originalIndex[Max];

    for(int i = 0; i < n; i++)
        originalIndex[i] = i;

    // Sort blocks in ascending order
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(blockSize[j] > blockSize[j+1]) {
                int temp = blockSize[j];
                blockSize[j] = blockSize[j+1];
                blockSize[j+1] = temp;

                int tempIndex = originalIndex[j];
                originalIndex[j] = originalIndex[j+1];
                originalIndex[j+1] = tempIndex;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        blockAllocated[i] = -1;
        for(int j = 0; j < n; j++) {
            if(!used[j] && processSize[i] <= blockSize[j]) {
                blockAllocated[i] = originalIndex[j];
                used[j] = 1;
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock Allocated\n");
    for(int i = 0; i < m; i++) {
        if(blockAllocated[i] != -1)
            printf("P%d\t%d\tBlock %d\n", i, processSize[i], blockAllocated[i]);
        else
            printf("P%d\t%d\tNot Allocated\n", i, processSize[i]);
    }
}

void worstfit(int n, int m) {
    int blockAllocated[Max], used[Max] = {0};
    int originalIndex[Max];

    for(int i = 0; i < n; i++)
        originalIndex[i] = i;

    // Sort blocks in descending order
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(blockSize[j] < blockSize[j+1]) {
                int temp = blockSize[j];
                blockSize[j] = blockSize[j+1];
                blockSize[j+1] = temp;

                int tempIndex = originalIndex[j];
                originalIndex[j] = originalIndex[j+1];
                originalIndex[j+1] = tempIndex;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        blockAllocated[i] = -1;
        for(int j = 0; j < n; j++) {
            if(!used[j] && processSize[i] <= blockSize[j]) {
                blockAllocated[i] = originalIndex[j];
                used[j] = 1;
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock Allocated\n");
    for(int i = 0; i < m; i++) {
        if(blockAllocated[i] != -1)
            printf("P%d\t%d\tBlock %d\n", i, processSize[i], blockAllocated[i]);
        else
            printf("P%d\t%d\tNot Allocated\n", i, processSize[i]);
    }
}

int main() {
    int n, m, c;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);

    printf("Enter the number of processes: ");
    scanf("%d", &m);

    printf("Enter the sizes of the memory blocks:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the sizes of the processes:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &processSize[i]);
    }

    while(1) {
        printf("\nChoose memory allocation strategy:\n");
        printf("1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit\nChoice: ");
        scanf("%d", &c);

        // Reset block sizes each time to original state
        int originalBlockSize[Max];
        for(int i = 0; i < n; i++)
            originalBlockSize[i] = blockSize[i];

        switch(c) {
            case 1:
                firstfit(n, m);
                break;
            case 2:
                bestfit(n, m);
                break;
            case 3:
                worstfit(n, m);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }

        // Restore original block sizes
        for(int i = 0; i < n; i++)
            blockSize[i] = originalBlockSize[i];
    }

    return 0;
}
