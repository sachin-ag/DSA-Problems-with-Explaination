#include <iostream>
using namespace std;
#include <stack>

/* Sachin has been working with an organization called 'Money Traders' for the past few years. 
The organization is into the money trading business. His manager assigned him a task. 
For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days 
(starting from today and going backwards) for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], 
then the stock spans will be [1, 1, 1, 2, 1, 4, 6]. */

int* stockSpan(int *price, int size) {
    int *span = new int[size];
    stack<int> s;
    span[0] = 1;
    s.push(0);
    for (int i=1; i<size; i++) {
        if (price[i] <= price[s.top()]) {
            span[i] = i - s.top();
            s.push(i);
        } else {
            s.pop();
            while (!s.empty()) {
                if (price[i] > price[s.top()]) {
                    s.pop();
                } else {
                    break;
                }
            }
            if (s.empty()) {
                s.push(i);
                span[i] = i + 1;
                continue;
            } else {
                span[i] = i - s.top();
                s.push(i);
            }
        }
    }
    return span;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
