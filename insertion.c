#include<stdio.h>
int main ()
{
	int i,j,k,tmp,arr[100];
	printf("enter the size of array\n");
	scanf("%d",&k);
	printf("enter the elements of array\n");
	for(i=0;i<k;i++)
		scanf("%d",&arr[i]);
	for(j=1;j<k;j++)
	{
		tmp=arr[j];
		for(i=j-1;i>=0 && tmp<arr[i];i--)
			arr[i+1]=arr[i];
		arr[i+1]=tmp;
	}
	for(i=0;i<k;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}
