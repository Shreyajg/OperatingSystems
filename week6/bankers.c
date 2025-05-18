#include <stdio.h>
#define Max 10

int allocated[Max][Max], maximum[Max][Max], available[Max];
int need[Max][Max], safe[Max];

int main() {
    int n, m;

    printf("SHREYA J G 1BM23CS352\n");
    printf("Enter the number of processes and resources:\n");
    scanf("%d%d", &n, &m);

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &allocated[i][j]);

    printf("Enter the Maximum Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &maximum[i][j]);

    printf("Enter the Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &available[i]);

    // Calculate Need Matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocated[i][j];

    int finished[Max] = {0};
    int k = 0;

    while (k < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (!finished[i]) {
                int can_allocate = 1;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        can_allocate = 0;
                        break;
                    }
                }

                if (can_allocate) {
                    for (int j = 0; j < m; j++)
                        available[j] += allocated[i][j];

                    safe[k++] = i;
                    finished[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("The system is not in a safe state.\n");
            return 0;
        }
    }

    // If system is in a safe state
    printf("The system is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", safe[i]);
        if (i != n - 1) printf(" -> ");
    }
    printf("\n");

    return 0;
}
