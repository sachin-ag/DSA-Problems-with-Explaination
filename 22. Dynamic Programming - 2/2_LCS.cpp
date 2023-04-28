#include <iostream>
using namespace std;
#include <string>
// LCS is Longest Common Subsequence
// common subsequence bw two strings have same order but may not be continuos

int LCS(string a, string b) {
    if ((a.size() == 0) || (b.size() == 0)) return 0;

    // if first character is same
    if (a[0] == b[0]) return 1 + LCS(a.substr(1), b.substr(1));

    // if first character is diff
    int x = LCS(a.substr(1), b); // removing first char of string a
    int y = LCS(a, b.substr(1)); // removing first char of string b
    return max(x, y);
}

int LCS_memo_help(string a, string b, int** output, int i, int j) {
    if ((i > a.size() - 1) || (j > b.size() - 1)) return 0;
    if (output[i][j] != -1) return output[i][j];
    if (a[i] == b[j]) {
        output[i][j] = 1 + LCS_memo_help(a, b, output, i + 1, j + 1);
        return output[i][j];
    }
    int x = LCS_memo_help(a, b, output, i + 1, j);
    int y = LCS_memo_help(a, b, output, i, j + 1);
    output[i][j] = max(x, y);
    return output[i][j];
}
int LCS_memo(string a, string b) {
    int **output = new int*[a.size()];
    for (int i=0; i<a.size(); i++) {
        output[i] = new int[b.size()];
    }
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<b.size(); j++) {
            output[i][j] = -1;
        }
    }
    return LCS_memo_help(a, b, output, 0, 0);
}

int LCS_dp(string a, string b) {
    int **output = new int*[a.size()];
    for (int i=0; i<a.size(); i++) {
        output[i] = new int[b.size()];
    }
    for (int i=a.size()-1; i>=0; i--) {
        for (int j=b.size()-1; j>=0; j--) {
            output[i][j] = 0;
            if (a[i] == b[j]) {
                output[i][j]++;
                if ((i < a.size() - 1) && (j < b.size() - 1)) {
                    output[i][j] += output[i+1][j+1];
                }
                continue;
            }
            int x = 0, y = 0;
            if (i < a.size() - 1) x = output[i+1][j];
            if (j < b.size() - 1) y = output[i][j+1];
            output[i][j] += max(x, y);
        }
    }
    return output[0][0];
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << LCS(a, b) << endl;
    cout << LCS_memo(a, b) << endl;
    cout << LCS_dp(a, b) << endl;
    return 0;
}