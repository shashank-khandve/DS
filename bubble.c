#include <stdio.h>
int main ()
{
	int a[100],b,i,temp,j;
	printf("enter the size of array\n");
	scanf("%d",&b);
	printf("enter the elements of array\n");
	for(i=0;i<b;i++)
		scanf("%d",&a[i]);
	for(j=b-1;j>=0;j--)
	{
		for(i=0;i<j;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
	for(i=0;i<b;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
