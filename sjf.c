#include <stdio.h>

int main() {
    int n, i, j, pos;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], ct[n], p[n];

    // Input
    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // Sort by Burst Time (Simple SJF)
    for(i = 0; i < n-1; i++) {
        pos = i;
        for(j = i+1; j < n; j++) {
            if(bt[j] < bt[pos]) {
                pos = j;
            }
        }

        int temp;

        temp = bt[i]; bt[i] = bt[pos]; bt[pos] = temp;
        temp = at[i]; at[i] = at[pos]; at[pos] = temp;
        temp = p[i];  p[i]  = p[pos];  p[pos]  = temp;
    }

    // Waiting time
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        ct[i] = tat[i];
    }

    // Gantt Chart
    printf("\nGantt Chart:\n|");
    for(i = 0; i < n; i++) {
        printf(" P%d |", p[i]);
    }

    printf("\n0");
    for(i = 0; i < n; i++) {
        printf("   %d", ct[i]);
    }

    // Table
    printf("\n\nProcess\tAT\tBT\tWT\tTAT\n");

    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);

    return 0;
}