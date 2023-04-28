#include <iostream>
using namespace std;

void Merge(int l[], int r[], int a[], int n1, int n2) {
	int i = 0, j = 0, k = 0;
	while ((i<n1)&&(j<n2)) {
		if (l[i] < r[j]) {
			a[k++] = l[i++];
		} else {
			a[k++] = r[j++];
		}
	}
	while (i<n1) {
		a[k++] = l[i++];
	}
	while (j<n2) {
		a[k++] = r[j++];
	}
}

void mergeSort(int input[], int size){
    if (size<=1) {
        return;
    } else {
        int m = size/2;
        int a[m];
        int b[size-m];
        for (int i=0; i<m; i++) {
            a[i] = input[i];
        }
        for (int i=m; i<size; i++) {
            b[i-m] = input[i];
        }
        mergeSort(a, m);
        mergeSort(b, size-m);
        Merge(a, b, input, m, size-m);
    }
}

int max(int a[], int n) {
    int t = a[0];
    for (int i=1; i<n; i++) {
        if (a[i] > t) {
            t = a[i];
        } else continue;
    }
    return t;
}

int maximumProfit(int budget[], int n) {
    mergeSort(budget, n);
    int a[n];
    for (int i=0; i<n; i++) {
        a[i] = (n - i)*budget[i];
        
    }
    return max(a, n);
}


int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}

