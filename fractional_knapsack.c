//Fractional Kanpsack

#include<stdio.h>

struct obj
{
    int seq;
    int profit;
    int weight;
    float pw_ratio;
};
typedef struct obj obj;

struct obj_knapsack
{
    int seq;
    int weight;
    float profit;
    float fraction;
};
typedef struct obj_knapsack obj_knapsack;

void obj_sort(obj a[50],int n)
{
	int i,j,flag;
	obj t;
	
	for(i=1; i<=n; i++)
	{
		flag=0;
		for(j=1;j<=n-i;j++)
		{
			if(a[j].pw_ratio < a[j+1].pw_ratio)
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

void knapsack_filling(obj a[50],int n,int m)
{
    obj_knapsack x[50];
    int rem_capacity=m,i,k,net_weight=0;
	float net_profit=0.0;

	for(i=0;i<=n;i++)
	{
    	x[i].seq=i;
		x[i].profit=0.0;
		x[i].weight=0;
		x[i].fraction=0.0;
	}

	for(i=1;i<=n;i++)
	{
		if(rem_capacity == 0)
			break;

		k=a[i].seq;
		if(a[i].weight <= rem_capacity)
		{
			x[k].weight = a[i].weight;
			x[k].fraction = 1;
			x[k].profit = a[i].profit;
			rem_capacity -= a[i].weight;
		}
		else
		{
			x[k].weight = rem_capacity;
			x[k].fraction = rem_capacity/(float)a[i].weight;
			x[k].profit = a[i].profit*x[k].fraction;
			rem_capacity = 0;			
		}
		net_weight+=x[k].weight;
		net_profit+=x[k].profit;
	}

	printf("The Knapsack:");
	printf("\nObject  :");
	for(i=1;i<=n;i++)
	{
		printf("%7d",x[i].seq);
	}
	printf("\nFraction:");
	for(i=1;i<=n;i++)
	{
		printf("%7.2f",x[i].fraction);
	}
	printf("\nWeight  :");
	for(i=1;i<=n;i++)
	{
		printf("%7d",x[i].weight);
	}
	printf("\nProfit  :");
	for(i=1;i<=n;i++)
	{
		printf("%7.2f",x[i].profit);
	}

	printf("\nNet weight = %d\nNet profit = %.2f",net_weight,net_profit);
}

int main()
{
	obj bag[50];
	int capacity,i,n;

	bag[0].seq=0;
	bag[0].weight=0;
	bag[0].profit=0;
	bag[0].pw_ratio=0.0;

	printf("Enter the capacity of the knapsack: ");
	scanf("%d",&capacity);
	printf("Enter the number of objects: ");
	scanf("%d",&n);
	printf("Enter the object details...\n");
	for(i=1;i<=n;i++)
	{
		bag[i].seq=i;
		printf("Object %d weight = ",i);
		scanf("%d",&bag[i].weight);
		printf("Object %d profitt = ",i);
		scanf("%d",&bag[i].profit);
		bag[i].pw_ratio=bag[i].profit/(float)bag[i].weight;
	}

	obj_sort(bag,n);
	knapsack_filling(bag,n,capacity);

	return 0;
}

/*
Output:
------
Enter the capacity of the knapsack: 15
Enter the number of objects: 7
Enter the object details...
Object 1 weight = 2
Object 1 profitt = 10
Object 2 weight = 3
Object 2 profitt = 5
Object 3 weight = 5
Object 3 profitt = 15
Object 4 weight = 7
Object 4 profitt = 7
Object 5 weight = 1
Object 5 profitt = 6
Object 6 weight = 4
Object 6 profitt = 18
Object 7 weight = 1
Object 7 profitt = 3
The Knapsack:
Object  :      1      2      3      4      5      6      7
Fraction:   1.00   0.67   1.00   0.00   1.00   1.00   1.00
Weight  :      2      2      5      0      1      4      1
Profit  :  10.00   3.33  15.00   0.00   6.00  18.00   3.00
Net weight = 15
Net profit = 55.33
*/
