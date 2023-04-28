#include <iostream>
using namespace std;

class dynamicArray {
	
	private:
		
		int *data;
		int nextIndex;
		int capacity;
	
	public:
		
		dynamicArray() {
			data = new int[5];
			nextIndex = 0;
			capacity = 5;
		}
		
		dynamicArray(dynamicArray const &d) { // copy constructor to do deep copy
			this -> nextIndex = d.nextIndex;
			this -> capacity = d.capacity;
			this -> data = new int[capacity];
			for (int i=0; i<nextIndex; i++) {
					this -> data[i] = d.data[i];
				}
		}
		
		void operator=(dynamicArray const &d) { // copy assignment operator using deep copy
			this -> nextIndex = d.nextIndex;
			this -> capacity = d.capacity;
			this -> data = new int[capacity];
			for (int i=0; i<nextIndex; i++) {
					this -> data[i] = d.data[i];
				}
		}
		
		void add(int element) {
			if (nextIndex == capacity) {
				int *newdata = new int[2*capacity];
				for (int i=0; i<nextIndex; i++) {
					newdata[i] = data[i];
				}
				delete [] data;
				data = newdata;
				capacity *= 2;
			}
			data[nextIndex] = element;
			nextIndex++;
		}
		
		int const get(int i) {
			if (i < nextIndex) {
				return data[i];
			} else {
				return -1;
			}
		}
		
		void add(int i, int element) {
			if(i < nextIndex) {
				data[i] = element;
			} else if (i == nextIndex) {
				add(element);
			} else {
				return;
			}
		}
		
		void const print() {
			for(int i=0; i<nextIndex; i++) {
				cout<<data[i]<<" ";
			}
			cout<<endl;
		}
		
};

int main () {
	dynamicArray d1;
	
	d1.add(10);
	d1.add(20);
	d1.add(30);
	d1.add(40);
	d1.add(50);
	d1.add(60);
	
	d1.print();
	cout<<endl;
	
	dynamicArray d2(d1); // copy constructor
	d1.add(1, 100);
	d1.print();
	d2.print();
	cout<<endl;
	
	dynamicArray d3;
	d3 = d1;
	d3.add(2, 55);
	d1.print();
	d3.print();
	
	return 0;
}
