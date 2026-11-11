#include <iostream>
#include <cmath>
#include "mycomplex.h"
using namespace std;

Complex::Complex(double re, double im) : re_(re), im_(im) {
}

Complex::Complex(const Complex& rhs) : re_(rhs.re_), im_(rhs.im_) {
}

Complex::~Complex() {
    re_ = 0.0;
    im_ = 0.0;
}

void Complex::set(double re, double im) {
    re_ = re;
    im_ = im;
}

Complex::operator double() const {
    return abs();
}

double Complex::abs() const {
    return sqrt(re_ * re_ + im_ * im_);
}

Complex Complex::operator+(const Complex& rhs) const {
    Complex result;
    result.re_ = re_ + rhs.re_;
    result.im_ = im_ + rhs.im_;
    return result;
}

Complex Complex::operator-(const Complex& rhs) const {
    Complex result;
    result.re_ = re_ - rhs.re_;
    result.im_ = im_ - rhs.im_;
    return result;
}

Complex Complex::operator+(const double& value) const {
    Complex result;
    result.re_ = re_ + value;
    result.im_ = im_;
    return result;
}

Complex Complex::operator-(const double& value) const {
    Complex result(*this);
    result.re_ = re_ - value;
    return result;
}

Complex Complex::operator*(const Complex& rhs) const {
    Complex result;
    result.re_ = re_ * rhs.re_ - im_ * rhs.im_;
    result.im_ = re_ * rhs.im_ + im_ * rhs.re_;
    return result;
}

Complex Complex::operator*(const double& value) const {
    Complex result;
    result.re_ = re_ * value;
    result.im_ = im_ * value;
    return result;
}

Complex Complex::operator/(const double& value) const {
    Complex result;
    result.re_ = re_ / value;
    result.im_ = im_ / value;
    return result;
}

Complex& Complex::operator+=(const Complex& rhs) {
    re_ += rhs.re_;
    im_ += rhs.im_;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
    re_ -= rhs.re_;
    im_ -= rhs.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
    double tmp_re = re_;
    re_ = re_ * rhs.re_ - im_ * rhs.im_;
    im_ = im_ * rhs.re_ + tmp_re * rhs.im_;
    return *this;
}

Complex& Complex::operator+=(const double& value) {
    re_ += value;
    return *this;
}

Complex& Complex::operator-=(const double& value) {
    re_ -= value;
    return *this;
}

Complex& Complex::operator*=(const double& value) {
    re_ *= value;
    im_ *= value;
    return *this;
}

Complex& Complex::operator/=(const double& value) {
    re_ /= value;
    im_ /= value;
    return *this;
}

Complex& Complex::operator=(const Complex& rhs) {
    re_ = rhs.re_;
    im_ = rhs.im_;
    return *this;
}

Complex& Complex::operator=(const double& value) {
    re_ = value;
    im_ = 0.0;
    return *this;
}

istream& operator>>(istream& stream, Complex& value) {
    char tmp[256];
    stream >> value.re_ >> value.im_ >> tmp;
    return stream;
}

ostream& operator<<(ostream& stream, const Complex& value) {
    stream << value.re_;
    if (!(value.im_ < 0)) {
        stream << '+';
    }
    stream << value.im_ << 'i';
    return stream;
}

Complex operator+(const double& lhs, const Complex& rhs) {
    Complex result;
    result.re_ = lhs + rhs.re_;
    result.im_ = rhs.im_;
    return result;
}

Complex operator-(const double& lhs, const Complex& rhs) {
    Complex result;
    result.re_ = lhs - rhs.re_;
    result.im_ = -rhs.im_;
    return result;
}

Complex operator*(const double& lhs, const Complex& rhs) {
    Complex result;
    result.re_ = lhs * rhs.re_;
    result.im_ = lhs * rhs.im_;
    return result;
}
