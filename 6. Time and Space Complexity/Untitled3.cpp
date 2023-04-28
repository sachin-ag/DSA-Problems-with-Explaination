#include <iostream>
using namespace std;

#define min(n1, n2) ((n1<=n2) ? n1 : n2)
#define max(n1, n2) ((n1>=n2) ? n1 : n2)

int max2(int a, int b, int c) {
    int t = max(a, b);
    t = max(t, c);
    return t;
}
int min2(int a, int b, int c) {
    int t = min(a, b);
    t = min(t, c);
    return t;
}
void FindTriplet(int arr[], int size, int x) {
    if (size < 2) {
        return;
    }
    for (int i=0; i<size; i++) {
        int j = 0;
		for (j<size; j!=i; j++) {
            int k = 0;
            for (k<size; k!=j; k++) {
                if (k != i) {
                    if (arr[i] + arr[j] + arr[k] == x) {
                        int sum = arr[i] + arr[j] + arr[k];
                        int sum1 = max2(arr[i], arr[j], arr[k]) + min2(arr[i], arr[j], arr[k]);
                        cout<<min2(arr[i], arr[j], arr[k])<<" "<<sum-sum1<<" "<<max2(arr[i], arr[j], arr[k]);
                    }
                }
            }
        }
    }

}

int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);
		
	return 0;
}


