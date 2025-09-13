#include <stdio.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[10], bt[10], pr[10], rt[10], ct[10], tat[10], wt[10];
    printf("Enter AT, BT, and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    int t = 0, c = 0;
    while (c < n) {
        int idx = -1, best = 9999;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= t && pr[i] < best) {
                best = pr[i];
                idx = i;
            }
        }
        if (idx == -1) { t++; continue; }
        rt[idx]--; t++;
        if (rt[idx] == 0) {
            ct[idx] = t;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            c++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);

    return 0;
}
