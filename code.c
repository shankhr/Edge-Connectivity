#include <stdio.h>
#include <stdlib.h>
int source, V, E, visited[20], G[20][20];
int connectivity()
{
    int check = 1;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            check = 0;
            break;
        }
    }
    return check;
}
void DFS(int i)
{
    int j;
    visited[i] = 1;
    for (j = 0; j < V; j++)
    {
        if (G[i][j] == 1 && visited[j] == 0)
            DFS(j);
    }
}
int main()
{
    int i, j, k, v1, v2, flag;
    printf("Enter the no of vertices:");
    scanf("%d", &V);
    printf("Enter the no of edges:");
    scanf("%d", &E);
    for (i = 0; i < V; i++)

    {
        for (j = 0; j < V; j++)
            G[i][j] = 0;
    }
    for (i = 0; i < E; i++)
    {
        printf("Enter the edges (format: V1 V2) : ");
        scanf("%d%d", &v1, &v2);
        G[v1 - 1][v2 - 1] = 1;
        G[v2 - 1][v1 - 1] = 1;
    }
    printf("The adjacency matrix of the given graph:\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            printf(" %d ", G[i][j]);
        printf("\n");
    }
    printf("Using DFS algorithm\n");
    printf("Enter the source: ");
    scanf("%d", &source);
    DFS(source - 1);
    flag = connectivity();
    if (flag)
        printf("\nThe graph is connected\n");
    else
    {
        printf("\nThe graph is not connected\n");
        exit(0);
    }
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (G[i][j] == 1)
            {
                G[i][j] = 0;
                for (k = 0; k < V; k++)

                {
                    visited[k] = 0;
                }
                DFS(0);
                flag = connectivity();
                if (flag == 0)
                {
                    printf("\nThe graph is single edge connected");
                    printf("\nThe bridge is %d--%d", i + 1, j + 1);
                    exit(0);
                }
                else
                {
                    G[i][j] = 1;
                }
            }
        }
    }
    printf("\nThe graph is multi edge connected");
    return 0;
}
