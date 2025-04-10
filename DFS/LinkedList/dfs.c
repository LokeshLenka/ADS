// DFS Program using Linked list in C
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int vertex;
  struct node *next;
};
typedef struct node *nodeptr;
struct Graph
{
  int numVertices;
  int *visited;

  // We need int** to store a two dimensional array.
  // Similary, we need struct node** to store an array of Linked lists
  nodeptr *adjLists;
};
typedef struct Graph *graphptr;
nodeptr createNode(int);
void dfs(graphptr, int);
graphptr createGraph(int);
void addEdge(graphptr, int, int);
void printGraph(graphptr);
void DFS(graphptr, int);
int main()
{
  int n, k, n1, n2, i;
  printf("\nEnter the no of vertices in Graph:");
  scanf("%d", &n);
  graphptr graph = createGraph(n);
  printf("\nEnter the no of Edges in Graph:");
  scanf("%d", &k);
  printf("\nEnter the source vertex and destination vertex for EDGE\n");
  for (i = 0; i < k; i++)
  {
    printf("\nenter the EDGE-%d:", i + 1);
    printf("\nEnter the source vertex:");
    scanf("%d", &n1);
    printf("\nEnter the Destination vertex:");
    scanf("%d", &n2);
    addEdge(graph, n1, n2);
  }
  printGraph(graph);
  DFS(graph, n);

  return 0;
}
// DFS function
void DFS(graphptr graph, int novertices)
{
  for (int i = 0; i < novertices; i++)
  {
    if (graph->visited[i] == 0)
    {
      dfs(graph, i);
    }
  }
}
void dfs(graphptr graph, int vertex)
{
  nodeptr adjList = graph->adjLists[vertex];
  nodeptr temp = adjList;

  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  while (temp != NULL)
  {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0)
    {
      dfs(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

// Create a node
nodeptr createNode(int v)
{
  nodeptr newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create graph
graphptr createGraph(int vertices)
{
  graphptr graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node *));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++)
  {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

// Add edge
void addEdge(graphptr graph, int src, int dest)
{
  // Add edge from src to dest
  nodeptr newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(graphptr graph)
{
  int v;
  for (v = 0; v < graph->numVertices; v++)
  {
    nodeptr temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp)
    {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}
