#include <iostream>
using namespace std;

class Polynomial {
	
	private:
		
		int capacity;
	
	public:
		
		int *degCoeff;
		
		Polynomial() {
			degCoeff = new int[1];
			this -> degCoeff[0] = 0;
			capacity = 1;
		}
		
		Polynomial(Polynomial const &p) {
			this -> capacity = p.capacity;
			this -> degCoeff = new int[capacity];
			for (int i=0; i<capacity; i++) {
				this -> degCoeff[i] = p.degCoeff[i];
			}
		}
		
		void operator=(Polynomial const &p) {
			this -> capacity = p.capacity;
			this -> degCoeff = new int[capacity];
			for (int i=0; i<capacity; i++) {
				this -> degCoeff[i] = p.degCoeff[i];
			}
		}
		
		void setCoefficient(int i, int coeff) {
			if (i >= capacity) {
				int *newdegCoeff = new int[i + 1];
				for (int j=0; j<i+1; j++) {
					newdegCoeff[j] = 0;
				}
				for (int j=0; j<capacity; j++) {
					newdegCoeff[j] = degCoeff[j];
				}
				delete [] degCoeff;
				degCoeff = newdegCoeff;
				capacity = i+1;
			}
			degCoeff[i] = coeff;
		}
		
		Polynomial operator+(Polynomial const &p) {
			Polynomial newp;
			newp.capacity = max(this -> capacity, p.capacity);
			newp.degCoeff = new int[newp.capacity];
			for (int i=0; i<newp.capacity; i++) {
				newp.degCoeff[i] = 0;
			}
			for (int i=0; i<min(this -> capacity, p.capacity); i++) {
				newp.degCoeff[i] = this -> degCoeff[i] + p.degCoeff[i];
			}
			if (this -> capacity > p.capacity) {
				for (int i=p.capacity; i<this -> capacity; i++) {
					newp.degCoeff[i] = this -> degCoeff[i];
				}
			} else if (this -> capacity < p.capacity) {
				for (int i=this -> capacity; i<p.capacity; i++) {
					newp.degCoeff[i] = p.degCoeff[i];
				}
			}
			return newp;
		}
		
		Polynomial operator-(Polynomial const &p) {
			Polynomial newp;
			newp.capacity = max(this -> capacity, p.capacity);
			newp.degCoeff = new int[newp.capacity];
			for (int i=0; i<newp.capacity; i++) {
				newp.degCoeff[i] = 0;
			}
			for (int i=0; i<min(this -> capacity, p.capacity); i++) {
				newp.degCoeff[i] = this -> degCoeff[i] - p.degCoeff[i];
			}
			if (this -> capacity > p.capacity) {
				for (int i=p.capacity; i<this -> capacity; i++) {
					newp.degCoeff[i] = this -> degCoeff[i];
				}
			} else if (this -> capacity < p.capacity) {
				for (int i=this -> capacity; i<p.capacity; i++) {
					newp.degCoeff[i] = -1*p.degCoeff[i];
				}
			}
			return newp;
		}
		
		Polynomial operator*(Polynomial const &p) {
			Polynomial newp;
			newp.capacity = this -> capacity + p.capacity;
            newp.degCoeff = new int[newp.capacity];
			for (int i=0; i<newp.capacity; i++) {
				newp.degCoeff[i] = 0;
			}
			for (int i=0; i<this -> capacity; i++) {
				for (int j=0; j<p.capacity; j++) {
					newp.degCoeff[i + j] += this -> degCoeff[i] * p.degCoeff[j];
				}
			}
			return newp;
		}
		
		void const print() {
			for (int i=0; i<capacity; i++) {
				if (this -> degCoeff[i] != 0) {
					cout<<this -> degCoeff[i]<<"x"<<i<<" ";
				}
			}
			cout<<endl;
		}		
};

int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    first.print();
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    second.print();
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}

