#include <stdio.h>
#include <stdlib.h>

struct Task {
    int id;
    int execution;
    int deadline;
    int period;
    int nextarrival;
    int remaining;
    int abs_deadline;
};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int findlcm(int a[], int n) {
    int res = a[0];
    for (int i = 1; i < n; i++) {
        res = (res * a[i]) / gcd(res, a[i]);
    }
    return res;
}

int main() {
    printf("SHREYA J G 1BM23CS352\n");
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    struct Task tasks[n];
    int periods[n];

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("Enter execution time, period, and deadline of task %d: ", i + 1);
        scanf("%d %d %d", &tasks[i].execution, &tasks[i].period, &tasks[i].deadline);
        tasks[i].nextarrival = 0;
        tasks[i].remaining = 0;
        tasks[i].abs_deadline = 0;
        periods[i] = tasks[i].period;
    }

    int lcm = findlcm(periods, n);
    printf("\nEDF Scheduling for %d time units:\n", lcm);

    for (int time = 0; time < lcm; time++) {
        // Check for arrivals
        for (int i = 0; i < n; i++) {
            if (time == tasks[i].nextarrival) {
                tasks[i].remaining = tasks[i].execution;
                tasks[i].abs_deadline = time + tasks[i].deadline;
                tasks[i].nextarrival += tasks[i].period;
            }
        }

        // Select task with earliest absolute deadline
        int min_deadline = 99999, selected = -1;
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0 && tasks[i].abs_deadline < min_deadline) {
                min_deadline = tasks[i].abs_deadline;
                selected = i;
            }
        }

        if (selected != -1) {
            printf("Time %2d: Task %d executing\n", time, tasks[selected].id);
            tasks[selected].remaining--;
        } else {
            printf("Time %2d: CPU Idle\n", time);
        }
    }

    return 0;
}
