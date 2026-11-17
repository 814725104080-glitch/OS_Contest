#include <stdio.h>

int main(void)
{
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0}, safe[10];
    int count = 0, found;

    printf("Enter number of processes (max 10): ");
    scanf("%d", &n);

    printf("Enter number of resource types (max 10): ");
    scanf("%d", &m);

    if (n < 1 || n > 10 || m < 1 || m > 10) {
        printf("Invalid number of processes or resources.\\n");
        return 1;
    }

    printf("\\nEnter Allocation Matrix (%d x %d):\\n", n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\\nEnter Maximum Matrix (%d x %d):\\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            if (max[i][j] < alloc[i][j]) {
                printf("Invalid input: maximum cannot be less than allocation.\\n");
                return 1;
            }
        }
    }

    printf("\\nEnter Available Resources (%d values):\\n", m);
    for (j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    /* Calculate Need = Maximum - Allocation */
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    /* Banker's safety algorithm */
    while (count < n) {
        found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }

                if (j == m) {
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
            break;
    }

    if (count == n) {
        printf("\\nSystem is in a SAFE state.\\n");
        printf("Safe sequence: ");
        for (i = 0; i < n; i++) {
            printf("P%d", safe[i]);
            if (i < n - 1)
                printf(" -> ");
        }
        printf("\\n");
    } else {
        printf("\\nSystem is in an UNSAFE state.\\n");
        printf("No safe sequence exists.\\n");
    }

    return 0;
}
