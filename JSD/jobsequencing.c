/*Job Sequencing with Deadlines using Greedy Method*/
#include <stdio.h>
#include <conio.h>
int greedyjob(int[], int[], int);
void selectionsort(int[], int[], int);
int main()
{
  int n, p[100], d[100], i, j[100], k, p1;
  printf("\nEnter the no of Jobs:");
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    printf("profit[%d]=", i);
    scanf("%d", &p[i]);
    printf("deadline[%d]=", i);
    scanf("%d", &d[i]);
  }
  selectionsort(p, d, n);
  k = greedyjob(j, d, n);
  p1 = 0;
  printf("\nSolution is \n{");
  for (i = 1; i <= k; i++)
  {
    printf("   %d", j[i]);
    p1 = p1 + p[j[i]];
  }
  printf("  }\nprofit=%d", p1);

  return 0;
}
void selectionsort(int p[], int d[], int n)
{
  int i, j, indx, large;
  for (i = 1; i < n; i++)
  {
    indx = i;
    for (j = i + 1; j <= n; j++)
      if (p[j] > p[indx])
        indx = j;
    large = p[indx];
    p[indx] = p[i];
    p[i] = large;
    large = d[indx];
    d[indx] = d[i];
    d[i] = large;
  }
  for (i = 1; i <= n; i++)
    printf("\nprofit=%d\t\tdeadline=%d", p[i], d[i]);
}

int greedyjob(int j[100], int d[100], int n)
{
  int k, i, r, q;
  d[0] = 0;
  j[0] = 0;
  j[1] = 1;
  k = 1;
  for (i = 2; i <= n; i++)
  {
    r = k;
    while ((d[j[r]] > d[i]) && (d[j[r]] != r))
      r = r - 1;
    if ((d[j[r]] <= d[i]) && (d[i] > r))
    {

      for (q = k; q >= r + 1; q--)
        j[q + 1] = j[q];
      j[r + 1] = i;
      k = k + 1;
    }
  }
  return k;
}
