//Recursive binary search
#include<stdio.h>
int rec_binary_search(int arr[50],int item,int low,int high)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==item)
            return mid;
        else if(item>arr[mid])
            return rec_binary_search(arr,item,mid+1,high);
        else
            return rec_binary_search(arr,item,low,mid-1);
    }
    return -1;
}

void display(int arr[50],int n)
{
    int i;
    printf("The array:\n");
    for(i=0;i<n;i++)
        printf("%3d",arr[i]);
    return;
}

void status(int pos,int item)
{
    if(pos!=-1)
        printf("Position of %d is %d",item,pos+1);
    else
        printf("Not Found");
    return;
}

int main()
{
    int a[50],n,i,d,pos;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    display(a,n);
    
    printf("\nEnter the element to be searched: ");
    scanf("%d",&d);
    pos=rec_binary_search(a,d,0,n-1);
    status(pos,d);
    
    return 0;
}
    
