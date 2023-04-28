#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray {
	
	private:
		int *data;
		int nextIndex;
		int capacity;
		
	public:
		
		StackUsingArray(int totalSize) {
			data = new int[totalSize];
			nextIndex = 0;
			capacity = totalSize;
		}
		
		int size() {
			return nextIndex;
		}
		
		bool isEmpty() {
			return nextIndex == 0; //shortcut for if-else
		}
		
		void push(int element) {
			if (nextIndex == capacity) {
				cout<<"Stack Full!"<<endl;
				return;
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
	StackUsingArray s(5);
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
	cout<<s.pop()<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.size()<<endl;
	return 0;
	}

