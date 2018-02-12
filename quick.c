#include <stdio.h>
void quick(int arr[],int low,int high)
{
	int pivot,i,j,tmp;
	pivot=arr[low];
	i=low+1;
	j=high;
	if(low>=high)
		return;
	while(i<=j && j>=i)
	{
		for(;arr[j]>pivot;j--);
		for(;arr[i]<pivot;i++);
		if(i<j)
		{
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
		}
	}
	arr[low]=arr[j];
	arr[j]=pivot;
	quick(arr,low,j-1);
	quick(arr,j+1,high);
	return;
}	
int main ()
{
	int i,a,arr[100];
	printf("enter the size of array\n");
	scanf("%d",&a);
	printf("enter the elements of array\n");
	for(i=0;i<a;i++)
		scanf("%d",&arr[i]);
	quick(arr,0,a-1);
	for(i=0;i<a;i++)
		printf("%d\t",arr[i]);
}
