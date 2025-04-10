// BFS algorithm using Linked list in C
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
struct queue
{
    int items[SIZE];
    int front;
    int rear;
};
typedef struct queue *queueptr;
struct node
{
    int vertex;
    struct node *next;
};
typedef struct node *nodeptr;
struct Graph
{
    int numVertices;
    nodeptr *adjLists;
    int *visited;
};
typedef struct Graph *graphptr;
queueptr createQueue();
void enqueue(queueptr q, int);
int dequeue(queueptr q);
void display(queueptr q);
int isEmpty(queueptr q);
void printQueue(queueptr q);
nodeptr createNode(int);
graphptr createGraph(int);
void bfs(graphptr, int);
void BFS(graphptr, int);
void printGraph(graphptr);
void addEdge(graphptr, int, int);
int main()
{
    int n, e, s, d, i;
    printf("\nEnter the no of vertices in a graph:");
    scanf("%d", &n);
    graphptr graph = createGraph(n);
    printf("\nEnter the no of edges in a graph:");
    scanf("%d", &e);
    for (i = 0; i < e; i++)
    {
        printf("\nEnter the edge-%d\n", i + 1);
        printf("Enter the source vertex of edge:");
        scanf("%d", &s);
        printf("\nEnter the Destination vertex of edge:");
        scanf("%d", &d);
        addEdge(graph, s, d);
    }
    printGraph(graph);
    BFS(graph, n);
    return 0;
}
// BFS algorithm
void BFS(graphptr graph, int novertices)
{
    for (int i = 0; i < novertices; i++)
    {
        if (graph->visited[i] == 0)
        {
            bfs(graph, i);
        }
    }
}
void bfs(graphptr graph, int startVertex)
{
    queueptr q = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    while (!isEmpty(q))
    {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("\nVisited %d\n", currentVertex);
        nodeptr temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}
// Creating a node
nodeptr createNode(int v)
{
    nodeptr newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Creating a graph
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

// Create a queue
queueptr createQueue()
{
    queueptr q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(queueptr q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(queueptr q, int value)
{
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(queueptr q)
{
    int item;
    if (isEmpty(q))
    {
        printf("\nQueue is empty\n");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            printf("\nResetting queue\n ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Print the queue
void printQueue(queueptr q)
{
    int i = q->front;
    if (isEmpty(q))
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue contains \n");
        for (i = q->front; i < q->rear + 1; i++)
        {
            printf("%d\t", q->items[i]);
        }
    }
}
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
