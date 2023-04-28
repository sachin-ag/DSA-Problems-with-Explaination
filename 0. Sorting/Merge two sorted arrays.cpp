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

int main () {
	int a[4] = {2, 3, 4, 7};
	int b[6] = {1, 48, 79, 87, 95, 102};
	int c[10];
	Merge(a, b, c, 4, 6);
	for (int i=0; i<10; i++) {
		cout<<c[i]<<" ";
	}
	return 0;
	}

