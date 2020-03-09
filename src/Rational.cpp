#include "Rational.h"
Rational::Rational(int num, int denom) //Конструктор должен делать дробь несократимой
{
	try
	{
		fraction = {num, denom};
		int tmp = nod({num, denom});
		fraction.first /= tmp;
		fraction.second /= tmp;
		if (fraction.second == 0)throw std::exception();
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		exit(-1);
	}
}

Rational::Rational(std::pair<int, int> fract) : fraction(fract){};

int Rational::nod(std::pair<int, int> fract)	//Наибольший общий делитель
{
	int tmp = std::max(fract.first, fract.second);
	while((fract.first % tmp != 0) || (fract.second % tmp != 0))
	{
		tmp--;
	}
	return tmp;
}

std::pair<int, int> Rational::get()
{
	return fraction;
}

bool operator==(const Rational& r1, const Rational& r2)
{
	if (r1.get == r2.get)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Rational operator*(const Rational& r1, const Rational& r2)
{
	Rational ret((r1.get.first*r2.get.first), (r1.get.second*r2.get.second));
	return ret;
}

Rational operator/(const Rational& r1, const Rational& r2)
{
	try 
	{
		if (r2.get.second == 0)throw std::exception();
		Rational ret(r1.get.first * r2.get.second, r1.get.second * r2.get.first);
		return ret;
	}
	catch(std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		exit(-1);
	}
	
}

/**
Rational operator+(const Rational& r1, const Rational& r2)
{
	int num1 = r1.Numerator();
	int num2 = r2.Numerator();
	int denom1 = r1.Denominator();
	int denom2 = r2.Denominator();
	if (denom1 == denom2)
	{
		Rational rat(num1 + num2, denom1);
		return rat;
	}
	int tmpdenom1 = denom1;
	int tmpdenom2 = denom2;
	num1 *= tmpdenom2;
	denom1 *= tmpdenom2;
	num2 *= tmpdenom1;
	denom2 *= tmpdenom1;
	Rational rat(num1+num2, denom1);
	return rat;
}

Rational operator-(const Rational& r1, const Rational& r2)
{
	int num1 = r1.Numerator();
	int num2 = r2.Numerator();
	int denom1 = r1.Denominator();
	int denom2 = r2.Denominator();
	if (denom1 == denom2)
	{
		Rational rat(num1 - num2, denom1);
		return rat;
	}
	int tmpdenom1 = denom1;
	int tmpdenom2 = denom2;
	num1 *= tmpdenom2;
	denom1 *= tmpdenom2;
	num2 *= tmpdenom1;
	denom2 *= tmpdenom1;
	Rational rat(num1 - num2, denom1);
	return rat;
}

std::ostream& operator<<(std::ostream& stream, const Rational& rat)
{
	stream << rat.Numerator() << '/' << rat.Denominator();
	return stream;
}

std::istream& operator>>(std::istream& stream, Rational& rat)
{
	int x, y;
	stream >> x;
	stream.ignore(1);
	stream >> y;
	rat = Rational(x, y);
	return stream;
};
*/

