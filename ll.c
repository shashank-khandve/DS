#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
	};
struct node *beg(struct node *head,int d)
{
	if(head==NULL)
	{
		head=(struct node *)malloc (sizeof(struct node));
		head->link=NULL;
		head->data=d;
		return head;
	}
	struct node *temp;
	temp=(struct node *)malloc (sizeof(struct node));
	temp->link=head;
	temp->data=d;
	return temp;
}
struct node *end(struct node *head,int d)
{
	if(head==NULL)
	{
		head=(struct node *)malloc (sizeof(struct node));
		head->link=NULL;
		head->data=d;
		return head;
	}
	struct node *temp1,*temp=head;
	while(temp->link!=NULL)
		temp=temp->link;
	temp1=(struct node *)malloc (sizeof(struct node));	
	temp1->link=NULL;
	temp1->data=d;
	temp->link=temp1;
	return head;
}
struct node *mid(struct node *head,int d,int b)
{
	struct node *temp1,*temp=head;
	if(b==0)
	{
		temp1=(struct node *)malloc(sizeof(struct node));
		temp1->link=head;	
		temp1->data=d;
		return temp1;
	}
	if(head==NULL)
	{
		printf("linked list is empty\n")
;		return head;
	}
	int count=1;
	while(temp!=NULL && b>=count)
	{
		if(b==(count))
		{
			temp1=(struct node *)malloc(sizeof(struct node));
			temp1->link=temp->link;	
			temp->link=temp1;
			temp1->data=d;
			return head;
		}
		temp=temp->link;
		count++;
	}
	printf("given index is invalid\n");
	return head;
}
void display(struct node *head)
{
	struct node *tmp=head;
	if(head==NULL)
	{
		printf("linked list is empty\n");
		return ;		
	}
	while(tmp!=NULL)
	{
		printf("%d\t",tmp->data);
		tmp=tmp->link;
	}
	printf("\n");
	return ;
}
struct node *first(struct node *head)
{
	if(head==NULL)
	{
		printf("linked list is empty\n");
		return head;
	}
	struct node *temp=head;
	head=head->link;
	free(temp);
	return head;
}
struct node *last(struct node *head)
{
	if(head==NULL)
	{
		printf("linked list is empty\n");
		return head;
	}
	struct node *temp1,*temp=head;
	if(temp->link==NULL)
	{
		free(temp);
		head=NULL;
		return head;
	}
	while(temp->link->link!=NULL)
		temp=temp->link;
	temp1=temp->link;
	temp->link=NULL;
	free(temp1);
	return head;
}
struct node *dmid(struct node *head,int a)
{
	if(head==NULL)
	{
		printf("linked list is empty\n");
		return head;
	}
	struct node *temp1,*temp=head;
	int b=1;
	if(a==0)
	{
		head=head->link;
		free(temp);
		return head;
	}
	while(temp->link!=NULL)
	{
		if(a==b)
		{
			temp1=temp->link;
			temp->link=temp->link->link;
			free(temp1);
			return head;
		}
		temp=temp->link;
		b++;
	}
	printf("index is invalid\n");
	return head;
}
struct node *reverse(struct node *head)		
{
	if(head==NULL)
	{
		printf("linked list i sempty\n");
		return head;
	}
	if(head->link==NULL)
		return head;
	struct node *prev=NULL;
	struct node *current=head;
	struct node *next;
	while(current != NULL)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;
	}
	return prev;
}
	
int main ()
{
	struct node *head=NULL;
	int a,b,c;
	while(1)
	{
		printf("enter the choice\n1.insert at begining\n2.insert at end\n3.insert at middle\n4.delete first node\n5.delete last node\n6.delete node\n7.reverse\n8.display\n9.exit\n");
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
				head=first(head);
				break;
			case 5:
				head=last(head);
				break;
			case 6:
				printf("enter the index to be deleted\n");
				scanf("%d",&b);
				head=dmid(head,b);
				break;
			case 7:
				head=reverse(head);
				break;
			case 8:
				display(head);
				break;
			case 9:
				exit(6);
				break;
			default:
				printf("entered choice is invalid\n");
				continue;
		}
	}
}
