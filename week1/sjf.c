#include<stdio.h>
#define Max 10

int p[Max], at[Max], bt[Max], ct[Max], tat[Max], wt[Max];
int is_completed[Max] = {0};

int main() {
    int n;
    printf("SHREYA J G 1BM23CS352\n");
    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter arrival time for process %d: ", i);
        scanf("%d", &at[i]);
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &bt[i]);
    }

    int completed = 0, current_time = 0;
    float total_wt = 0, total_tat = 0;

    while(completed < n) {
        int idx = -1;
        int min_bt = 1e9;

        for(int i = 0; i < n; i++) {
            if(at[i] <= current_time && is_completed[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
                if(bt[i] == min_bt) {  // Tie breaker: earlier arrival
                    if(at[i] < at[idx])
                        idx = i;
                }
            }
        }

        if(idx != -1) {
            ct[idx] = current_time + bt[idx];
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            total_wt += wt[idx];
            total_tat += tat[idx];
            is_completed[idx] = 1;
            completed++;
            current_time = ct[idx];
        } else {
            current_time++; // No process available, increment time
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
