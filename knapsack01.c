#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int weights[], int profits[], int n, int W) {
    int i, w;
    int K[n+1][W+1];
    int selectedItems[MAX_ITEMS] = {0};

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i-1] <= w)
                K[i][w] = max(profits[i-1] + K[i-1][w-weights[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
// Find items included in the knapsack
    int j = n, k = W;
    while (j > 0 && k > 0) {
        if (K[j][k] != K[j-1][k]) {
            selectedItems[j-1] = 1;
            k -= weights[j-1];
        }
        j--;
    }
// Print total profit and selected items
    printf("Total Profit: %d\n", K[n][W]);
    printf("Array specifying the Selected items(if selected then value at that index is 1 ,otherwise 0):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", selectedItems[i]);
    }
    printf("\n");
}

int main() {
    int n, W;
    int weights[MAX_ITEMS], profits[MAX_ITEMS];
// Input number of items and weight of knapsack
   printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight of the knapsack: ");
    scanf("%d", &W);
// Input weights and profits of items
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter the profits of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }
// Solve knapsack problem
    knapsack(weights, profits, n, W);
    return 0;
}

/*
Output:
------
Enter the number of items: 4
Enter the weight of the knapsack: 8
Enter the weights of the items:
2
3
4
5
Enter the profits of the items:
1
2
5
6
Total Profit: 8
Array specifying the Selected items(if selected then value at that index is 1 ,otherwise 0):
0 1 0 1 
*/