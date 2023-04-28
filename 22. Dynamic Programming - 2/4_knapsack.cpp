#include <iostream>
using namespace std;
/* A thief robbing a store can carry a maximal weight of W into his knapsack. 
There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' 
What would be the maximum value V, that the thief can steal? */

int knapsack(int *weights, int *values, int n, int maxWeight) {
    if (n == 0 || maxWeight == 0) return 0;
    int a = 0;
    if (weights[0] <= maxWeight) {
        a = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
    }
    int b = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    return max(a, b);
}

int knapsackMemoHelp(int *weights, int *values, int n, int maxWeight, int **output, int i) {
    if (n == 0 || maxWeight == 0) return 0;
    cout << output[i][maxWeight] << " hehe ";
    if (output[i][maxWeight] != -1) return output[i][maxWeight];
    int a = 0;
    if (weights[0] <= maxWeight) {
        a = values[0] + knapsackMemoHelp(weights + 1, values + 1, n - 1, maxWeight - weights[0], output, i + 1);
    }
    int b = knapsackMemoHelp(weights + 1, values + 1, n - 1, maxWeight, output, i + 1);
    cout << a <<"   " << b << endl;
    output[i][maxWeight] = max(a, b);
    return output[i][maxWeight];
}
int knapsackMemo(int *weights, int *values, int n, int maxWeight) {
    int** output = new int*[n];
    for (int i=0; i<n; i++) {
        output[i] = new int[maxWeight+1];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<maxWeight+1; j++) {
            output[i][j] = -1;
        }
    }
    return knapsackMemoHelp(weights, values, n, maxWeight, output, 0);
}

int knapsackDP(int *weights, int *values, int n, int maxWeight) {
    int** output = new int*[n+1];
    for (int i=0; i<n+1; i++) {
        output[i] = new int[maxWeight+1];
    }
    for (int i=n; i>=0; i--) {
        for (int j=0; j<=maxWeight; j++) {
            if (i == n || j == 0) {output[i][j] = 0; continue;}
            int a = 0;
            if (weights[i] <= j) a = values[i] + output[i+1][j-weights[i]];
            int b = output[i+1][j];
            output[i][j] = max(a, b);
        }
    }
    return output[0][maxWeight];
}

int main() {
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;
    cout << knapsackMemo(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}