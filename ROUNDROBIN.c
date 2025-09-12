#include <stdio.h>
int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int t = 0, c = 0;
    while (c < n) {
        int idle = 1;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= t) {
                idle = 0;
                if (rt[i] > tq) {
                    t += tq;
                    rt[i] -= tq;
                } else {
                    t += rt[i];
                    rt[i] = 0;
                    ct[i] = t;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    c++;
                }
            }
        }
        if (idle) t++;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);

    return 0;
}
