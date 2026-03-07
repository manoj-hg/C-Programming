#include <stdio.h>
#include <string.h>

int main()
{
    int bt[50], wt[50], at[50], wat[50], ft[50], tat[50];
    int i, j, n, temp;
    float awt, att, sum = 0, sum1 = 0;
    char p[50][20], tempStr[20];

    printf("\n Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process name and burst-time:\n");
    for (i = 0; i < n; i++)
        scanf("%s%d", p[i], &bt[i]);

    printf("\nEnter the arrival-time:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                strcpy(tempStr, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], tempStr);
            }
        }
    }

    wt[0] = 0;
    ft[0] = at[0] + bt[0];

    for (i = 1; i < n; i++)
    {
        if (ft[i - 1] < at[i])
        {
            wt[i] = 0;
            ft[i] = at[i] + bt[i];
        }
        else
        {
            wt[i] = ft[i - 1] - at[i];
            ft[i] = ft[i - 1] + bt[i];
        }
    }

    printf("\n\n\t\t\tGANTT CHART\n\n");
    for (i = 0; i < n; i++)
        printf("|\t%s\t", p[i]);
    printf("|\n");

    printf("%d\t\t", at[0]);
    for (i = 1; i < n; i++)
        printf("%d\t\t", (ft[i - 1] > at[i]) ? ft[i - 1] : at[i]);
    printf("%d", ft[n - 1]);

    for (i = 0; i < n; i++)
        wat[i] = wt[i];

    for (i = 0; i < n; i++)
        tat[i] = ft[i] - at[i];

    printf("\n\n FIRST COME FIRST SERVE\n");
    printf("\n Process Burst-time Arrival-time Waiting-time Finish-time Turnaround time\n");

    for (i = 0; i < n; i++)
        printf("\n\n %d%s \t %d\t\t %d \t\t %d\t\t %d \t\t %d",
               i + 1, p[i], bt[i], at[i], wat[i], ft[i], tat[i]);

    for (i = 0; i < n; i++)
        sum += wat[i];
    awt = sum / n;

    for (i = 0; i < n; i++)
        sum1 += tat[i];
    att = sum1 / n;

    printf("\n\nAverage waiting time: %.2f", awt);
    printf("\nAverage turnaround time: %.2f\n", att);

    return 0;
}