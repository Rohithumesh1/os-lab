#include <stdio.h>
#define MAX_PROCESSES 10
void calculateWaitingTime(int bt[], int n, int quantum, int wt[]) {
    int rem_bt[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }
    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) {
            break;
        }
    }
}
int main() {
    int n;
    int bt[MAX_PROCESSES];
    int wt[MAX_PROCESSES];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    calculateWaitingTime(bt, n, quantum, wt);
    printf("\nProcess\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, bt[i], wt[i]);
    }
    return 0;
}
