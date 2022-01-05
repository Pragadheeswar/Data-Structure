#include<stdio.h>
#include <stdlib.h>
void insert();
void display();
void deletion();
void find();
typedef struct node* position;
struct node{
	int data;
	position next;
	position prev;
};
position L=NULL,newnode,P,temp;
void main()
{
	int ch;
	do
	{
		printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.FIND\n5.EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			insert();
			break;
			case 2:
			deletion();
			break;
			case 3:
			display();
			break;
			case 4:
			find();
			break;
			case  5:
			printf("PROGRAM END!!");
			exit(1);
		} 
	}while(ch!=5);

}
void insert()
{
	int pos,i;
	newnode=(position)malloc(sizeof(struct node));
	newnode->prev=NULL;
	newnode->next=NULL;
	printf("Enter the element:");
	scanf("%d",&newnode->data);
	if(L==NULL)
	{
		L=newnode;
	}
	else
	{
		printf("Enter the positon:");
		scanf("%d",&pos);
		if(pos==1)
		{
			newnode->next=L;
			L->prev=newnode;
			L=newnode;
		}
		else
		{
			P=L;
			for(i=1;i<pos-1;i++)
			{
				P=P->next;
			}
			newnode->prev=P;
			newnode->next=P->next;
			if(P->next!=NULL)
			{
				P->next->prev=newnode;
				P->next=newnode;
			}
			else
			{
				P->next=newnode;
			}
		}
	}
}

void display()
{
	if(L==NULL)
	{
		printf("the list is empty");
	}
	else
	{
		for(P=L;P!=NULL;P=P->next)
			printf("%d\t",P->data);
		printf("\n");
	}
}
void deletion()
{
	int pos;
	if(L==NULL)
	{
		printf("list is empty");
	}
	else
	{
		printf("Enter the position to delete:");
		scanf("%d",&pos);
		if(pos==1)
		{
			temp=L;
			L=temp->next;
			printf("element %d is deleted\n",temp->data);
			free(temp);
		}
		else
		{
			P=L;
			for(int i=1;i<pos-1;i++)
				P=P->next;
			temp=P->next;
			if(temp->next!=NULL)
			{
				P->next=temp->next;
				temp->next->prev=P;
				printf("element %d is deleted\n",temp->data);
				free(temp);
		    }
		    else
		    {
		    	P->next=NULL;
		    	printf("element %d is deleted\n",temp->data);
		    	free(temp);
		    }

		}
	}
}

void find()
{
	int a,count=0,f=0;
	if(L==NULL)
		printf("the list is empty");
	else
	{
		printf("Enter the element to search:");
		scanf("%d",&a);
		for(P=L;P!=NULL;P=P->next)
		{
			count++;
			if(P->data==a){
				printf("the elemnt is found in %d\n",count);
				f=1;
				break;
			}
		}
		if(f==0)
			printf("the elment is not found");
	}
}