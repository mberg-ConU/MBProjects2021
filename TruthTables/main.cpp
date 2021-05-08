//main.cpp
//using MyBool objects, outputs a truth table for a Boolean function
//next challenge: figure out how to allow user to enter input?
#include "MyBool.h"
using namespace std;

int main()
{
    MyBool a, b, c, d, F;

    cout << "a" << setw(10) << "b" << setw(10) << "c" << setw(10) << "d" << setw(10) << "F" << endl;
    //output labels for each column

    //now, iterate over each MyBool object, trying every possible combination
    for(int i = 0;i <= 1;i++)
    {
        a = MyBool(i);
        for(int j = 0;j <= 1;j++)
        {
            b = MyBool(j);
            for(int k = 0;k <= 1;k++)
            {
                c = MyBool(k);
                for(int m = 0; m <= 1;m++)
                {
                    d = MyBool(m);
                    F = a*b + c*!d + a; //arbitrary function, would work with anything
                    cout << a << setw(10) << b << setw(10) << c << setw(10) << d << setw(10) << F << endl;
                    //output value of each MyBool object
                }
            }
        }
    }
    return 0;
}
