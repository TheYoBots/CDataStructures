#include<stdio.h>

int q[20],front=-1,rear=-1,a[20][20],vis[20];

int delete();
void add(int item);
void BFS(int s,int n);

int main()
{
	int n,i,s,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
    vis[i]=0;
    scanf("%d",&s);
    BFS(s,n);
}

void BFS(int s,int n)
{
	int p,i;
	add(s);
	vis[s]=1;
	p=delete();
	if(p!=0)
	    printf(" %d",p);
	while(p!=0)
	{
		for(i=1;i<=n;i++)
		if((a[p][i]!=0)&&(vis[i]==0))
		{
			add(i);
			vis[i]=1;
		}
		p=delete();
		if(p!=0)
		    printf(" %d ",p);
	}
	for(i=1;i<=n;i++)
	if(vis[i]==0)
	    BFS(i,n);
    return 0;
}

void add(int item)
{
	if(rear==19)
	    printf("QUEUE FULL");
	else
	{
		if(rear==-1)
		{
			q[++rear]=item;
			front++;
		}
		else
            q[++rear]=item;
	}
}

int delete()
{
	int k;
	if((front>rear) || (front==-1))
	    return(0);
	else
	{
		k=q[front++];
		return(k);
	}
}