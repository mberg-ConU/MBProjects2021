//MyBool.cpp
//Matthew Bergeron
//Concordia University

#include "MyBool.h"

MyBool operator+(const MyBool &first, const MyBool &second)
{
    MyBool a((first.value || second.value));
    return a;
}

MyBool operator*(const MyBool &first, const MyBool &second)
{
    MyBool a((first.value && second.value));
    return a;
}

MyBool operator!(const MyBool &toinvert)
{
    MyBool a(!toinvert.value);
    return a;
}

ostream &operator<<(ostream &out, const MyBool &toprint)
{
    out << toprint.value;
}

MyBool::MyBool()
{
    value = NULL;
}

MyBool::MyBool(bool a)
{
    value = a;
}
