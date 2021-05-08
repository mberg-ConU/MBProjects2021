
#include <cmath>
#include <iostream>
#include <fstream>
#ifndef MYCOMP
#define MYCOMP

#define PI 3.14159265358979323846
using namespace std;

class complexNum
{
private:
    double Re; //real part of the number
    double Im; //imaginary part of the number
    double mag; //magnitude of the number
    double theta; //angle between vector in complex plane and the real axis
public:
    complexNum(double, double); //builds an object using rectangular form
    complexNum(); //empty constructor necessary to create copies of objects
    void printpol(); //used to print the polar form
    complexNum get_comp_conj();
    //we will overload these operators, and they must be friend functions so we can access the attributes
    friend complexNum operator*(const complexNum &num1, const complexNum &num2);
    friend complexNum operator+(const complexNum &num1, const complexNum &num2);
    friend complexNum operator/(const complexNum &num1, const complexNum &num2);
    friend complexNum operator-(const complexNum &num1, const complexNum &num2); //for subtraction
    friend complexNum operator-(const complexNum &num2); //to create the opposite of a number
    friend ostream &operator<<(ostream &out, const complexNum &num);
};

#endif // MYCOMP
