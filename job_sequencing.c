//Job sequencing problem
#include<stdio.h>
#define MAX 50

struct obj
{
    int seq;
    int profit;
    int deadline;
};
typedef struct obj obj;

void sortObj(obj a[MAX], int n)
{
    int i,j,flag;
    obj t;

    for(i=1;i<=n;i++)
    {
        flag = 0;
        for(j=1;j<=n-i;j++)
        {
            if(a[j].profit < a[j+1].profit)
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                flag = 1;
            }
        }
        if(!flag)
            return;
    }
}

int max_deadline(obj a[MAX],int n)
{
    int max = a[1].deadline, i;
    for(i=2;i<=n;i++)
        max = a[i].deadline > max ? a[i].deadline : max;
    return max;
}

void sequencing(obj a[MAX],int n)
{
    int i, k, j, netProfit = 0, max_dead;
    obj x[MAX];

    max_dead = max_deadline(a,n);
    for(i=0;i<=max_dead;i++)
    {
        x[i].seq = 0;
        x[i].profit = 0;
        x[i].deadline = i;
    }

    for(i=1;i<=n;i++)
    {
        k = a[i].deadline;
        if(x[k].seq == 0)
        {
            x[k].seq = a[i].seq;
            x[k].profit = a[i].profit;
            netProfit += x[k].profit;
        }
        else
        {
            for(j=1;j<k;j++)
            {
                if(x[j].seq == 0)
                {
                    x[j].seq = a[i].seq;
                    x[j].profit = a[i].profit;
                    netProfit += x[j].profit;
                    break;
                }
            }
        }
    }

    printf("\nJob Sequence:");
    printf("\nSeq     :");
    for(i=1;i<=max_dead;i++)
        printf("%7d",x[i].seq);
    printf("\nProfit  :");
    for(i=1;i<=max_dead;i++)
        printf("%7d",x[i].profit);
    printf("\nDeadline:");
    for(i=1;i<=max_dead;i++)
        printf("%7d",x[i].deadline);
    printf("\nNet Profit = %5d",netProfit);
}

int main()
{
    int i,n;
    obj m[MAX];

    printf("Enter the number of jobs: ");
    scanf("%d",&n);
    printf("Enter the job details...\n");
    m[0].seq = 0;
    m[0].profit = 0;
    m[0].deadline = 0;
    for(i=1;i<=n;i++)
    {
        m[i].seq = i;
        printf("Job %d profit: ",i);
        scanf("%d",&m[i].profit);
        printf("Job %d deadline: ",i);
        scanf("%d",&m[i].deadline);
    }

    sortObj(m,n);
    sequencing(m,n);

    return 0;
}

/*
Output:
------
Enter the number of jobs: 5
Enter the job details...
Job 1 profit: 10
Job 1 deadline: 2
Job 2 profit: 15
Job 2 deadline: 2
Job 3 profit: 10
Job 3 deadline: 1
Job 4 profit: 5
Job 4 deadline: 3
Job 5 profit: 1
Job 5 deadline: 3

Job Sequence:
Seq     :      1      2      4
Profit  :     10     15      5
Deadline:      1      2      3
Net Profit =    30
*/
