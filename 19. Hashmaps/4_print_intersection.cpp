#include <iostream>
#include <algorithm>
using namespace std;
#include <unordered_map>
#include <vector>

void intersection(int *arr1, int *arr2, int n, int m) {
	unordered_map<int, int> map2;
    vector<int> ans;
	for (int i=0; i<m; i++) {
		map2[arr2[i]]++;
	}
	for (int i=0; i<n; i++) {
		if (map2.count(arr1[i]) > 0) {
			if (map2[arr1[i]] > 0) {
				ans.push_back(arr1[i]);
				map2[arr1[i]]--;
			}
		}
	}
    sort(ans.begin(), ans.end());
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}