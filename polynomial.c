#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct poly
{
	int coeff;
	int degree;
	struct poly* next;	
}*temp,*newnode,*list1,*list2,*list3;

void create(struct poly** list);
void print();
struct poly* add(struct poly* a,struct poly* b);
struct poly* sub(struct poly* a,struct poly* b);
struct poly* mul(struct poly* a,struct poly* b);


void main()
{
	create(&list1);
	print(list1);
	printf("\n");
	create(&list2);
	print(list2);
	printf("\n");
	list3=mul(list1,list2);
	print(list3);
}

void create(struct poly** list)
{
	int n,a;
	temp=(struct poly*)malloc(sizeof(struct poly));
	temp->next=NULL;
	*list=temp;
	printf("enter number of terms");
	scanf("%d",&n);
	for(int i=0;i<2*n;i++)
	{
		if(i%2==0)
		{
			scanf("%d",&a);
			temp->coeff=a;
		}
		else
		{
			scanf("%d",&a);
			temp->degree=a;
			if(i<2*n-1)
			{
				temp->next=(struct poly*)malloc(sizeof(struct poly));
				temp->next->next=NULL;
				temp=temp->next;
			}
		}
		
	}
	printf("complete\n");
}
void print(struct poly* list)
{
	for(temp=list;temp!=NULL;temp=temp->next)
	{
		printf("%dx^%d\t",temp->coeff,temp->degree,temp->next);
	}
}

struct poly* add(struct poly* a,struct poly* b)
{
	newnode=(struct poly*)malloc(sizeof(struct poly));
	newnode->next=NULL;
	list3=newnode;
	while(a!=NULL&&b!=NULL)
	{
		if(a->degree==b->degree)
		{
			newnode->coeff=a->coeff+b->coeff;
			newnode->degree=a->degree;
			a=a->next;
			b=b->next;
		}
		else if(a->degree>b->degree)
		{
			newnode->coeff=a->coeff;
			newnode->degree=a->degree;
			a=a->next;
		}
		else if(a->degree<b->degree)
		{
			newnode->coeff=b->coeff;
			newnode->degree=b->degree;
			b=b->next;
		}
		if(a!=NULL&&b!=NULL)
		{
			temp=(struct poly*)malloc(sizeof(struct poly));
			temp->next=NULL;
			newnode->next=temp;
			newnode=temp;
		}
		
		}
		while(a!=NULL)
		{
			
			temp=(struct poly*)malloc(sizeof(struct poly));
			temp->next=NULL;
			temp->coeff=a->coeff;
			temp->degree=a->degree;
			newnode->next=temp;
			newnode=temp;
			a=a->next;
		}
		while(b!=NULL)
		{
			temp=(struct poly*)malloc(sizeof(struct poly));
			temp->next=NULL;
			temp->coeff=b->coeff;
			temp->degree=b->degree;
			newnode->next=temp;
			newnode=temp;
			b=b->next;
	}
	return list3;
	

}

struct poly* sub(struct poly* a,struct poly* b)
{
	newnode=(struct poly*)malloc(sizeof(struct poly));
	newnode->next=NULL;
	list3=newnode;
	while(a!=NULL&&b!=NULL)
	{
		if(a->degree==b->degree)
		{
			newnode->coeff=a->coeff-b->coeff;
			newnode->degree=a->degree;
			a=a->next;
			b=b->next;
		}
		else if(a->degree>b->degree)
		{
			newnode->coeff=a->coeff;
			newnode->degree=a->degree;
			a=a->next;
		}
		else if(a->degree<b->degree)
		{
			newnode->coeff=(b->coeff)*-1;
			newnode->degree=b->degree;
			b=b->next;
		}
		if(a!=NULL&&b!=NULL)
		{
			temp=(struct poly*)malloc(sizeof(struct poly));
			temp->next=NULL;
			newnode->next=temp;
			newnode=temp;
		}
		
		}
		while(a!=NULL)
		{
			
			temp=(struct poly*)malloc(sizeof(struct poly));
			temp->next=NULL;
			temp->coeff=a->coeff;
			temp->degree=a->degree;
			newnode->next=temp;
			newnode=temp;
			a=a->next;
		}
		while(b!=NULL)
		{
			temp=(struct poly*)malloc(sizeof(struct poly));
			temp->next=NULL;
			temp->coeff=b->coeff;
			temp->degree=b->degree;
			newnode->next=temp;
			newnode=temp;
			b=b->next;
	}
	return list3;
	

}

struct poly* mul(struct poly* a,struct poly* b)
{
	int i,j;
    newnode=(struct poly*)malloc(sizeof(struct poly));
	newnode->next=NULL;
	list3=newnode;
	for(struct poly* temp1=a;temp1!=NULL;temp1=temp1->next)
	{
		for(struct poly* temp2=b;temp2!=NULL;temp2=temp2->next)
		{
			i=temp1->coeff*temp2->coeff;
			j=temp1->degree*temp2->degree;
			newnode->coeff=i;
			newnode->degree=j;
			if(temp2->next!=NULL)
			{
				temp=(struct poly*)malloc(sizeof(struct poly));
				temp->next=NULL;
				newnode->next=temp;
				newnode=temp;
			}
		}
	}
	return list3;
}