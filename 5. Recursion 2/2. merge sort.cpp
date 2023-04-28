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


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
  return 0;
}

