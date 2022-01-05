//Single link list
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void display(struct node* ptr);
void insertatend(struct node* ptr,int x);
void insertatbeg(struct node** ptr,int x);
void insertatmid(struct node* ptr,int i,int x);
void delfirst(struct node** ptr);
void delend(struct node* ptr); 
void delmid(struct node* ptr,int i);

int main(){
	struct node* head=(struct node*)malloc(sizeof(struct node));
	head->data=10;
	head->next=NULL;

	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=20;
	temp->next=NULL;
	head->next=temp;

	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=30;
	temp->next=NULL;
	head->next->next=temp;

	insertatend(head,40);

	delmid(head,2);

	display(head);


}

void display(struct node* ptr)
{
	while(ptr!=NULL)
	{
		printf("%d  ",ptr->data);
		ptr=ptr->next;
	}
}

void insertatend(struct node* ptr,int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
}

void insertatbeg(struct node** ptr,int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=*ptr;
	*ptr=temp;
}

void insertatmid(struct node* ptr,int i,int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	int count=0;
	i--;
	while((ptr->next!=NULL)&(count<i))
	{
		ptr=ptr->next;
		count++;
	}
	temp->next=ptr->next;
	ptr->next=temp;

}

void delfirst(struct node** ptr)
{
	*ptr=(*ptr)->next;	
}

void delend(struct node* ptr)
{
	while(ptr->next->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=NULL;
}

void delmid(struct node* ptr,int i)
{	int count=1;
	while((ptr->next!=NULL)&(count<i))
	{		
		ptr=ptr->next;
		count++;
	}
	ptr->next=ptr->next->next;
}