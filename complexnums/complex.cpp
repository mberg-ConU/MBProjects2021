#include "complex.h"


complexNum::complexNum(double real, double imag)
{
    //use arguments of imaginary and real parts to create a complex number
    Re = real;
    Im = imag;
    //use necessary formulas to also generate the magnitude and angle of the complex number
    mag = sqrt(Re*Re + Im*Im);
    if (Re > 0)
    {
        theta = atan(Im/Re)*180/PI;
    }
    else
    {
        if(Im > 0)
            theta = atan(Im/Re)*180/PI + 180;
        else
            theta = atan(Im/Re)*180/PI - 180;
    }


}

complexNum::complexNum()
{
    //we need a default "empty" constructor to allow us to create copies in the program
    Re = 0;
    Im = 0;
    mag = 0;
    theta = 0;

}

void complexNum::printpol()
{

    cout << "The polar form of this number is " << mag << " with angle " << theta << " degrees" << endl;
}

complexNum operator*(const complexNum &num1, const complexNum &num2)
{
    double newRe, newIm;
    //these formulas obtained by FOILing the rectangular form of the numbers
    newRe = num1.Re * num2.Re - num1.Im * num2.Im;
    newIm = num1.Re * num2.Im + num1.Im * num2.Re;

    complexNum prod(newRe, newIm);
    return prod;
}

complexNum operator+(const complexNum &num1, const complexNum &num2)
{
    double newRe, newIm;
    //add up real and imaginary parts
    newRe = num1.Re + num2.Re;
    newIm = num1.Im + num2.Im;

    complexNum sum(newRe, newIm);
    return sum;

}

complexNum operator/(const complexNum &num1, const complexNum &num2)
{
    double newRe, newIm;
    //using cmath functions introduces some error, use rectangular forms
    complexNum conj_of_num2(num2.Re, -num2.Im);
    //since num2 is const, we cannot use the function I created.
    complexNum temporary = num1 * conj_of_num2;

    //this comes from the mathod used to divide complex numbers: we multiply the numerator and denominator by the complex conjugate of the denominator
    //on the "bottom", this simply gives the magnitude of the denominator
    newRe = temporary.Re / (num2.mag*num2.mag);
    newIm = temporary.Im / (num2.mag*num2.mag);
    complexNum quot(newRe, newIm);

    return quot;
}
complexNum operator-(const complexNum &num2)
{
    //we overload the minus sign to create negative numbers using it
    double newRe, newIm;
    newRe = -num2.Re;
    newIm = -num2.Im;
    complexNum neg(newRe, newIm);
    return neg;
}

complexNum operator-(const complexNum &num1, const complexNum &num2)
{
    //we need to overload the subtraction operator
    //this will require using the overloaded addition operator and the subtraction operator overloaded for one argument
    complexNum temp1 = num1;
    complexNum temp2 = num2;
    return temp1 + (-temp2);
}
ostream &operator<<(ostream &out, const complexNum &num)
{
    //we overload the left bit shift operator to show the complex numbers easily
    //the if statements are used to make the formatting correct and easy to read

    if (num.Re == 0)
        out << num.Im << "i";
    else if(num.Im > 0)
        out << num.Re << " + " << num.Im << "i";
    else if(num.Im < 0)
        out << num.Re << " - " << -num.Im << "i";
    else if(num.Im == 0)
        out << num.Re;

    return out;
}

complexNum complexNum::get_comp_conj()
{
    double newIm;
    newIm = -Im;
    complexNum conj(Re, newIm);
    return conj;
}
