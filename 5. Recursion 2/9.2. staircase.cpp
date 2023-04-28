#include <iostream>
using namespace std;

/* A child is running up a staircase with N steps, 
and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the 
child can run up to the stairs. 
You need to return number of possible ways W. */

int staircase(int n){
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    int a = 0, b = 0, c = 0;
    if (n > 2) {
        a = staircase(n - 1);
        b = staircase(n - 2);
        c = staircase(n - 3);
    } else if (n == 2) {
        a = staircase(n - 1);
        b = staircase(n - 2);
    } else {
        a = staircase(n - 1);
    }
    return a + b + c;
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}

