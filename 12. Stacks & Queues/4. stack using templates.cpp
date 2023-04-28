#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class StackUsingArray {
	
	private:
		T *data;
		int nextIndex;
		int capacity;
		
	public:
		
		StackUsingArray() {
			data = new T[4];
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
				T *newData = new T[capacity + 1];
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
		
		T pop() {
			if (isEmpty()) {
				cout<<"Stack is Empty!"<<endl;
				return 0;
			}
			nextIndex--;
			return data[nextIndex];
		}
		
		T top() {
			if (isEmpty()) {
				cout<<"Stack is Empty!"<<endl;
				return 0;
			}
			return data[nextIndex - 1];
		}
		
};

int main () {
	StackUsingArray<char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	s.push(105);
	cout<<s.top()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.size()<<endl;
	return 0;
	}

