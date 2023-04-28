#include <iostream>
using namespace std;

//method 1
int allIndexes1(int input[], int size, int x, int output[]) {
    if (size == 0)
        return 0;
    int temp = allIndexes1(input + 1, size - 1, x, output);
    for (int i=0; i<temp; i++)
        output[i] += 1;
    if (x == input[0]) {
        for (int i=0; i<temp; i++)
            output[temp - i] = output[temp - i - 1];
        output[0] = 0;
        return temp + 1;
    }
    else return temp;
}

//method 2
int allIndexes2(int input[], int size, int x, int output[]) {
    if (size == 0)
        return 0;
    int temp = allIndexes2(input, size - 1, x, output);
    if (x == input[size - 1]) {
        output[temp] = size - 1;
        return temp + 1;
	}
    else return temp;
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
    
    int *output = new int[n];
    
    int size = allIndexes1(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    cout<<endl<<endl;
    
    size = allIndexes2(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    
}

