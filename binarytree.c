#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
}*root;

struct tree* newnode(int i)
{
	struct tree* temp = (struct tree*)malloc(sizeof(struct tree));
	temp->data=i;
	temp->left=temp->right=NULL;
	return temp;
}

struct tree* insert(int key,struct tree* leaf)
{
	if(leaf==NULL)
	{
		leaf=newnode(key);
		printf("node created\n");
	}
	else
	{
		if(key<leaf->data)
		{
			leaf->left=insert(key,leaf->left);
		}
		else
		{
			leaf->right=insert(key,leaf->right);
		}
	}
	return leaf;
}

void preorder(struct tree* leaf)
{
	if(leaf==NULL)
		return;
	printf("%d\t",leaf->data);
	preorder(leaf->left);
	preorder(leaf->right);
}

void inorder(struct tree* leaf)
{
	if(leaf==NULL)
		return;
	inorder(leaf->left);
	printf("%d\t",leaf->data);
	inorder(leaf->right);
}

void postorder(struct tree* leaf)
{
	if (leaf==NULL)
		return;
	postorder(leaf->left);
	postorder(leaf->right);
	printf("%d\t",leaf->data);
}

struct tree* search(int key,struct tree* leaf)
{
	if(key==leaf->data)
	{
		// printf("Element is found");
		return leaf;
	}
	else
	{
		if(key<leaf->data)
			return search(key,leaf->left);
		else
			return search(key,leaf->right);
	}
}

struct tree* findmin(struct tree* leaf)
{
	if(leaf==NULL)
		return leaf;
	else
	{
		if(leaf->left==NULL)
			return leaf;
		else
			return findmin(leaf->left);
	}
}

struct tree* delete(struct tree* leaf,int key)
{
	if(leaf==NULL)
		return leaf;
	else if(key<leaf->data)
		leaf->left=delete(leaf->left,key);
	else if(key>leaf->data)
		leaf->right=delete(leaf->right,key);
	else
	{
		if(leaf->left==NULL&&leaf->right==NULL)
		{
			free(leaf);
			leaf=NULL;
			return leaf;
		}
		else if(leaf->left==NULL)
		{
			struct tree* temp=leaf;
			leaf=leaf->right;
			free(temp);
			return leaf;
		}
		else if(leaf->right==NULL)
		{
			struct tree* temp=leaf;
			leaf=leaf->left;
			free(temp);
			return leaf;
		}
		else
		{
			struct tree* temp=findmin(leaf->right);
			leaf->data=temp->data;
			leaf->right=delete(leaf->right,temp->data);
		}
	}
}

void print2d(struct tree* root,int space)
{
	if(root==NULL)
		return;
	space+=5;

	print2d(root->right,space);

	printf("\n");
	for (int i = 5; i < space; ++i)
		printf(" ");
	printf("%d\n",root->data);

	print2d(root->left,space);
}

void main()
{
	int key;
	for(int i=0;i<6;i++){
		scanf("%d",&key);
		root=insert(key,root);
	}

	inorder(root);
	printf("\n");
	delete(root,4);
	inorder(root);
	print2d(root,5);
}



