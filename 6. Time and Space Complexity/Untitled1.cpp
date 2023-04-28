#include <iostream>
#include <algorithm>
#include <map>
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

void intersection(int input1[], int input2[], int size1, int size2) {
    mergeSort(input1, size1);
    mergeSort(input2, size2);
    int i=0, j=0;
    while((i<size1)&&(j<size2)) {
        if (input1[i] == input2[j]) {
            cout<<input1[i]<<endl;
            i++;
            j++;
        }
        if (input1[i] < input2[j]) {
            i++;
        }
        if (input1[i] > input2[j]) {
            j++;
        }
    }
}
#include <iostream>
using namespace std;

int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];	
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];	
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	
	intersection(input1,input2,size1,size2);

		
	return 0;
}


