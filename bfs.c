#include<stdio.h>
#include<stdlib.h>
int q[10],visited[10],i,j,n,adj[20][20],v,front=1,rear=0,item;
void insert(int v);
int del();
void insert(int v)
{
	rear++;
	q[rear]=v;
}
int del()
{
	v=q[front];
	front++;
	return v;
}
int main()
{
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		visited[i]=0;
	}
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			printf("adj[%d][%d]:",i,j);
			scanf("%d",&adj[i][j]);
			printf("\n");
		}
	}
	insert(1);
	printf("Spanning tree edges are:\n");
	for(i=1;i<=n;++i)
	{
		item=del();
		visited[item]=1;
		for(j=i+1;j<=n;j++)
		{
			if(adj[item][j]==1 && visited[j]==0)
			{
				insert(j);
				visited[j]=1;
				printf("Edge(%d,%d)\n",item,j);
			}
		}
	}
	return 0;
}

