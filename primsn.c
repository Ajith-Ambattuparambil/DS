#include <stdio.h>
#define INF 999
int cost[10][10], visited[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, min;
int n, no_edges = 0, total_cost = 0;
int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost Adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = INF;
            }
        }
    }
    visited[1] = 1;
    printf("The edges of Minimum Cost Spanning Tree are :\n ");
    while (no_edges < n - 1)
    {
        min = INF;
        int a = 0;
        int b = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (visited[j] == 0 && cost[i][j] != INF)
                    {
                        if (cost[i][j] < min)
                        {
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }
        no_edges++;
        visited[b] = 1;
        printf("%d--%d : %d\n", a, b, min);
        total_cost = total_cost + min;
    }
    printf("Total cost: %d", total_cost);
}