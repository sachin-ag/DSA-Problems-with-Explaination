#include <iostream>
using namespace std;
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
		
		Fraction const add(Fraction const &f) {
			int lcm = this -> denominator * f.denominator;
			int x = lcm/this -> denominator;
			int y = lcm/f.denominator;
			int num = (x*this -> numerator) + (y*f.numerator);
			
			Fraction temp(num, lcm);
			temp.simplify();
			return temp;
		}
		
		Fraction const operator+(Fraction const &f) { // + operator overloading, 
			//left of + is this and right of + is argument
			int lcm = this -> denominator * f.denominator;
			int x = lcm/this -> denominator;
			int y = lcm/f.denominator;
			int num = (x*this -> numerator) + (y*f.numerator);
			
			Fraction temp(num, lcm);
			temp.simplify();
			return temp;
		}
		
		Fraction const multiply(Fraction const &f) {
			int n = this -> numerator * f.numerator;
			int d = this -> denominator * f.denominator;
			Fraction temp(n, d);
			temp.simplify();
			return temp;
		}
		
		Fraction const operator*(Fraction const &f) { // * operator overloading
			//left of * is this and right of * is argument
			int n = this -> numerator * f.numerator;
			int d = this -> denominator * f.denominator;
			Fraction temp(n, d);
			temp.simplify();
			return temp;
		}
		
		bool const operator==(Fraction const &f) { // == operator overloading
			//left of == is this and right of == is argument
			return((this -> numerator == f.numerator) && (this -> denominator == f.denominator));
		}
};

int main () {
	Fraction f1(10, 2);
	Fraction f2(15, 4);
	
	Fraction f3 = f1.add(f2);
	f1.print();
	f2.print();
	f3.print();
	
	Fraction f4 = f1 + f2;
	f4.print();
	
	f3 = f1.multiply(f2);
	f4 = f1 * f2;
	f3.print();
	f4.print();
	
	Fraction f5 = f4;
	f5.print();
	
	if(f1 == f2) {
		cout<<"equal"<<endl;
	} else {
		cout<<"not equal"<<endl;
	}
	
	if(f5 == f3) {
		cout<<"equal"<<endl;
	} else {
		cout<<"not equal"<<endl;
	}
	
	return 0;
	}

