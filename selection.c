#include <stdio.h>
int main ()
{
	int i,j,k,tmp,a,arr[100];
	printf("enter the size of array\n");
	scanf("%d",&a);
	printf("enter the elements of array\n");
	for(i=0;i<a;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<a;i++)
	{
		tmp=arr[i];
		k=0;
		for(j=i+1;j<a;j++)
		{
			if(tmp>arr[j])
			{
				tmp=arr[j];
				k=j;
			}
		}
		if(k!=0)
		{
			arr[k]=arr[i];
			arr[i]=tmp;
		}
	}
	for(i=0;i<a;i++)
		printf("%d\t",arr[i]);
}	
