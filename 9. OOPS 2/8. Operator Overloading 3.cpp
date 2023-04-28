#include <iostream>
using namespace std;
// in this we will post increment ++ and +=
// this is also uninary operator

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
		
		Fraction& operator++() { // pre increment ++ from prev lecture
			numerator += denominator;
			simplify();
			return *this;
		}
		
		Fraction operator++(int) { // this is how declare post increment ++ function
			Fraction fnew(numerator, denominator); // copying this to fnew
			numerator += denominator;
			simplify();
			fnew.simplify();
			return fnew;
		}
		
		Fraction& operator+=(Fraction const &f) {
			int lcm = this -> denominator * f.denominator;
			int x = lcm/this -> denominator;
			int y = lcm/f.denominator;
			int num = (x*this -> numerator) + (y*f.numerator);
			
			numerator = num;
			denominator = lcm;
			simplify(); // we have added f to this
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
	Fraction f1(10, 2);
	
	Fraction f2 = f1++;
	f1.print();
	f2.print();
	
	int i=5, j=3;
	//nesting is not allowed in post increment for normal things
	//(i++)++; is illegal
	
	(i+=j)+=j; // gives i = i + 2j
	cout<<endl<<i<<" "<<j<<endl<<endl;
	
	f1.print();
	f2.print();
	f1 += f2;
	f1.print();
	f2.print();
	
	//to do nesting return type of += MUST BE "Fraction&" (& is important, see  prev lecture)
	
	cout<<endl;
	(f1+=f2)+=f2;
	f1.print();
	f2.print();
	
	return 0;
	}

