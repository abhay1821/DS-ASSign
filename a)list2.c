
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
}*first;

void create(int A[], int n)
{
  struct node *p, *t;
  p=(struct node*)malloc(sizeof(struct node));
  p->data=A[0];
  p->link=NULL;
  first = p;

  for(int i=1; i<n; i++)
  {
    t=(struct node*)malloc(sizeof(struct node));;
    t->data = A[i];
    t->link = NULL;
    p->link = t;
    p=t;
  }
}

void display(struct node *p)
{
  while(p)
  {
    printf("%d ",p->data);
    p=p->link;
  }
}

void insertBegin(int x)
{
  struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  p->data = x;
  p->link = first;
  first = p;
}

void take(int A[], int n)
{
  for(int i=0; i<n; i++)
  {
    scanf("%d",&A[i]);
  }
}

void main()
{
  int n; //make a variable to store the number of nodes
  printf("The number of inputs:\n");
  scanf("%d",&n); //get the number of nodes
  int A[n];
  printf("Give the inputs:");
  take(A,n);
  create(A,n);
  display(first);
  insertBegin(472);
  printf("\n");
  display(first);
}
