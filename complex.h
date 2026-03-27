#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{
    double real;
    double imag;

public:
    Complex();
    Complex(double r, double i);

    double getReal() const;
    double getImag() const;
    double magnitude() const;

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex& operator+=(const Complex& c);

    bool operator==(const Complex& c) const;
    bool operator!=(const Complex& c) const;

    bool operator<(const Complex& c) const;
    bool operator>(const Complex& c) const;
    bool operator<=(const Complex& c) const;
    bool operator>=(const Complex& c) const;

    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};

#endif
