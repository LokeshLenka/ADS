// 0/1 knapsack problem using Backtracking
#include <stdio.h>

#define MAX_ITEMS 100
int max(int, int);
void knapsack(int, int[], int[], int, int, int, int, int *);
int main()
{
  int n, capacity;
  int weights[MAX_ITEMS], profits[MAX_ITEMS];
  int maxProfit = 0;

  printf("Enter the number of items: ");
  scanf("%d", &n);

  printf("Enter the weights of the items: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &weights[i]);
  }

  printf("Enter the profits of the items: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &profits[i]);
  }

  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  knapsack(n, weights, profits, capacity, 0, 0, 0, &maxProfit);

  printf("Maximum profit: %d\n", maxProfit);

  return 0;
}
int max(int a, int b)
{
  return (a > b) ? a : b;
}

void knapsack(int n, int weights[], int profits[], int capacity, int index, int currentWeight, int currentProfit, int *maxProfit)
{
  // Base case: If all items are considered or weight limit is reached
  if (index == n || currentWeight > capacity)
  {
    if (currentWeight <= capacity)
    {
      *maxProfit = max(*maxProfit, currentProfit);
    }
    return;
  }

  // Case 1: Exclude the current item and move to the next item
  knapsack(n, weights, profits, capacity, index + 1, currentWeight, currentProfit, maxProfit);

  // Case 2: Include the current item if it doesn't exceed the capacity
  if (currentWeight + weights[index] <= capacity)
  {
    knapsack(n, weights, profits, capacity, index + 1, currentWeight + weights[index], currentProfit + profits[index], maxProfit);
  }
}
