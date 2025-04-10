// Traveling Salesman Problem using LCBB
#include <stdio.h>
#include <limits.h>
int find_min_cost(int[10][10], int, int);
int find_second_min_cost(int[10][10], int, int);
void tsp_branch_and_bound(int[10][10], int, int, int, int, int[], int[], int *, int[]);
void solve_tsp(int[10][10], int);
int main()
{
  int adj[10][10], n;
  printf("\nEnter the no of cities:");
  scanf("%d", &n);
  printf("\nEnter the Distances\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("\nEnter distance [%d, %d]: ", i, j);
      scanf("%d", &adj[i][j]);
    }
  }
  printf("\nTraveling salesman problem\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      printf("%d\t", adj[i][j]);
    printf("\n");
  }

  solve_tsp(adj, n);

  return 0;
}
// Function to find the minimum cost edge having an end at the vertex i
int find_min_cost(int adj[10][10], int n, int i)
{
  int min = INT_MAX;
  for (int k = 0; k < n; k++)
    if (adj[i][k] != 0 && adj[i][k] < min)
      min = adj[i][k];
  return min;
}

// Function to find the second minimum cost edge having an end at the vertex i
int find_second_min_cost(int adj[10][10], int n, int i)
{
  int first = INT_MAX, second = INT_MAX;
  for (int j = 0; j < n; j++)
  {
    if (adj[i][j] <= first)
    {
      second = first;
      first = adj[i][j];
    }
    else if (adj[i][j] <= second && adj[i][j] != first)
      second = adj[i][j];
  }
  return second;
}

// Recursive function that solves the TSP using Branch and Bound
void tsp_branch_and_bound(int adj[10][10], int n, int curr_bound, int curr_weight, int level, int curr_path[], int visited[], int *min_cost, int final_path[])
{
  if (level == n)
  {
    // check for a solution
    if (adj[curr_path[level - 1]][curr_path[0]] != 0)
    {
      int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];
      printf("\n Current Path Length=%d\n", curr_res);
      printf("\nCurrent path:");
      for (int i = 0; i < n; i++)
        printf("%d\t", curr_path[i]);
      printf("%d\n", curr_path[0]);
      if (curr_res < *min_cost)
      {
        *min_cost = curr_res;

        for (int i = 0; i < n; i++)
          final_path[i] = curr_path[i];
        final_path[n] = curr_path[0];
      }
    }
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (adj[curr_path[level - 1]][i] != 0 && visited[i] == 0)
    {
      int temp = curr_bound;
      curr_weight += adj[curr_path[level - 1]][i];

      if (level == 1)
        curr_bound -= ((find_min_cost(adj, n, curr_path[level - 1]) +
                        find_min_cost(adj, n, i)) /
                       2);
      else
        curr_bound -= ((find_second_min_cost(adj, n, curr_path[level - 1]) +
                        find_min_cost(adj, n, i)) /
                       2);

      if (curr_bound + curr_weight < *min_cost)
      {
        curr_path[level] = i;
        visited[i] = 1;

        tsp_branch_and_bound(adj, n, curr_bound, curr_weight, level + 1, curr_path, visited, min_cost, final_path);
      }

      curr_weight -= adj[curr_path[level - 1]][i];
      curr_bound = temp;

      for (int j = 0; j < n; j++)
        visited[j] = 0;
      for (int j = 0; j <= level - 1; j++)
        visited[curr_path[j]] = 1;
    }
  }
}

// Function to solve the TSP
void solve_tsp(int adj[10][10], int n)
{
  int curr_path[20];
  int visited[10] = {0};
  int min_cost = INT_MAX;
  int final_path[20];
  int curr_bound = 0;

  // Initialize the current bound
  for (int i = 0; i < n; i++)
    curr_bound += (find_min_cost(adj, n, i) + find_second_min_cost(adj, n, i));

  curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;

  visited[0] = 1;
  curr_path[0] = 0;

  tsp_branch_and_bound(adj, n, curr_bound, 0, 1, curr_path, visited, &min_cost, final_path);

  printf("Minimum cost: %d\n", min_cost);
  printf("Path: ");
  for (int i = 0; i <= n; i++)
    printf("%d ", final_path[i]);
  printf("\n");
}
