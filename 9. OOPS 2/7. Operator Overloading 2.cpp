#include <iostream>
using namespace std;
// ++ has both pre-increment and post-increment in it
// in this we will use pre increment ++
// +, *, == all are binary operators
// ++ is uninary operator

class Fraction {
	private:
		
		int numerator;
		int denominator;
		
	public:
		
		Fraction(int numerator, int denominator) {
			this -> numerator = numerator;
			this -> denominator = denominator;
		}
		
		void print() {
			cout<<numerator<<" / "<<this -> denominator<<endl;
		}
		
		void simplify() {
			int hcf = 1;
			int j = min(this -> numerator, this -> denominator);
			for (int i=1; i<=j; i++) {
				if ((this -> numerator % i == 0) && (this -> denominator % i == 0)) {
					hcf = i;
				}
			}
			this -> numerator = this -> numerator / hcf;
			denominator = denominator / hcf;
		}
		
		//we have to return "Fraction&" and not "Fraction".. reasons in main code
		Fraction& operator++() { // overloading uninary operator ++ (pre-increment)
		//this fn adds 1 to the fraction
			numerator += denominator;
			simplify();
			
			return *this; // as this is a pointer pointing to current object
		}
		
		Fraction const operator+(Fraction const &f) {
			int lcm = this -> denominator * f.denominator;
			int x = lcm/this -> denominator;
			int y = lcm/f.denominator;
			int num = (x*this -> numerator) + (y*f.numerator);
			
			Fraction temp(num, lcm);
			temp.simplify();
			return temp;
		}
		
		Fraction const operator*(Fraction const &f) {
			int n = this -> numerator * f.numerator;
			int d = this -> denominator * f.denominator;
			Fraction temp(n, d);
			temp.simplify();
			return temp;
		}
		
		bool const operator==(Fraction const &f) {
			return((this -> numerator == f.numerator) && (this -> denominator == f.denominator));
		}
};

int main () {
	Fraction f1(10, 4);
	f1.print();
	
	++f1;
	f1.print();
	
	Fraction f3 = ++f1; // cannot be called when ++ is returning void so ++ must return Fraction
	f1.print();
	f3.print();
	
	// if ++  function was set to return just "Fraction":	
	/*
	++(++f1); // here the ++ outside bracket is incrementing a buffer copy of "++f1" and not f1 itself
	f1.print();
	
	Fraction f4 = ++(++f1); // here value of increment of ++f1 is returned but on f1 hv called only ++ once
	f1.print(); // this happens because ++ is called only once on f1 while 2nd ++ is called on a copy of ++f1
	f4.print();
	*/
	
	//when ++ fn is set to return "&Fraction"
	++(++f1);
	f1.print();
	
	Fraction f4 = ++(++f1);
	f1.print();
	f4.print();
	
	return 0;
	}

