/* QUICK SORT */
#include <stdio.h>
#include <conio.h>
void quicksort();
int partition();
int n, a[100];
int count;
int main()
{
  int n, i;
  printf("\nEnter the size of array:");
  scanf("%d", &n);
  printf("\nEnter the elements:\n");
  for (i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  a[i] = 999;
  count = 0;
  quicksort(1, n);
  printf("\nafter sorting elements are:\n");
  for (i = 1; i <= n; i++)
    printf("%d\t", a[i]);
  printf("\ncount=%d\n", count);
  return 0;
}
void quicksort(int p, int q)
{
  int j;
  if (p < q)
  {
    j = partition(p, q + 1);
    quicksort(p, j - 1);
    quicksort(j + 1, q);
  }
}
int partition(int m, int p)
{
  int v, i, j, t;
  v = a[m];
  i = m;
  j = p;
  do
  {
    do
    {
      i++;
      count++;

    } while (a[i] < v);
    do
    {
      j--;
      count++;
    } while (a[j] > v);
    if (i < j)
    {
      t = a[j];
      a[j] = a[i];
      a[i] = t;
    }
  } while (i <= j);
  a[m] = a[j];
  a[j] = v;
  return j;
}
