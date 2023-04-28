#include<iostream>
using namespace std;

//method 1
int firstIndex1(int input[], int size, int x) {
	if (size==0)
        return -1;
    if (input[0]==x)
        return 0;
    int temp = firstIndex1(input + 1, size - 1, x);
    if (temp == -1)
        return temp;
    else
        return temp + 1;
}

//method 2
int firstIndex2(int input[], int size, int x) {
	if (size == 0)
        return -1;
    int temp = firstIndex2(input, size - 1, x);
    if (temp ==-1) {
        if (input[size - 1] == x)
            return size - 1;
        else return -1;
    }
    else
        return temp;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << firstIndex1(input, n, x) << endl;
	cout << firstIndex2(input, n, x) << endl;

}
