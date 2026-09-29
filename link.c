#include<stdio.h>
#define INF 9999
#define MAX 10
int main()
{
int n, cost[MAX][MAX], dist[MAX], visited[MAX];
int src;
printf("Enter number of routers: ");
scanf("%d",&n);
printf("\nEnter the cost matrix(9999 for no link):\n");
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
scanf("%d", &cost[i][j]);
printf("\nEnter source router:");
scanf("%d",&src);

for(int i=0;i<n;i++)
{
dist[i]=cost[src][i];
visited[i]=0;
}
dist[src]=0;
visited[src]=1;

for(int count=1;count<n;count++)
{
int min=INF,u=-1;
for(int i=0;i<n;i++)
{
if(!visited[i]&&dist[i]<min)
{
min=dist[i];
u=i;
}}
visited[u]=1;
for(int v=0;v<n;v++)
{
if(!visited[v]&&dist[u]+cost[u][v]<dist[v])
{
dist[v]=dist[u]+cost[u][v];
}
}
}
printf("\nShortest distances from router %d:\n",src);
for(int i=0;i<n;i++)
printf("To %d ->cost=%d\n",i,dist[i]);
return 0;
}



