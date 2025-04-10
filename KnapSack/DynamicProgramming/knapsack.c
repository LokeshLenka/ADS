// 0/1 knapsack problem using Dynamic programming
#include <stdio.h>
int max(int, int);
int knapSack(int, int[], int[], int);
int main()
{
  int i, n, val[20], wt[20], W, s;

  printf("Enter number of items:");
  scanf("%d", &n);

  printf("Enter value and weight of items:\n");
  wt[0] = 0;
  val[0] = 0;
  for (i = 1; i <= n; ++i)
  {
    printf("\nItem-%d Value:", i);
    scanf("%d", &val[i]);
    printf("\nItem-%d Weight:", i);
    scanf("%d", &wt[i]);
  }

  printf("\nEnter size of knapsack:");
  scanf("%d", &W);
  s = knapSack(W, wt, val, n);
  printf("\n\nprofit=%d", s);
  return 0;
}
int max(int a, int b)
{
  return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
  int i, j, w, a, u, x[20];
  int K[20][20];
  for (i = 0; i <= n; i++)
    x[i] = 0;
  for (i = 0; i <= n; i++)
  {
    for (w = 0; w <= W; w++)
    {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (wt[i] <= w)
        K[i][w] = max(val[i] + K[i - 1][w - wt[i]], K[i - 1][w]);
      else
        K[i][w] = K[i - 1][w];
    }
  }
  for (i = 0; i <= n; i++)
  {
    printf("\n");
    for (j = 0; j <= W; j++)
      printf("%d\t", K[i][j]);
  }
  i = n;
  a = K[n][W];
  u = W;
  while (i >= 0)
  {
    printf("\n\nitems=%d\t\tCapacity=%d\tprofit=%d", i, u, a);
    if (a == K[i - 1][u])
    {
      x[i] = 0;
      a = K[i - 1][u];
    }
    else
    {
      x[i] = 1;
      u = u - wt[i];
      a = K[i - 1][u];
    }
    i--;
  }
  printf("\n\nSolution is: ");
  printf("(");
  for (i = 1; i <= n; i++)
    printf("%d, ", x[i]);
  printf(")\n");
  return K[n][W];
}
