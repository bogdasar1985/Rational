#ifndef RATIONAL
#define RATIONAL
#include <iostream>
#include <algorithm>
#include <exception>
class Rational
{
private:
    std::pair<int, int> fraction;
    int nod(std::pair<int, int> fract);  //Greatest common factor.
public:
    Rational(int num, int denom);   //Constructor with numerator and denominator.
    Rational(std::pair<int, int> fract);    //Constructor with std::pair, consist of numerator and denominator.
    std::pair<int, int> get();  //Return std::pair<int, int> with numerator and denominator.
};

bool operator==(const Rational& r1, const Rational& r2);

Rational operator*(const Rational& r1, const Rational& r2);

Rational operator/(const Rational& r1, const Rational& r2);

Rational operator+(const Rational& r1, const Rational& r2);

Rational operator-(const Rational& r1, const Rational& r2);

std::ostream& operator<<(std::ostream& stream, const Rational& rat);

std::istream& operator>>(std::istream& stream, Rational& rat);
#endif