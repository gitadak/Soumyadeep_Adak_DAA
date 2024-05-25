//Finding max and min element in an array using divide and conquer method
#include<stdio.h>

typedef struct
{
	int max;
	int min;
}pair;

pair maxmindivcon(int a[50],int low, int high)
{
	pair result, left, right;
	int mid;
	
	if(low == high)
	{
		result.max = a[low];
		result.min = a[low];
		return result;
	}
	if(high == low+1)
	{
		if(a[low] < a[high])
		{
			result.max = a[high];
			result.min = a[low];
		}
		else
		{
			result.max = a[low];
			result.min = a[high];
		}
		return result;
	}
	mid = (low+high)/2;
	left = maxmindivcon(a,low,mid);
	right = maxmindivcon(a,mid+1,high);
	result.max = (left.max > right.max)?left.max:right.max;
	result.min = (left.min < right.min)?left.min:right.min;
	return result;
}

int main()
{
	int a[50],n,i;
	pair res;
	
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
	
	res = maxmindivcon(a,0,n-1);
	printf("\nMaximum element = %d\nMinimum element = %d",res.max,res.min);
	
	return 0;
}
