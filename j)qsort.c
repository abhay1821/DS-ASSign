#include <stdio.h>

void swap(int arr[],int i,int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}


int partition(int arr[],int low,int high)
{
  swap(arr,low,high);
  int pivot = arr[high];
  int i = low-1;
  for(int j=low;j<high;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(arr,j,i);
    }
  }
  swap(arr,high,i+1);
  return i+1;
}


void quick_sort(int arr[],int low,int high)
{
  if(low<high)
  {
    int pi = partition(arr,low,high);
    
      quick_sort(arr,pi+1,high);
      quick_sort(arr,low,pi-1);
  }
}



void selection_sort(int arr[],int n)
{
    printf("Sorted Array is(Selection Method):");
    for(int i=0;i<n;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
                min = j;
        }
        swap(arr,i,min);
    }
}


int main()
{
    printf("::::::::::::::Quick-Sorting::::::::::::::\n");
    int n;
    printf("Enter Size of Array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Data of Array:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Sorted Array is(Quick Sorting):");
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);

    printf("::::::::::::::Selection-Sorting::::::::::::::\n");
    printf("Enter Size of Array Again:");
    scanf("%d",&n);
    
    printf("Enter Data of Array Again:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    selection_sort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);

}

