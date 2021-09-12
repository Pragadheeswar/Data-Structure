#include<stdio.h>
#define max 10
int arr[max],top=-1,n;

void create(),push(),pop(),display(),total();

void main()
{
	create();
	display();
	total();
}

void create()
{
	printf("Enter the no of element");
	scanf("%d",&n);
	if(n<max){
		printf("Enter");
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
		}
		top=n-1;
	}
	else
		printf("unable to crete");
}

void push()
{	
	int x;
	if(top+1<max){
		printf("enter number");
		scanf("%d",&x);
		top+=1;
		arr[top]=x;
	}
	else
		printf("stack is full");
}

void pop()
{
	int x;
	if(top==-1)
		printf("stack is empty");
	else{
		x=arr[top];
		printf("%d is poped",x);
		top-=1;
	}
}

void display()
{
	if(top==-1)
		printf("stack is empty");
	else
		for(int i=top;i>=0;--i)
			printf("%d\n",arr[i]);
}

void total()
{
	if(top==-1)
		printf("empty");
	else
		printf("no of elements %d",top+1);
}