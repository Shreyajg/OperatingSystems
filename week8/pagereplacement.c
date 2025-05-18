#include <stdio.h>

#define MAX 50

void fifo(int pages[], int n, int capacity) {
    int frame[MAX], i, j = 0, k, flag = 0, fault = 0;
    for (i = 0; i < capacity; i++) frame[i] = -1;

    printf("FIFO Page Replacement Process:\n");
    for (i = 0; i < n; i++) {
        flag = 0;
        for (k = 0; k < capacity; k++) {
            if (frame[k] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            frame[j] = pages[i];
            j = (j + 1) % capacity;
            fault++;
        }

        printf("PF No. %2d: ", i + 1);
        for (k = 0; k < capacity; k++) {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("FIFO Page Faults: %d\n\n", fault);
}

void lru(int pages[], int n, int capacity) {
    int frame[MAX], time[MAX], count = 0, i, j, k, fault = 0, least, pos;

    for (i = 0; i < capacity; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("LRU Page Replacement Process:\n");
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if (!found) {
            int min = time[0];
            pos = 0;
            for (j = 1; j < capacity; j++) {
                if (time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            count++;
            time[pos] = count;
            fault++;
        }

        printf("PF No. %2d: ", i + 1);
        for (k = 0; k < capacity; k++) {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("LRU Page Faults: %d\n\n", fault);
}

void optimal(int pages[], int n, int capacity) {
    int frame[MAX], i, j, k, fault = 0;

    for (i = 0; i < capacity; i++) frame[i] = -1;

    printf("Optimal Page Replacement Process:\n");
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int pos = -1, farthest = i + 1;
            for (j = 0; j < capacity; j++) {
                int found_next = 0;
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        found_next = 1;
                        break;
                    }
                }

                if (!found_next) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) pos = 0;

            frame[pos] = pages[i];
            fault++;
        }

        printf("PF No. %2d: ", i + 1);
        for (k = 0; k < capacity; k++) {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("Optimal Page Faults: %d\n\n", fault);
}

int main() {
    int capacity, n, pages[MAX];

    printf("Enter the number of Frames: ");
    scanf("%d", &capacity);

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    fifo(pages, n, capacity);
    lru(pages, n, capacity);
    optimal(pages, n, capacity);

    return 0;
}
