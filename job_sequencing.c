//Job sequencing problem

#include<stdio.h>

struct job
{
	int seq;
	int profit;
	int deadline;
};
typedef struct job job;

void job_sort(job a[50],int n)
{
	int i,j,flag;
	job t;
	
	for(i=0; i<n-1; i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j].profit < a[j+1].profit)
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				flag=1;
			}
		}
		if(flag == 0)
			return;
	}
}

int max_deadline(job a[50],int n)
{
	int i,max_dead=a[0].deadline;
	for(i=1;i<n;i++)
	{
		if(a[i].deadline > max_dead)
			max_dead=a[i].deadline;
	}	
	
	return max_dead;
}

void job_sequence(job a[50],int n,int max)
{
	int i,j,k,total_profit=0;
	job m[50];
	
	for(i=0;i<=max;i++)
	{
		m[i].seq=0;
		m[i].profit=0;
		m[i].deadline=i;
	}
	
	for(i=0;i<n;i++)
	{
		k=a[i].deadline;
		if(m[k].seq == 0)
		{
			m[k].seq=a[i].seq;
			m[k].profit=a[i].profit;
			total_profit+=m[k].profit;
		}
		else
		{
			for(j=1;j<k;j++)
			{
				if(m[j].seq==0)
				{
					m[j].seq=a[i].seq;
					m[j].profit=a[i].profit;	
					total_profit+=m[j].profit;	
					break;	
				}
			}
		}
	}
	
	printf("Job sequence:");
    	printf("\nHour  :");
	for(i=1;i<=max;i++)
	{
		printf("%5d",i);
	}
   	printf("\nJob   :");
	for(i=1;i<=max;i++)
	{
		printf("%5d",m[i].seq);
	}
    	printf("\nProfit:");
	for(i=1;i<=max;i++)
	{
		printf("%5d",m[i].profit);
	}
	printf("\nNet profit = %d",total_profit);
}

int main()
{
	int i,n,max;
	job a[50];
	
	printf("Enter the no. of jobs: ");
	scanf("%d",&n);
	
	printf("Enter the details of job:\n");
	for(i=0;i<n;i++)
	{
		a[i].seq=i+1;
		printf("Job %d profit: ",i+1);
		scanf("%d",&a[i].profit);
		printf("Job %d deadline: ",i+1);
		scanf("%d",&a[i].deadline);		
	}
	
	job_sort(a,n);
	max=max_deadline(a,n);
	job_sequence(a,n,max);
	
	return 0;
}
/*
Output:
------
Enter the no. of jobs: 5
Enter the details of job:
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
Job sequence:
Hour  :    1    2    3
Job   :    1    2    4
Profit:   10   15    5
Net profit = 30
*/
