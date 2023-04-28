#include <iostream>
using namespace std;

/* Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K */

void helper(int input[], int size, int k, int output[], int m) { // m is size of output
    if (size == 0) {
        if (k == 0) {
            for (int i=0; i<m; i++) {
                cout<<output[i]<<" ";
            }
        	cout<<endl;
			return;
        } else {
            return;
        }
    }
    helper(input + 1, size - 1, k, output, m);
    output[m] = input[0];
    helper(input + 1, size - 1, k - input[0], output, m + 1);
}

void printSubsetSumToK(int input[], int size, int k) {
    int output[100];
    helper(input, size, k, output, 0);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
