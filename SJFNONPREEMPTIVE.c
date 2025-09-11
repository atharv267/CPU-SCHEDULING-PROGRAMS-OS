#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[10], bt[10], ct[10], tat[10], wt[10], done[10] = {0};
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    int time = 0, completed = 0;
    while (completed < n) {
        int idx = -1, minBT = 9999;
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }
        if (idx == -1) time++;
        else {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done[idx] = 1;
            completed++;
        }
    }

    float avgWT = 0, avgTAT = 0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average WT = %.2f\nAverage TAT = %.2f\n", avgWT / n, avgTAT / n);
}
