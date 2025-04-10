// Finding Bi-Connected Components in the Graph
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int time = 0;

struct Edge
{
  int u, v;
};
typedef struct Edge *edgeptr;

struct Graph
{
  int V;
  int adj[MAX][MAX];
};
typedef struct Graph *graphptr;
void initGraph(graphptr graph, int V);
void addEdge(graphptr graph, int u, int v);
void BCCUtil(graphptr graph, int u, int disc[], int low[], int parent[], bool stackMember[], struct Edge stack[], int *stackTop, int *bccCount);
void BCC(graphptr graph);

int main()
{
  int n, e, i, u, v;
  struct Graph graph;
  printf("\nEnter the no of Vertices:");
  scanf("%d", &n);
  initGraph(&graph, n);
  printf("\nEnter the no of Edges:");
  scanf("%d", &e);
  for (i = 0; i < e; i++)
  {
    printf("\nEnter the Edge-%d\n", i + 1);
    printf("Enter the Source Vertex:");
    scanf("%d", &u);
    printf("\nEnter the Destination vertex:");
    scanf("%d", &v);
    addEdge(&graph, u, v);
  }
  printf("Biconnected components in the graph are:\n");
  BCC(&graph);
  return 0;
}

void initGraph(graphptr graph, int V)
{
  graph->V = V;
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      graph->adj[i][j] = 0;
}

void addEdge(graphptr graph, int u, int v)
{
  graph->adj[u][v] = 1;
  graph->adj[v][u] = 1;
}

void BCCUtil(graphptr graph, int u, int disc[], int low[], int parent[], bool stackMember[], struct Edge stack[], int *stackTop, int *bccCount)
{
  int children = 0;

  disc[u] = low[u] = ++time;

  for (int v = 0; v < graph->V; v++)
  {
    if (graph->adj[u][v])
    {
      if (disc[v] == -1)
      {
        children++;
        parent[v] = u;
        stack[*stackTop].u = u;
        stack[*stackTop].v = v;
        (*stackTop)++;

        BCCUtil(graph, v, disc, low, parent, stackMember, stack, stackTop, bccCount);

        low[u] = (low[u] < low[v]) ? low[u] : low[v];

        if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= disc[u]))
        {
          printf("BCC %d: ", ++(*bccCount));
          while (stack[*stackTop - 1].u != u || stack[*stackTop - 1].v != v)
          {
            printf("(%d, %d) ", stack[*stackTop - 1].u, stack[*stackTop - 1].v);
            (*stackTop)--;
          }
          printf("(%d, %d)\n", stack[*stackTop - 1].u, stack[*stackTop - 1].v);
          (*stackTop)--;
        }
      }
      else if (v != parent[u] && disc[v] < disc[u])
      {
        low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        stack[*stackTop].u = u;
        stack[*stackTop].v = v;
        (*stackTop)++;
      }
    }
  }
}

void BCC(graphptr graph)
{
  int disc[MAX], low[MAX], parent[MAX];
  bool stackMember[MAX];
  struct Edge stack[MAX * MAX];
  int stackTop = 0, bccCount = 0;

  for (int i = 0; i < graph->V; i++)
  {
    disc[i] = -1;
    low[i] = -1;
    parent[i] = -1;
    stackMember[i] = false;
  }

  for (int i = 0; i < graph->V; i++)
  {
    if (disc[i] == -1)
    {
      BCCUtil(graph, i, disc, low, parent, stackMember, stack, &stackTop, &bccCount);

      while (stackTop > 0)
      {
        printf("BCC %d: ", ++bccCount);
        while (stackTop > 0)
        {
          printf("(%d, %d) ", stack[stackTop - 1].u, stack[stackTop - 1].v);
          stackTop--;
        }
        printf("\n");
      }
    }
  }
}
