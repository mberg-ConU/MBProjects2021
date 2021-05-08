//Matthew Bergeron
//The following program was created to test the complex number class and the overloaded operators created in complex.h and complex.cpp



#include <iostream>
#include "complex.h"
using namespace std;

//to make it easier to create a complex number with user input
//this function returns a complex number after getting user input
complexNum makeNum()
{
    double Real, Imaginary;
    cout << "Enter real part of your number: ";
    cin >> Real;
    cout << "Enter imaginary part of your number: ";
    cin >> Imaginary;
    complexNum toReturn(Real, Imaginary);
    return toReturn;
}

//to avoid rewriting the same code over and over again to obtain the complex numbers we need
void GetNums(complexNum &num1, complexNum &num2, complexNum &answer, bool haveanswer, bool needtwonums)
{
    if(haveanswer)
        {
            char rchoice;
            cout << "Use result of last calculation? (Y/N) ";
            cin >> rchoice;
            if(rchoice == 'Y')
            {
                num1 = answer;
            }
            else
            {
                cout << "Enter first number:\n";
                num1 = makeNum();
            }
        }
        else
        {
            cout << "Enter first number:\n";
            num1 = makeNum();
        }
        if(needtwonums)
        {
            cout << "Enter second number:\n ";
            num2 = makeNum();
        }
}
//division is a special case, we need to make sure they have the option to use the result as the divisor
void GetNumsforDivision(complexNum &num1, complexNum &num2, complexNum &answer, bool haveanswer, bool needtwonums)
{
    if(haveanswer)
        {
            char rchoice;
            int dchoice;
            cout << "Use result of last calculation? (Y/N) ";
            cin >> rchoice;

            if(rchoice == 'Y')
            {
            cout << "Do you want to divide by result (enter 1) or divide result by other number (enter 2)";
            //give option to divide by last result or divide last result by something else
            cin >> dchoice;
            if(dchoice == 2)
            {
                num2 = answer;
            }
            if(dchoice == 1)
            {
                num1 = answer;
            }

            }
            else
            {
                cout << "Enter first number: \n";
                num1 = makeNum();
            }
        }
        else
        {
            cout << "Enter first number:\n";
            num1 = makeNum();
        }
        if(needtwonums)
        {
            cout << "Enter second number:\n";
            num2 = makeNum();
        }
}


int main()
{
    bool haveresult = false; //we have not obtained any results yet
    char opchoice;

    cout << "Welcome to the complex number calculator!\n";
    cout << "Enter desired operation\n*: multiplication\n/: division\n+: addition\n-: subtraction\nC: complex conjugate\nP: print polar form\nE: exit calculator\n";

    complexNum num1, num2, result;
    double Re1, Im1, Re2, Im2;

    cin >> opchoice;
    while (opchoice != 'E')//while loop runs until the user enters the exit character
    {
    switch(opchoice) //switch statement allows user to select desired operation
    {

    //in each case, we put my overloaded operators to the test
    case 'C':

        GetNums(num1, num2, result, haveresult, false);
        result = num1.get_comp_conj(); //use member function defined in complex.cpp
        cout <<"Result is " << result;
        haveresult = true;
        cout << "\nEnter next operator: ";
        cin >> opchoice;
        break;

    case 'P':

        GetNums(num1, num2, result, haveresult, false); //last argument is false because we do not need a second number
        num1.printpol();
        cout << "\nEnter next operator: ";
        cin >> opchoice;
        break;

    case '+':

        GetNums(num1, num2, result, haveresult, true);
        result = num1 + num2;
        cout << "Result is " << result;
        haveresult = true;
        cout << "\nEnter next operator: ";
        cin >> opchoice;
        break;

    case '-':

        GetNums(num1, num2, result, haveresult, true);
        result = num1 - num2;
        cout << "Result is " << result;
        haveresult = true;
        cout << "\nEnter next operator: ";
        cin >> opchoice;
        break;

    case '/':

        GetNumsforDivision(num1, num2, result, haveresult, true);
        result = num1 / num2;
        cout << "Result is " << result;
        haveresult = true;
        cout << "\nEnter next operator: ";
        cin >> opchoice;
        break;

    case '*':

        GetNums(num1, num2, result, haveresult, true);
        result = num1 * num2;
        cout << "Result is " << result;
        haveresult = true;
        cout << "\nEnter next operator: ";
        cin >> opchoice;
        break;

    default:

        cout << "Invalid operator! Try again: ";
        //in case the user enters an operator that does not match any of ours
        cin >> opchoice;
        break;

    }
    }
    cout << "Thank you for using!";
    return 0;
}
