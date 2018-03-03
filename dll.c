#include <stdio.h>
#include <stdlib.h>
struct node{
	int d;
	struct node *l;
	struct node *r;
	};
struct node *beg(struct node *head,int data)
{
	struct node *temp;
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->l=NULL;
		head->r=NULL;
		head->d=data;
		return head;
	}
	temp=(struct node *)malloc(sizeof(struct node));
	temp->l=NULL;
	temp->r=head;
	temp->d=data;
	head->l=temp;
	return temp;
}
struct node *end(struct node *head,int data)
{
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->l=NULL;
		head->r=NULL;
		head->d=data;
		return head;
	}
	struct node *temp,*temp1=head;
	while(temp1->r!=NULL)
		temp1=temp1->r;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->l=temp1;
	temp->r=NULL;
	temp->d=data;
	temp1->r=temp;
	return head;
}
struct node *mid(struct node *head,int data,int a)
{
	int count=1;
	struct node *temp;
	struct node *temp1=head;
	if(a==0)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->l=NULL;
		temp->r=head;
		temp->d=data;
		head->l=temp;
		return temp;
	}
	while(temp1!=NULL && a>=count)
	{
		if(a==count)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->l=temp1;
			temp->r=temp->r;
			temp->d=data;
			temp1->r=temp;
			return head;
		}
		temp1=temp1->r;
		count++;
	}
	printf("entered index is invalid\n");
	return head;
}
void display(struct node *head)
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d\t",temp->d);
		temp=temp->r;
	}
	printf("\n");
	return;
}					
int main ()
{
	int a,b,c;
	struct node *head=NULL;
	while(1)
	{
		printf("enter your choice\n1.insert at begining\n2.insert at end\n3.insert at mid\n4.display\n5.delete first\n6.delete last\n7.delete at mid\n8.exit\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("enter the data\n");
				scanf("%d",&b);
				head=beg(head,b);
				break;
			case 2:
				printf("enter the data\n");
				scanf("%d",&b);
				head=end(head,b);
				break;
			case 3:
				printf("enter the data and index\n");
				scanf("%d%d",&b,&c);
				head=mid(head,b,c);
				break;
			case 4:
				display(head);
				break;
			case 5:
				//head=first(head);
				break;
			case 6:
				//head=last(head);
				break;
			case 7:
				printf("enter the index\n");
				scanf("%d",&b);
				//head=dmid(head);
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("entered choice is invalid\n");
				continue;
		}
	}
}
			
