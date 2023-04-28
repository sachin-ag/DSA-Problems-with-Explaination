#include <cstring>
#include <iostream>
using namespace std;
/* Edit Distance of two strings is minimum number of 
operations required to make one string equal to other. 
In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character */

int editDistance(string s1, string s2) {
    if (s1 == s2) return 0;
    if (s1.size() == 0) return s2.size(); // remove all remaining char in s2
    if (s2.size() == 0) return s1.size(); // remove all remaining char in s1
    if (s1[0] == s2[0]) return editDistance(s1.substr(1), s2.substr(1));
    int i, d, r;
    i = 1 + editDistance(s1.substr(1), s2);
    d = 1 + editDistance(s1, s2.substr(1));
    r = 1 + editDistance(s1.substr(1), s2.substr(1));
    return min(i, min(d, r));
}

int editDistanceMemoHelp(string s1, string s2, int** output, int i, int j) {
    if (s1 == s2) return 0;
    if (i == s1.size()) return s2.size() - j;
    if (j == s2.size()) return s1.size() - i;
    if (output[i][j] != -1) return output[i][j];
    if (s1[i] == s2[j]) {
        output[i][j] = editDistanceMemoHelp(s1, s2, output, i + 1, j + 1);
        return output[i][j];
    }
    int ins, d, r;
    ins = 1 + editDistanceMemoHelp(s1, s2, output, i + 1, j);
    d = 1 + editDistanceMemoHelp(s1, s2, output, i, j + 1);
    r = 1 + editDistanceMemoHelp(s1, s2, output, i + 1, j + 1);
    output[i][j] = min(ins, min(d, r));
    return output[i][j];
}
int editDistanceMemo(string s1, string s2) {
    int** output = new int*[s1.size()];
    for (int i=0; i<s1.size(); i++) {
        output[i] = new int[s2.size()];
    }
    for (int i=0; i<s1.size(); i++) {
        for (int j=0; j<s2.size(); j++) {
            output[i][j] = -1;
        }
    }
    return editDistanceMemoHelp(s1, s2, output, 0, 0);
}

int editDistanceDP(string s1, string s2) {
    int** output = new int*[s1.size()+1];
    for (int i=0; i<=s1.size(); i++) {
        output[i] = new int[s2.size()+1];
    }
    for (int i=s1.size(); i>=0; i--) {
        for (int j=s2.size(); j>=0; j--) {
            if (i == s1.size()) {output[i][j] = s2.size() - j; continue;}
            if (j == s2.size()) {output[i][j] = s1.size() - i; continue;}
            if (s1[i] == s2[j]) {output[i][j] = output[i+1][j+1]; continue;}
            int ins, del, rep;
            ins = 1 + output[i+1][j];
            del = 1 + output[i][j+1];
            rep = 1 + output[i+1][j+1];
            output[i][j] = min(ins, min(del, rep));
        }
    }
    return output[0][0];
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
    cout << editDistanceMemo(s1, s2) << endl;
    cout << editDistanceDP(s1, s2) << endl;
    return 0;
}