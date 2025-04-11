#include<stdio.h>
#define max 10
struct queue
{
	int front,rear;
	int items[max];

};
typedef struct queue *queueptr;
void BFS(int);
void bfs(int,int);
int adj[10][10],m[10],count;
void insert(queueptr,int);
int del(queueptr);
int empty(queueptr);
struct queue q;
int main()
{
	int i,j,n;
	q.front=1;
	q.rear=0;
	printf("\n enter the no.of vertices in graph:");
	scanf("%d",&n);
	printf("\n enter the 1 if edge else 0 if no edges\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		printf("enter the value for edge from %d to %d:",i,j);
		scanf("%d",&adj[i][j]);
	}
	BFS(n);
	printf("\n visiting vertices order is\n\n");
	for(i=1;i<=n;i++)
	printf("\n vertex- %d\t%d",i,m[i]);
	}
	void BFS(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		m[i]=0;
		count=0;
		for(i=1;i<=n;i++)
		if(m[i]==0)
		bfs(i,n);
		}
		void bfs(int i,int n)
		{
			int j,k;
			count++;
			m[i]=count;
			insert(&q,i);
			while(!empty(&q))
			{
				for(j=1;j<=n;j++)
				if(adj[q.front][j]!=0)
				if(m[j]==0)
				{
					count++;
					m[j]=count;
					insert(&q,j);
				}
			k=del(&q);
			
		}
	}
	void insert(queueptr qu,int a)
	{
		if(qu->rear==max-1)
		{
			printf("\n queue if full");
		}
		else
		{
			qu->rear++;
			qu->items[qu->rear]=a;
		}
	}
	
		
	int del(queueptr qu)
	{
		int a;
		if(empty(qu))
		return -1;
		else
		{
			a=qu->items[qu->front];
			qu->front++;
			return a;
		}
	}
	int empty(queueptr qu)
	{
		if(qu->front>qu->rear)
		return 1;
		else
		return 0;
	}
	
	
	
	
	
	
	

