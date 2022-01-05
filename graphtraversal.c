#include<stdio.h>

int a[10][10],n,s[20],top=-1,v[10],front=-1,rear=-1;
void push(int x);
int push();
void dfs(int s);
void dfs_rec(int s);
int remove();
void add(int x);

int main()
{
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			printf("Is %d is connected to %d (0/1):",i,j);
			scanf("%d",&a[i][j]);
		}
	printf("The adjacency matrix:\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}

	dfs_rec(2);
	return 0;
}

void push(int x)
{
	if(top==19)
		printf("Stack overflow");
	else
	{
		s[++top]=x;
	}
}

int pop()
{
	if(top==-1)
		printf("Stack is empty");
	else
	{
		return s[top--];
	}
}

void dfs(int s)
{
	int r;
	push(s);
	while(top!=-1)
	{
		r=pop();
		if(v[r]==0)
		{
			printf("%d ",r);
			v[r]=1;
		}
		for(int i=1;i<=n;i++)
			if(a[r][i]==1 && v[i]==0)
				push(i);
	}
}
 
void dfs_rec(int s)
{
	printf("%d ",s);
	v[s]=1;
	for(int i=1;i<=n;i++)
			if(a[s][i]==1 && v[i]==0)
				dfs_rec(i);
}

void add(int x)
{
	if(front=)
}

int remove()
{
	if(front==-1 && rear =-1)
		printf("Queue is empty");
	else
	{
		return a[front++];
	}
}

