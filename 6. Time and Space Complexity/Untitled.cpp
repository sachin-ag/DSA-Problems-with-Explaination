#include <iostream>
using namespace std;

void rotate(int *input, int d, int n) {
    if (d<1) {
        return;
    }
    int temp = input[0];
    for(int i=0; i<n-1; i++) {
        input[i] = input[i+1];
    }
    input[n-1] = temp;
    rotate(input, d-1, n);
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}

