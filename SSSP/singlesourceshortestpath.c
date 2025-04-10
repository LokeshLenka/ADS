/*Single source Shortest Paths using Greedy Method*/
#include <stdio.h>
#include <conio.h>
void shortestpaths(int[50][50], int[], int, int);
int main()
{
  int n, i, j, d[50], cost[50][50], v;
  printf("\nEnter the no of vertices:");
  scanf("%d", &n);
  printf("Enter the cost matrix\n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    {
      printf("\nEnter the cost of edge %d-%d:", i, j);
      scanf("%d", &cost[i][j]);
    }

  printf("Enter the source vertex:");
  scanf("%d", &v);
  shortestpaths(cost, d, v, n);
  printf("\nShortest paths from Source vertex %d is\n", v);
  for (i = 1; i <= n; i++)
    printf("\nShortest path from %d to %d  =  %d", v, i, d[i]);
  return 0;
}
void shortestpaths(int cost[50][50], int d[50], int v, int n)
{
  int i, num, s[50], min, ver;
  for (i = 1; i <= n; i++)
  {
    s[i] = 0;
    d[i] = cost[v][i];
  }
  s[v] = 1;
  d[v] = 0;
  for (num = 2; num < n; num++)
  {
    min = 999;
    ver = 0;
    for (i = 1; i <= n; i++)
      if (s[i] == 0)
        if (d[i] < min)
        {
          ver = i;
          min = d[i];
        }
    s[ver] = num;
    for (i = 1; i <= n; i++)
      if ((s[i] == 0) && (cost[ver][i] != 999))
        if (d[i] > (d[ver] + cost[ver][i]))
          d[i] = d[ver] + cost[ver][i];
  }
}
