#include <stdio.h>
#define MAX_PROCESSES 10
struct Process
{
    int burstTime;
    int priority;
};
void sortProcesses(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority)
                {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}
void calculateWaitingTime(struct Process processes[], int n, int wt[]) {
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = processes[i - 1].burstTime + wt[i - 1];
    }
}
void calculateTurnaroundTime(struct Process processes[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = processes[i].burstTime + wt[i];
    }
}
void calculateAverageTime(struct Process processes[], int n) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    int total_wt = 0, total_tat = 0;
    calculateWaitingTime(processes, n, wt);
    calculateTurnaroundTime(processes, n, wt, tat);
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].burstTime, processes[i].priority, wt[i], tat[i]);
    }
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int n;
    struct Process processes[MAX_PROCESSES];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }
    sortProcesses(processes, n);
    calculateAverageTime(processes, n);
    return 0;
}
