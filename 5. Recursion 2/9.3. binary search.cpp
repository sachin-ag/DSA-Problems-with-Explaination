#include <iostream>
using namespace std;

/* Given an integer sorted array (sorted in increasing order) and an element x, 
find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :
Line 1 : Array size
Line 2 : Array elements (separated by space)
Line 3 : x (element to be searched) */


int flag = 0; //to check whether it is found or not,otherwise -1 will be returned and it will get mixed
int binarySearch(int input[], int size, int x) {
    if (size == 0) {
        return -1;
    }
    int mid = size/2;
    int a;
    if (input[mid] == x) {
    	flag = 1;
        a = mid;
    } else if(input[mid] > x) {
        a = binarySearch(input, mid, x);
    } else {
        a = binarySearch(input + mid + 1, size - mid - 1, x) + mid + 1;
    }
    if (flag != 0) {
    	return a;
	} else {
		return -1;
	}
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }
    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}

