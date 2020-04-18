#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*head;

void createnode(int n)
{
     int data;
     head=(struct node*)malloc(sizeof(struct node));
     if(head==NULL)
     {
         printf("Memory not allocated");
         return;
     }
     printf("\nEnter node data : ");
     scanf("%d",&data);
     head->data=data;
     head->prev=NULL;
     head->next=NULL;
     struct node *temp=head;
    	for(int i=2;i<=n;i++)
 	    {
        	struct node *newnode=(struct node*)malloc(sizeof(struct node));
        	if(newnode==NULL)
   			{
        		printf("Memory not allocated");
        		break;
    		}
    		printf("\nEnter node data : ");
    		scanf("%d",&data);
    		newnode->data=data;
    		newnode->next=NULL;
    		newnode->prev=temp;
    		temp->next=newnode;
    		temp=temp->next;
 		}
}

void insertatindex(int index)
{
	int data;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
		  if(newnode==NULL)
   			{
        		printf("Memory not allocated");
        		return;
    		}
    	printf("\nEnter node data : ");
    	scanf("%d",&data);
    	newnode->data=data;
        if(index==1)
        {
            newnode->next=head;
            newnode->prev=NULL;
            head=newnode;
        }
        struct node *temp=head;
    for(int i=2;i<index;i++)
        temp=temp->next;
    	newnode->next=temp->next;
    	newnode->prev=temp;
    	temp->next=newnode;
}

void deletefromindex(int index)
{
    struct node *temp=head;
    if(index==1)
    {
        head=temp->next;
        free(temp);
        return;
    }
    for(int i=2;i<index;i++)
        temp=temp->next;
    struct node *temp1=temp->next->next;
    free(temp->next);
    temp->next=temp1;
}
void disp(struct node *h )
{
  while(h)
  {
    printf("%d ",h->data);
    h=h->next;
  }

}
int main()
{
  int n;
  printf("Enter the no of nodes to enter :");
  scanf("%d",&n);
  createnode(n);
  disp(head);

}
