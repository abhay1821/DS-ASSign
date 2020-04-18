#include <stdio.h>
#include <stdlib.h>


int enque(int arr[],int n,int f,int r)
{
  r = (r+1)%n;
  if(f==r)
  {
    printf("The Array Queue is full\n");
    if(r==0)
    {
      r = n - 1;
    }else
    {
      r--;
    }
  }else
  {
    printf("Enter data for Array Queue:");
    scanf("%d",&arr[r]);
  }

  return r;
}

int deque(int arr[],int n,int f,int r)
{
  if(f==r)
  {
    printf("Array Queue is empty\n");
  }else
  {
       f = (f+1)%n;
       printf("%d\n",arr[f]);
  }
  return f;
}

struct list
{
  struct list *pre;
  int data;
  struct list *next;
}*hd,*ptr;

struct list* DLLenque(struct list* f,struct list* r)
{
  r = r->next;
  if(f==r)
  {
    printf("Doubly-Linked-List Queue is full\n");
    r=r->pre;
  }else
  {
    printf("Enter data for Doubly-Linked-List Queue\n");
    scanf("%d",&(r->data));
  }
  return r;
}

struct list* DLLdeque(struct list* f,struct list* r)
{
  if(f==r)
  {
    printf("Doubly-Linked-List Queue is empty\n");
  }else
  {
       f = f->next;
       printf("Data is %d\n",f->data);
  }
  return f;
}

struct list* create()
{
  struct list * form;
  form = (struct list*)malloc(sizeof(struct list));
  form->pre = ptr;
  return form;
}

void LinkList()
{
  int n;
  printf("Enter no. empty box in Doubly-Linked-List Queue\n");
  scanf("%d",&n);
  for(int i=0;i<=n;i++)
  {
    if(i==0)
    {
    hd = create();
    ptr=hd;
    }else
    {
        ptr->next=create();
        ptr=ptr->next;
    }
  }
  hd->pre=ptr;
  ptr->next=hd;
  ptr=hd;
}


int main()
{
    printf("::::::::::::::::Array-Queue::::::::::::::::\n");
  int n;
  int f=0,r=0;
  printf("Enter no. empty box in Array Queue:");
  scanf("%d",&n);
  n++;
  int arr[n];
  char c;
  do {
    fflush(stdin);
      printf("Enter 'E' for enque, 'D' for deque, 'O' for stop\n");
      scanf("%c",&c);
      if(c == 'E')
        r = enque(arr,n,f,r);
      if(c == 'D')
        f = deque(arr,n,f,r);
  } while(c != 'O');
    printf("::::::::::::::::Doubly-Linked-List-Queue::::::::::::::::\n");
  LinkList();
  struct list *df=hd,*dr=hd;
  char c;
  do {
    fflush(stdin);
      printf("Enter '1' for enque, '2' for deque, '0' for stop\n");
      scanf("%c",&c);
      if(c == '1')
        dr = DLLenque(df,dr);
      if(c == '2')
        df = DLLdeque(df,dr);
  } while(c != '0');

}
