#ifndef MYCOMPLEX_H_
#define MYCOMPLEX_H_
#include <iostream>

class Complex {
    double re_;
    double im_;

public:
    explicit Complex(double re = 0, double im = 0);
    Complex(const Complex& rhs);
    ~Complex();
    void set(double re, double im = 0);
    explicit operator double() const;
    double abs() const;
    friend std::istream& operator>>(std::istream& stream, Complex& value);
    friend std::ostream& operator<<(std::ostream& stream, const Complex& value);

    Complex operator+(const Complex& rhs) const;
    Complex operator-(const Complex& rhs) const;
    Complex operator+(const double& value) const;
    friend Complex operator+(const double& lhs, const Complex& rhs);
    Complex operator-(const double& value) const;
    friend Complex operator-(const double& lhs, const Complex& rhs);
    Complex operator*(const Complex& rhs) const;
    Complex operator*(const double& value) const;
    friend Complex operator*(const double& lhs, const Complex& rhs);
    Complex operator/(const double& value) const;

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
