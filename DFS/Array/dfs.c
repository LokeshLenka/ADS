/* Depth First Search graph traversal*/

#include <stdio.h>
void DFS(int);
void dfs(int, int);
int adj[10][10], m[10], count;
int main()
{
  int i, j, n;

  printf("\nEnter the no of vertices in graph:");
  scanf("%d", &n);
  printf("\nEnter the 1 if edge else 0 if no edge\n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    {
      printf("Enter the value for edge from %d to %d:", i, j);
      scanf("%d", &adj[i][j]);
    }
  DFS(n);
  printf("\nVisiting vertices order is\n");
  for (i = 1; i <= n; i++)
    printf("\n%d\t%d", i, m[i]);
}
void DFS(int n)
{
  int i;
  for (i = 1; i <= n; i++)
    m[i] = 0;
  count = 0;
  for (i = 1; i <= n; i++)
    if (m[i] == 0)
      dfs(i, n);
}
void dfs(int i, int n)
{
  int j;
  count++;
  m[i] = count;
  for (j = 1; j <= n; j++)
    if (adj[i][j] != 0)
    {
      if (m[j] == 0)
        dfs(j, n);
    }
}
