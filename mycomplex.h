#ifndef MYCOMPLEX_H_
#define MYCOMPLEX_H_
#include <iostream>

class Complex {
    double re_;
    double im_;

public:
    Complex(double re = 0, double im = 0);
    Complex(const Complex& rhs);
    ~Complex();
    void set(double re, double im = 0);
    operator double();
    double abs();
    friend std::istream& operator>>(std::istream& stream, Complex& value);
    friend std::ostream& operator<<(std::ostream& stream, Complex& value);

    Complex operator+(const Complex& rhs);
    Complex operator-(const Complex& rhs);
    Complex operator+(const double& value);
    friend Complex operator+(const double& lhs, const Complex& rhs);
    Complex operator-(const double& value);
    friend Complex operator-(const double& lhs, const Complex& rhs);
    Complex operator*(const Complex& rhs);
    Complex operator*(const double& value);
    friend Complex operator*(const double& lhs, const Complex& rhs);
    Complex operator/(const double& value);

    Complex& operator+=(const Complex& rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator+=(const double& value);
    Complex& operator-=(const double& value);
    Complex& operator*=(const double& value);
    Complex& operator/=(const double& value);
    Complex& operator=(const Complex& rhs);
    Complex& operator=(const double& value);
};
#endif
