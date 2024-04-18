//Activity selection problem
#include<stdio.h>

struct job
{
	int seq;
	int start;
	int end;
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
			if(a[j].end > a[j+1].end)
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

void job_selection(job a[50],int n)
{
	int i,j,count=1,x=0, final[50];
	
	final[x]=a[0].seq;
	x++;
	j=0;
	for(i=1; i<n; i++)
	{
		if(a[i].start >= a[j].end)
		{
			final[x]=a[i].seq;
			x++;
			j=i;
			count++;
		}
	}
	
	printf("The max no. of jobs can be completed= %d",count);
	printf("\nThe jobs are:\n");
	for(i=0; i<count; i++)
		printf("%3d",final[i]);
}

int main()
{
	int i,n;
	job m[50];
	
	printf("Enter the no. of jobs: ");
	scanf("%d",&n);
	
	printf("Enter the starting and ending times of the jobs:\n");
	for(i=0;i<n;i++)
	{
		m[i].seq=i+1;
		printf("Job %d start time: ",i+1);
		scanf("%d",&m[i].start);
		printf("Job %d end time: ",i+1);
		scanf("%d",&m[i].end);		
	}
	
	job_sort(m,n);
	job_selection(m,n);
	
	return 0;
}
