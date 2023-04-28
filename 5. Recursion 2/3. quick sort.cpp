#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int s, int e) {
    int c = s;
    for (int i=s+1; i<=e; i++) {
        if (a[s] >= a[i]) {
            c++;
        }
    }
    swap(&a[s], &a[c]);
    int i = s, j = e;
    while(i<c && j>c) {
        if(a[i] <= a[c]) {
            i++;
        } else if(a[j] > a[c]) {
            j++;
        } else {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    return c;
}

void quickSort(int input[], int s, int e) {
    if (s >= e) {
        return;
    }
	int c = partition(input, s, e);
    quickSort(input, s, c-1);
    quickSort(input, c+1, e);
}

void quickSort(int input[], int size) {
    quickSort(input, 0, size-1);
}


int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    } 
    delete [] input;
    return 0;
}

