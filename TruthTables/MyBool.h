//MyBool.h
//Matthew Bergeron
//Concordia University

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class MyBool
{
private:
    bool value;
public:
    friend MyBool operator+(const MyBool &first, const MyBool &second);
    friend MyBool operator*(const MyBool &first, const MyBool &second);
    friend MyBool operator!(const MyBool &toinvert);
    friend ostream &operator<<(ostream &out, const MyBool &toprint);
    MyBool();
    MyBool(bool a);
};
