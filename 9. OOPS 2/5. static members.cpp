#include <iostream>
using namespace std;
// "::" is called scope resolution operator

class Student {
	public:
		
		int age;
		int rollNumber;
		
		static int totalStudents; //total no. of students
		// !!! - static property cannot be initialized here
		// by doing static this property belongs to the class and is same for each object
		// static property is not copied. it is the same memory used by every member of class
		
		Student() {
			totalStudents++; //increment totalStudents by 1 every time an obeject is created
		}
		
		int getrollNumber() { // by default non-static
			return rollNumber;
		}
		
		static int gettotalStudents() { // must to declare static
			return totalStudents; // returning static property
		} // static fn can ONLY access static members and functions
		// static fn cannot use "this"!
};

int Student :: totalStudents = 0; //initialize static data members like this

int main () {
	Student s1;
	cout<<s1.rollNumber <<endl;
	cout<<s1.age <<endl;
	
	cout<<Student :: totalStudents <<endl;
	
	cout<<s1.totalStudents <<endl;
	s1.totalStudents += 20; // can be done
	
	Student s2, s3, s4, s5;
	cout<<s2.totalStudents<<endl;
	
	cout<<Student :: gettotalStudents(); // call static functions of a class
	
	return 0;
	}

