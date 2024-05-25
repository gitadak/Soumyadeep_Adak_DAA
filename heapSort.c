//Heap Sort
#include<stdio.h>

void shiftDown(int numbers[],int root,int bottom)
{
    int flag,maxChild,temp;

    flag=1;
    while (((root)*2+1 <= bottom) && (flag==1))
    {
        if (root*2+1 == bottom)
            maxChild = root*2+1;
        else if (numbers[root*2+1] > numbers[root*2+2])
            maxChild = root*2+1;
        else
            maxChild = root*2+2;
        
        if(numbers[root] < numbers[maxChild])
        {
            temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else
            flag=0;
    }
}

void heapsort(int numbers[],int n)
{
    int i,temp;

    for(i=(n/2)-1;i>=0;i--)  //((n/2)-1) is the first non-leaf node from end
        shiftDown(numbers,i,n-1);
    
    for(i=n-1;i>=1;i--)
    {
        temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        shiftDown(numbers,0,i-1);
    }
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
    heapsort(a,n);
    printf("\nThe sorted array:\n");
    for(i=0;i<n;i++)
        printf("%5d",a[i]);

    return 0;
}