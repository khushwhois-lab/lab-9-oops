#include "complex.h"
#include <cmath>

Complex::Complex()
{
    real = 0;
    imag = 0;
}

Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

double Complex::getReal() const
{
    return real;
}

double Complex::getImag() const
{
    return imag;
}

double Complex::magnitude() const
{
    return sqrt(real * real + imag * imag);
}

Complex Complex::operator+(const Complex& c) const
{
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(const Complex& c) const
{
    return Complex(real - c.real, imag - c.imag);
}

Complex& Complex::operator+=(const Complex& c)
{
    real += c.real;
    imag += c.imag;
    return *this;
}

bool Complex::operator==(const Complex& c) const
{
    return fabs(real - c.real) < 1e-9 && fabs(imag - c.imag) < 1e-9;
}

bool Complex::operator!=(const Complex& c) const
{
    return !(*this == c);
}

bool Complex::operator<(const Complex& c) const
{
    return magnitude() < c.magnitude();
}

bool Complex::operator>(const Complex& c) const
{
    return c < *this;
}

bool Complex::operator<=(const Complex& c) const
{
    return !(*this > c);
}

bool Complex::operator>=(const Complex& c) const
{
    return !(*this < c);
}

ostream& operator<<(ostream& out, const Complex& c)
{
    if (c.imag >= 0)
        out << c.real << " + " << c.imag << "i";
    else
        out << c.real << " - " << fabs(c.imag) << "i";
    return out;
}

istream& operator>>(istream& in, Complex& c)
{
    in >> c.real >> c.imag;
    return in;
}
