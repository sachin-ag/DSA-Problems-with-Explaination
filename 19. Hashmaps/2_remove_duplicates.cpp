#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
// given an array, return a vector made up of unique elements from that array

vector<int> remove_duplicates(int* a, int n) {
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i=0; i<n; i++) {
        if (seen.count(a[i]) > 0) {
            continue;
        } else {
            output.push_back(a[i]);
            seen[a[i]] = true;
        }
    }
    return output;
}

int main () {
    int a[] = {1, 2, 5, 2, 3, 5, 6, 1, 9, 4, 6};
    vector<int> v = remove_duplicates(a, 11);
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}