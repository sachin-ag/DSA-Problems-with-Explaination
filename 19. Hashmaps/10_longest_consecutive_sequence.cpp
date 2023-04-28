#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>

/* You are given an array of unique integers that contain numbers in random order. 
You have to find the longest possible sequence of consecutive numbers using the 
numbers from given array. You need to return the output array which contains starting 
and ending element. If the length of the longest possible sequence is one, then the 
output array must contain only single element. */

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int, bool> temp;
    for (int i=0; i<n; i++) {
        pair<int, bool> temp2;
        temp2.first = arr[i];
        temp2.second = true;
        temp.insert(temp2);
    }
    int startElement = 0;
    int endElement = 0;
    int size = 0;
    for (int i=0; i<n; i++) {
        if (temp[arr[i]] == false) {
            continue;
        }
        int tempElement = arr[i];
        int tempSize = 1;
        while (temp[tempElement + 1] == true) {
            temp[tempElement + 1] = false;
            tempElement += 1;
            tempSize +=1;
        }
        int tempEnd = tempElement;
        tempElement = arr[i];
        while (temp[tempElement - 1] == true) {
            temp[tempElement - 1] = false;
            tempElement -=1;
            tempSize += 1;
        }
        int tempStart = tempElement;
        if (tempSize > size) {
            size = tempSize;
            startElement = tempStart;
            endElement = tempEnd;
        }
    }
    vector<int> ans;
    if (startElement == endElement) {
        ans.push_back(startElement);
        return ans;
    }
    ans.push_back(startElement);
    ans.push_back(endElement);
    return ans;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}