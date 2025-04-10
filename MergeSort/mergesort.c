/* MERGE SORT */
#include <stdio.h>
void mergesort(int, int);
void merge(int, int, int);
int a[20];
int count;
int main()
{
  int i, n;
  printf("\nEnter the size of array:");
  scanf("%d", &n);
  printf("\nEnter the elements:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  count = 0;
  mergesort(0, n - 1);
  printf("\nAfter sorting elements are:\n");
  for (i = 0; i < n; i++)
    printf("%d\t", a[i]);
  printf("\nCount=%d", count);
  return 0;
}
void mergesort(int low, int high)
{
  int mid;
  if (low < high)
  {
    mid = (low + high) / 2;
    mergesort(low, mid);
    mergesort(mid + 1, high);
    merge(low, mid, high);
  }
}
void merge(int low, int mid, int high)
{
  int i, j, h, k, b[20];
  k = low;
  i = low;
  j = mid + 1;
  while ((i <= mid) && (j <= high))
  {
    if (a[i] <= a[j])
    {
      b[k] = a[i];
      i++;
      count++;
    }
    else
    {
      b[k] = a[j];
      j++;
      count++;
    }
    k++;
  }
  if (i > mid)
    for (h = j; h <= high; h++)
    {
      b[k] = a[h];
      k++;
    }
  else
  {
    for (h = i; h <= mid; h++)
    {
      b[k] = a[h];
      k++;
    }
  }
  for (h = low; h <= high; h++)
    a[h] = b[h];
}
