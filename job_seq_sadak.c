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
			if(a[j].profit <= a[j+1].profit)
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
	
	printf("Job sequence:\n");
	for(i=1;i<=max;i++)
	{
		printf("%dth hour: Job=%d profit=%d\n",i,m[i].seq,m[i].profit);
	}
	printf("Net profit = %d",total_profit);
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
