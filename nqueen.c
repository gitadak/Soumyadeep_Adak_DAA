#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 30

int position[SIZE]={0}; /*position[3]=2 means the third queen is on the second column  
/*The index represents the row(the queen), the value represents the column*/

int place(int k){ /*returns 1 if the place is safe */
	int i;
	for(i=1;i<k;i++){ /*from the first row to the current row-1*/
	    if((position[i]==position[k])||((abs(position[i]-position[k])==abs(i-k)))) /*if same column or same diagonal*/
	    	return 0;
	}
	return 1;
}
void print_sol(int n){ /*This funciton prints the solution*/
	int i,j;
	printf("\n\n The solution: \n" );	
	for(i=1;i<=n;i++){
	    for(j=1;j<=n;j++){
	        if(position[i]==j) /*If the ith queen is stored at the current column j*/
	            printf("Q\t");
	        else
	            printf("*\t");
	        }
	    printf("\n");
	}
}
int queen(int k, int n){ /*k is number of current queen and n is the total queens number*/
	if (k==0) /*No valid solution condition*/
		return 0;
	position[k]=position[k]+1; /*Move to the next column*/
	while((position[k]<=n)&&!place(k)){ /*if we still have columns left and the place is not valid keep checking the next columns*/
	    position[k]++;
	}
	if(position[k]<=n){ /*if the queen is safely placed*/
	    if(k==n){ /*if all queens are placed print solution*/
	        print_sol(n);
	        return 1;
	    }
	    else{
	        /*Move to the next queen*/
			position[++k]=0; /*Start from the leftmost column*/
	        queen(k,n);
	    }
	}
	else
	    queen(k-1,n); /*backtrack to change the previous queen's place*/
}
/***Recursive function to calculate factorial***/

int main(){
	int n;
	printf("Enter the number of Queens:\n");
	scanf("%d",&n);
	if(!queen(1,n)) /*1 is for the first queen*/
		printf("\n No valid solution!\n");
	return 0;
}

/*
Output:
------
Enter the number of Queens:
8


 The solution: 
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*/