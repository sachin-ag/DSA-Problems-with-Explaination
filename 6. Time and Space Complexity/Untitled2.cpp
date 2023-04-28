#include <iostream>
using namespace std;

#define min(n1, n2) ((n1<=n2) ? n1 : n2)
#define max(n1, n2) ((n1>=n2) ? n1 : n2)
void pairSum(int input[], int size, int x) {
    if (size < 2) {
        return;
    }
    for (int i=0; i<size; i++) {
        int j = 0;
		for (j<size; j!=i; j++) {
           if (input[i] + input[j] == x) {
            cout<<min(input[i], input[j])<<" "<<max(input[i], input[j])<<endl;
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
	pairSum(input,size,x);
		
	return 0;
}


