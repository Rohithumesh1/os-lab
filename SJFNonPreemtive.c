 #include <stdio.h>

// Function to calculate the turnaround time and waiting time using SJF (Non-preemptive) algorithm
void sjf_nonpreemptive(int processes[], int burst_time[], int n) {
    int waiting_time[n], turnaround_time[n], completion_time[n];
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Sorting the processes based on burst time in ascending order using selection sort
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[min_idx])
                min_idx = j;
        }
        int temp = burst_time[i];
        burst_time[i] = burst_time[min_idx];
        burst_time[min_idx] = temp;

        temp = processes[i];
        processes[i] = processes[min_idx];
        processes[min_idx] = temp;
    }

    // Calculating completion time, waiting time, and turnaround time for each process
    for (int i = 0; i < n; i++) {
        if (i == 0)
            completion_time[i] = burst_time[i];
        else
            completion_time[i] = completion_time[i - 1] + burst_time[i];

        turnaround_time[i] = completion_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];

        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Printing the process details and average waiting time and turnaround time
    printf("\nSJF (Non-preemptive) Scheduling Algorithm:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}


int main() {
    int n, choice;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];
    int priority[n];

    printf("\nEnter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i]=(i+1);
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
    }
     sjf_nonpreemptive(processes, burst_time, n);

    return 0;
}
