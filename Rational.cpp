#include "Rational.h"
using namespace std;

Rational::Rational()
{
	numenator = 0;
	denominator = 1;
};

Rational::Rational(int num, int denom) //Конструктор должен делать дробь несократимой
{
	try
	{
		numenator = num;
		denominator = denom;
		int tmp = nod(num, denom);
		numenator /= tmp;
		denominator /= tmp;
		if (denominator < 0)
		{
			denominator *= -1;
			numenator *= -1;
		}
		if (denominator == 0)throw exception();
	}
	catch(exception& ex)
	{
		cout << ex.what() << endl;
		exit(-1);
	}
}

int Rational::Numerator() const //Возвращает числитель
{
	return numenator;
}

int Rational::Denominator() const  //Возвращает знаминатель
{
	return denominator;
}

int Rational::nod(int a, int b)	//Наибольший общий делитель
{
	int tmp = max(a, b);
	while((a % tmp != 0) || (b % tmp != 0))
	{
		tmp--;
	}
	return tmp;
}


bool operator==(const Rational& r1, const Rational& r2)
{
	if ((r1.Denominator() == r2.Denominator()) && (r1.Numerator() == r2.Numerator()))
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
	Rational ret(r1.Numerator()*r2.Numerator(), r1.Denominator()*r2.Denominator());
	return ret;
}

Rational operator/(const Rational& r1, const Rational& r2)
{
	try 
	{
		if (r2.Numerator() == 0)throw exception();
		Rational ret(r1.Numerator() * r2.Denominator(), r1.Denominator() * r2.Numerator());
		return ret;
	}
	catch(exception& ex)
	{
		cout << ex.what() << endl;
		exit(-1);
	}
	
}

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

ostream& operator<<(ostream& stream, const Rational& rat)
{
	stream << rat.Numerator() << '/' << rat.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& rat)
{
	int x, y;
	stream >> x;
	stream.ignore(1);
	stream >> y;
	rat = Rational(x, y);
	return stream;
};

