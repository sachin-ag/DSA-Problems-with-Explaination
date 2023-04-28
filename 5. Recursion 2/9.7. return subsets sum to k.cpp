#include <iostream>
using namespace std;

/* Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K */

int subsetSumToK(int input[], int n, int output[][50], int k) {
    if (n == 0) {
    	if (k == 0) {
            return 1;
        } else {
            return 0;
        }
    } 
    int output1[500][50], output2[500][50];
    int a = subsetSumToK(input + 1, n - 1, output1, k); //a=no. of such subsets
    int b = subsetSumToK(input + 1, n - 1, output2, k - input[0]);
    for (int i=0; i<b; i++) {
        for (int j=1; j<50; j++) {
            output2[i][j+1] = output2[i][j];
        }
        output2[i][1] = input[0];
        output2[i][0] += 1;
    }
    for (int i=0; i<a; i++) {
        for (int j=0; j<50; j++) {
            output[i][j] = output1[i][j];
        }
    }
    for (int i=a; i<a+b; i++) {
        for (int j=0; j<50; j++) {
            output[i][j] = output2[i-a][j];
        }
    }
	return a + b;
}

int main() {
  int input[20],length, output[1000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin >> k;
  int size = subsetSumToK(input, length, output, k);
  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}


