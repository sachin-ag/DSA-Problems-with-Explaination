#include <iostream>
using namespace std;
#include <vector>
// vector is inbuilt dynamic array

int main () {
	vector<int> v; // static
	vector<int> *v2 = new vector<int>; // dynamic
	
	v.push_back(10); // pushes 10 to last index
	v.push_back(20);
	v.push_back(30);
	
	v[1] = 100; // use only for updates !!!
	
	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl << endl;
	
	v[3] = 67; // we can do this sometimes but push_back is vry important as it checks for size, etc.
	// dont use v[i] to make elements
	v[4] = 6344;
	v.push_back(43973); // see what happens in cout
	v.push_back(34834);
	
	cout << v[3] << endl;
	cout << v[4] << endl << endl;
	
	cout << "Size: " << v.size() << endl; // gives no of elements in the vector
	cout << "Capacity: " << v.capacity() << endl << endl; // gives size of underlying dynamic array
	cout << v.at(2) << endl;
	cout << v[5] << endl; // print garbage
	//cout << v.at(5) << endl; // print error
	cout << endl;
	
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}
	
	cout << endl;	
	v.pop_back(); // deletes last element;
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}
	
	return 0;
	}

