#include<iostream>
using namespace std;

//method 1
int lastIndex1(int input[], int size, int x) {
    if (size==0)
        return -1;
    if (input[size-1]==x)
        return size - 1;
    int temp = lastIndex1(input, size - 1, x);
    if (temp == -1)
        return -1;
    else
        return temp;
}

//method 2
int lastIndex2(int input[], int size, int x) {
    if (size == 0)
        return -1;
    int temp = lastIndex2(input + 1, size - 1, x);
    if (temp == -1) {
        if (input[0] == x)
            return 0;
        else return -1;
    }
    else
        return temp + 1;
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
    
    cout << lastIndex1(input, n, x) << endl;
    cout << lastIndex2(input, n, x) << endl;

}



