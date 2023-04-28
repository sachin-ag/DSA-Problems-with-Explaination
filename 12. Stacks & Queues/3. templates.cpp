#include <iostream>
using namespace std;

template <typename T, typename V>

class Pair {
	T x;
	V y;
	
	public:
		
		void setX(T x) {
			this -> x = x;
		}
		
		T getX() {
			return x;
		}
		
		void setY(V y) {
			this -> y = y;
		}
		
		V getY() {
			return y;
		}
};

int main () {
	Pair<int, int> p1; // all T will be replaced by int
	
	Pair<double, double> p2;
	
	p1.setX(10);
	p1.setY(20);
	cout<<p1.getX()<<endl;
	cout<<p1.getY()<<endl<<endl;
	
	p2.setX(100.345);
	p2.setY(-59.678);
	cout<<p2.getX()<<endl;
	cout<<p2.getY()<<endl<<endl;
	
	Pair<int, double> p3;
	
	p3.setX(100.345);
	p3.setY(100.345);
	cout<<p3.getX()<<endl;
	cout<<p3.getY()<<endl<<endl;
	
	//creating a triplet class from a pair class:
	Pair<Pair<int, int>, int> p4;
	Pair<int, int> p5;
	p5.setX(12);
	p5.setY(75);
	p4.setX(p5);
	p4.setY(93);
	cout<<p4.getX().getX()<<endl;
	cout<<p4.getX().getY()<<endl;
	cout<<p4.getY()<<endl;
	
	return 0;
	}

