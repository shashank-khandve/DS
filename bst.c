#include<stdio.h>
#include<stdlib.h>
struct bst{
	int data;
	struct bst *left;
	struct bst *right;
};

struct bst *findmin(struct bst *head)
{
	struct bst *temp;
	temp=head;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	printf("%d\n",temp->data);
	return head;
}
struct bst *delete(struct bst *head,int d)
{
		if(head == NULL)
		return head;
		else if (d < head->data)
			head->left = delete(head->left,d);
		else if (d > head->data)
			head->right = delete(head->right,d);
 		else
 		{
 			if(head->left == NULL)
 			{
 				struct bst *temp = head->right;
 				free(head);
 				return temp;
 			
 			}
 			
 			else if(head -> right == NULL)
 			{
 				struct bst *temp = head->left;
 				free(head);
 				return temp;
 			
 			}
 			struct bst *temp = findmin(head->right);
 			head->data = temp->data;
 			head->right=delete(head->right,temp->data);
 		}
 		return head;
}
struct bst *insert(struct bst *head,int d)
{
	
	if(head==NULL)
	{
		head=(struct bst *)malloc(sizeof(struct bst));	
		head->data=d;
		head->left=NULL;
		head->right=NULL;
	}
	else if(head->data < d)
		head->right=insert(head->right,d);
	else if(head->data > d)
		head->left=insert(head->left,d);
	else
		printf("duplicate data\n");
	return head;
}

struct bst *pre(struct bst *head)
{
	static int i=0;
	struct bst *temp=head;
	if(head==NULL && i==0)
	{
		printf("bst is empty\n");
		return head;
	}
	i++;
	if(temp==NULL && i!=0)
		return head;
	printf("%d\t",temp->data);
	temp->left=pre(temp->left);
	temp->right=pre(temp->right);
	return head;
}

struct bst *post(struct bst *head)
{
	static int i=0;
	struct bst *temp=head;
	if(head==NULL && i==0)
	{
		printf("bst is empty\n");
		return head;
	}
	i++;
	if(temp==NULL && i!=0)
		return head;
	temp->left=pre(temp->left);
	temp->right=pre(temp->right);
	printf("%d\t",temp->data);
	return head;
}	
struct bst *in(struct bst *head)
{
	static int i=0;
	struct bst *temp=head;
	if(head==NULL && i==0)
	{
		printf("bst is empty\n");
		return head;
	}
	i++;
	if(temp==NULL && i!=0)
		return head;
	temp->left=pre(temp->left);
	printf("%d\t",temp->data);
	temp->right=pre(temp->right);
	return head;
}	
	
int main ()
{
	int a,b;
	struct bst *p=NULL;
	while (1)
	{
		printf("enter the choice\n1.insert a node\n2.delete a node\n3.pre-order\n4.in-order\n5.post-order\n6.exit\n");
		scanf("%d",&a);
		switch (a)
		{
			case 1:
				printf("enter the data\n");
				scanf("%d",&b);
				p=insert(p,b);
				break;
			case 2:
				printf("enter the element\n");
				scanf("%d",&b);
				p=delete(p,b);
				break;
			case 3:
				p=pre(p);
				break;
			case 4:
				p=in(p);
				break;
			case 5:
				p=post(p);
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("choice is invalid\n");
				continue;
		}
	}
}
