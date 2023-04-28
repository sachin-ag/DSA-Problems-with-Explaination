#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray {
	
	private:
		int *data;
		int nextIndex;
		int capacity;
		
	public:
		
		StackUsingArray() {
			data = new int[4];
			nextIndex = 0;
			capacity = 4;
		}
		
		int size() {
			return nextIndex;
		}
		
		bool isEmpty() {
			return nextIndex == 0; //shortcut for if-else
		}
		
		void push(int element) {
			if (nextIndex == capacity) {
				int *newData = new int[capacity + 1];
				for (int i=0; i<capacity; i++) {
					newData[i] = data[i];
				}
				delete [] data;
				data = newData;
				capacity += 1;
			}
			data[nextIndex] = element;
			nextIndex++;
		}
		
		int pop() {
			if (isEmpty()) {
				cout<<"Stack is Empty!"<<endl;
				return INT_MIN;
			}
			nextIndex--;
			return data[nextIndex];
		}
		
		int top() {
			if (isEmpty()) {
				cout<<"Stack is Empty!"<<endl;
				return INT_MIN;
			}
			return data[nextIndex - 1];
		}
		
};

int main () {
	StackUsingArray s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	cout<<s.top()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.size()<<endl;
	return 0;
	}

