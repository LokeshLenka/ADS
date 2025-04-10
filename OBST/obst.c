// optimal Binary Search Tree using Dynamic Programming
#include <stdio.h>
float optimal(float[], float[], int, float);
int find(float[20][20], int[20][20], int, int);
void write(float[20][20], float[20][20], int[20][20], int, float);
int main()
{
  float p[20], q[20], s, d;
  int n;
  printf("\nEnter the no of Identifiers:");
  scanf("%d", &n);
  printf("\nEnter the denominator:");
  scanf("%f", &d);
  printf("\nEnter the Values of Probabilities\n");
  for (int i = 1; i <= n; i++)
  {
    printf("\np[%d]:", i);
    scanf("%f", &p[i]);
  }
  for (int i = 0; i <= n; i++)
  {
    printf("\nq[%d]:", i);
    scanf("%f", &q[i]);
  }
  s = optimal(p, q, n, d);
  printf("\nCost of OBST = %.2f", s / d);
  return 0;
}
float optimal(float p[20], float q[20], int n, float d)
{
  float w[20][20], c[20][20];
  int r[20][20], i, j, k, m;
  for (i = 0; i < n; i++)
  {
    w[i][i] = q[i];
    c[i][i] = 0;
    r[i][i] = 0;
    w[i][i + 1] = p[i + 1] + q[i] + q[i + 1];
    c[i][i + 1] = w[i][i + 1];
    r[i][i + 1] = i + 1;
  }
  w[n][n] = q[n];
  c[n][n] = 0;
  r[n][n] = 0;
  for (m = 2; m <= n; m++)
  {
    for (i = 0; i <= n - m; i++)
    {
      j = i + m;
      w[i][j] = w[i][j - 1] + p[j] + q[j];
      k = find(c, r, i, j);
      c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
      r[i][j] = k;
    }
  }
  write(c, w, r, n, d);
  return c[0][n];
}
int find(float c[20][20], int r[20][20], int i, int j)
{
  int min, k, l;
  min = 999;
  for (k = i + 1; k <= j; k++)
  {
    if (c[i][k - 1] + c[k][j] < min)
    {
      min = c[i][k - 1] + c[k][j];
      l = k;
    }
  }
  return l;
}
void write(float c[20][20], float w[20][20], int r[20][20], int n, float d)
{
  int i, j;
  for (j = 0; j <= n; j++)
  {
    printf("\n");
    for (i = 0; i <= n - j; i++)
    {
      printf("%.2f\t", w[i][i + j] / d);
    }
    printf("\n");
    for (i = 0; i <= n - j; i++)
    {
      printf("%.2f\t", c[i][i + j] / d);
    }
    printf("\n");
    for (i = 0; i <= n - j; i++)
    {
      printf("%d   \t", r[i][i + j]);
    }
    printf("\n\n");
  }
}
