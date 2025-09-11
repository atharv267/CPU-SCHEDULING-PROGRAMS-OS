#include <stdio.h>

int main() {
    int n, at[10], bt[10], ct[10], tat[10], wt[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &at[i], &bt[i]);

    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t < at[i]) t = at[i];
        t += bt[i];
        ct[i] = t;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    return 0;
}
