#include <stdio.h>
void sort(int arr[],int tmp[], int low1,int high1,int low2,int high2)
{
	int i,j,k;
	k=i=low1;
	j=low2;
	while(i<=high1 && j<=high2)
	{
		if(arr[i]<=arr[j])
			tmp[k++]=arr[i++];
		else
			tmp[k++]=arr[j++];
	}
	while(i<=high1)
		tmp[k++]=arr[i++];
	while(j<=high2)
		tmp[k++]=arr[j++];
	return;
}
void mix(int arr[],int tmp[],int low,int high)
{
	int i;
	for(i=low;i<=high;i++)
		arr[i]=tmp[i];
	return; 
}	
void merge(int arr[],int low ,int high)
{
	int mid,tmp[100];
	if(low>=high)
		return;
	mid=(low+high)/2;
	merge(arr,low,mid);
	merge(arr,mid+1,high);
	sort(arr,tmp,low,mid,mid+1,high);
	mix(arr,tmp,low,high);
	return;
}	
int main ()
{
	int a,i,arr[100];
	printf("enter the size of array\n");
	scanf("%d",&a);
	printf("enter the elements of array\n");
	for(i=0;i<a;i++)
		scanf("%d",&arr[i]);
	merge(arr,0,a-1);
	for(i=0;i<a;i++)
		printf("%d\t",arr[i]);
}
