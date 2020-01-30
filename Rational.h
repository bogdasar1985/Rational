#include <iostream>
#include <algorithm>
#include <exception>
class Rational
{
private:
    int numenator;
	int denominator;
    int nod(int a, int b);
public:
    Rational();
    Rational(int num, int denom);
    int Numerator() const;
    int Denominator() const;
};

bool operator==(const Rational& r1, const Rational& r2);

Rational operator*(const Rational& r1, const Rational& r2);

Rational operator/(const Rational& r1, const Rational& r2);

Rational operator+(const Rational& r1, const Rational& r2);

Rational operator-(const Rational& r1, const Rational& r2);

std::ostream& operator<<(std::ostream& stream, const Rational& rat);

std::istream& operator>>(std::istream& stream, Rational& rat);
