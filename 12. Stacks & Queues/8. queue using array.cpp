#include <iostream>
using namespace std;

template <typename T>
class Queue {
	
	T *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;
	
	public:
		
		Queue(int capacity) {
			data = new T[capacity];
			nextIndex = 0;
			firstIndex = -1;
			this -> size = 0;
			this -> capacity = capacity;
		}
		
		int getSize() {
			return size;
		}
		
		bool isEmpty() {
			return size == 0;
		}
		
		void enqueue(T element) {
			if (size == capacity) {
				cout<<"Queue is full!"<<endl;
				return;
			}
			data[nextIndex] = element;
			nextIndex = (nextIndex + 1) % capacity; 
			if (firstIndex == -1) {
				firstIndex++;
			}
			size++;
		}
		
		T front() {
			if (firstIndex == -1) {
				cout<<"Queue is empty!"<<endl;
				return 0;
			}
			return data[firstIndex];
		}
		
		T dequeue() {
			if (firstIndex == -1) {
				cout<<"Queue is empty!"<<endl;
				return 0;
			}
			T ans = data[firstIndex];
			firstIndex = (firstIndex + 1) % capacity;
			size--;
			if (size == 0) {
				firstIndex = -1;
				nextIndex = 0;
			}
			return ans;
		}
		
};

int main () {
	Queue<int> q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	
	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.getSize()<<endl;
	cout<<q.isEmpty()<<endl;
	
	return 0;
	}

