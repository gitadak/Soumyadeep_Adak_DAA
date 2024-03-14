//Merge sort
#include<stdio.h>

void merge(int a[50],int lb,int mid,int ub)
{
	int i=lb,j=mid+1,b[50],k=lb;//k=0
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];	
	while(j<=ub)
		b[k++]=a[j++];	
	/*i=lb;
	for(j=0;j<k;j++)
	{
		a[i]=b[j];
		i++;	
	}*/
	k=lb;
	while(k<=ub)
	{
		a[k]=b[k];
		k++;	
	}
	return;
}

void merge_sort(int a[50],int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		merge_sort(a,lb,mid);
		merge_sort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
	return;
}

int main()
{
    int n,i,a[50];

    printf("\nEnter the no. of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d] = ",i+1);
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    printf("\nThe sorted array:\n");
    for(i=0;i<n;i++)
        printf("%5d",a[i]);

    return 0;
}
