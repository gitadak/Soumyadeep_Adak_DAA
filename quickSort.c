//Quick sort
//Quick Sort
#include<stdio.h>

void swap(int *a,int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int position(int x[],int low,int high)
{
    int i,j,t,flag = 1,pos = low;

    while(flag == 1)
    {
        for(i = high;i > pos;i--)
        {
            flag = 0;
            if(x[pos] > x[i])
            {
                swap(&x[pos],&x[i]);
                pos = i;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            for(i = low;i < pos;i++)
            {
                flag = 0;
                if(x[pos] < x[i])
                {
                    swap(&x[pos],&x[i]);
                    pos = i;
                    flag = 1;
                    break;
                }
            }
        }
    }
    return pos;
}

void qSort(int x[],int low,int high)
{
    int pivot;

    if(low < high)
    {
        pivot = position(x,low,high);
        qSort(x,low,pivot-1);
        qSort(x,pivot+1,high);
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
    qSort(a,0,n-1);
    printf("\nThe sorted array:\n");
    for(i=0;i<n;i++)
        printf("%5d",a[i]);

    return 0;
}
