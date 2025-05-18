#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
} Process;

// Function to implement FCFS scheduling
void fcfsScheduling(Process queue[], int n) {
    int waiting_time = 0, turnaround_time = 0, completion_time = 0;
    int total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");

    for (int i = 0; i < n; i++) {
        if (completion_time < queue[i].arrival) {
            completion_time = queue[i].arrival;
        }
        completion_time += queue[i].burst;
        int turnaround = completion_time - queue[i].arrival;
        int waiting = turnaround - queue[i].burst;

        // Accumulate waiting time and turnaround time for average calculation
        total_turnaround_time += turnaround;
        total_waiting_time += waiting;

        // Print details of each process
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", queue[i].pid, queue[i].arrival, queue[i].burst,
               completion_time, turnaround, waiting);
    }

    // Calculate and display average waiting time and average turnaround time
    if (n > 0) {
        float avg_waiting_time = (float)total_waiting_time / n;
        float avg_turnaround_time = (float)total_turnaround_time / n;

        printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
        printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    }
}

// Function to perform multi-level queue scheduling
void multiLevelQueueScheduling(Process systemQueue[], int sysCount, Process userQueue[], int userCount) {
    printf("\nExecuting System Processes (Higher Priority):\n");
    fcfsScheduling(systemQueue, sysCount);

    printf("\nExecuting User Processes (Lower Priority):\n");
    fcfsScheduling(userQueue, userCount);
}

int main() {
    int n, sysCount = 0, userCount = 0;
    Process systemQueue[MAX_PROCESSES], userQueue[MAX_PROCESSES];
    printf("Shreya JG 1BM2E3CS352\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Process p;
        int type;
        printf("\nEnter details for process %d\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &p.pid);
        printf("Arrival Time: ");
        scanf("%d", &p.arrival);
        printf("Burst Time: ");
        scanf("%d", &p.burst);
        printf("Enter process type (1 - System, 2 - User): ");
        scanf("%d", &type);

        if (type == 1) {
            systemQueue[sysCount++] = p;
        } else {
            userQueue[userCount++] = p;
        }
    }

    multiLevelQueueScheduling(systemQueue, sysCount, userQueue, userCount);

    return 0;
}