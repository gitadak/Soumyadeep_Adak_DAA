//Finding max and min element in an array using non-recursive method
#include<stdio.h>

void minmax(int a[50],int n,int *max, int *min)
{
	int i;
	*max = a[0], *min = a[0];
	
	for(i=1;i<n;i++)
	{
		if(a[i] > *max)
			*max = a[i];
		if(a[i] < *min)
			*min = a[i];
	}
}

int main()
{
	int a[50],n,i,max,min;
	
	printf("\nEnter the no. of elements: ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("arr[%d] = ",i+1);
		scanf("%d",&a[i]);
	}
	
	
	printf("The array:\n");
	for(i=0;i<n;i++)
		printf("%3d",a[i]);
	
	minmax(a,n,&max,&min);
	printf("\nMaximum element = %d\nMinimum element = %d",max,min);
	
	return 0;
}
