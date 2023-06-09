#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


double geometricSum(int k) {
	if (k == 0)
        return 1;
    double temp = geometricSum(k-1);
    double temp2 = 1/pow(2, k);
    return temp + temp2;

}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}

