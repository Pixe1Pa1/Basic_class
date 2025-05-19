#include "Ratio.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

int Ratio::current_count;
int Ratio::total_count;

Ratio::Ratio() 
	: numerator(0), denominator(1) 
{
	current_count++;
	total_count++;
}

Ratio::Ratio(int OtherNumerator)
	:Ratio(OtherNumerator, 1)
{}

Ratio::Ratio(int OtherNumerator, int OtherDenominator)
{
	current_count++;
	total_count++;
	SetNumerator(OtherNumerator);
	SetDenominator(OtherDenominator);
	SetSignRatio();
	ReduceRatio();
}

Ratio::~Ratio()
{
	current_count--;
}

Ratio::Ratio(const Ratio& other)
	:numerator(other.numerator), denominator(other.denominator)
{
	current_count++;
	total_count++;
}


void Ratio::SetSignRatio()
{
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	else
	{
		numerator = numerator;
		denominator = denominator;
	}
}

void Ratio::SetNumerator(int OtherNumerator)
{
	numerator = OtherNumerator;
}

void Ratio::SetDenominator(int OtherDenominator)
{
	if (OtherDenominator == 0)
	{
		std::cout << "Error, now denominator = 1" << std::endl;
		denominator = 1;
	}
	else if (OtherDenominator < 0)
	{
		denominator = -OtherDenominator;
		numerator = -numerator;
	}
	else
		denominator = OtherDenominator;
	
}

int Ratio::GetNumerator() const
{
	return numerator;
}

int Ratio::GetDenominator() const
{
	return denominator;
}

void Ratio::ShowRatio() const
{
	std::cout << this->numerator << "/" << this->denominator << "\t";
}

void Ratio::ReduceRatio()
{
	int numer = numerator;
	int denom = denominator;
	while (denom != 0)
	{
		int tmp = denom;
		denom = numer % denom;
		numer = tmp;
	}
	if (numer < 0)
	{
		numerator /= -numer;
		denominator /= -numer;
	}
	else {
		numerator /= numer;
		denominator /= numer;
	}
}

Ratio operator+(const Ratio& OtherNumber1, const Ratio& OtherNumber)
{
	int numer = OtherNumber.numerator * (OtherNumber1.denominator) + (OtherNumber1.numerator) * OtherNumber.denominator;
	int denom = OtherNumber.denominator * (OtherNumber1.denominator);
	Ratio Rat(numer, denom);
	Rat.ReduceRatio();
	return Rat;
}

Ratio operator-(const Ratio& OtherNumber1, const Ratio& OtherNumber)
{
	int numer = OtherNumber1.numerator * OtherNumber.denominator - OtherNumber.numerator * (OtherNumber1.denominator);
	int denom = OtherNumber1.denominator * OtherNumber.denominator;
	Ratio Rat(numer, denom);
	Rat.ReduceRatio();
	return Rat;
}

Ratio operator*(const Ratio& OtherNumber1, const Ratio& OtherNumber)
{
	int numer = OtherNumber1.numerator * OtherNumber.numerator;
	int denom = OtherNumber1.denominator * OtherNumber.denominator;
	Ratio Rat(numer, denom);
	Rat.ReduceRatio();
	return Rat;
}

Ratio operator/(const Ratio& OtherNumber1, const Ratio& OtherNumber)
{
	if (OtherNumber.numerator == 0) {
		std::cout << "Error: Division by zero!" << std::endl;
		return Ratio(0, 1); 
	}
	int numer = OtherNumber1.numerator * OtherNumber.denominator;
	int denom = OtherNumber1.denominator * OtherNumber.numerator;
	Ratio Rat(numer, denom);
	Rat.ReduceRatio();
	return Rat;
}

bool Ratio::operator==(const Ratio& OtherNumber) const
{   // true = 1, false = 0
	return (OtherNumber.numerator == this->numerator && OtherNumber.denominator == this->denominator);
}

bool Ratio::operator!=(const Ratio& OtherNumber) const
{
	return !(*this == OtherNumber);
}

bool Ratio::operator>(const Ratio& OtherNumber) const
{
	int numer1 = this->numerator * OtherNumber.denominator;
	int numer2 = OtherNumber.numerator * this->denominator;
	return (numer1 > numer2);
}

bool Ratio::operator<(const Ratio& OtherNumber) const
{
	int numer1 = this->numerator * OtherNumber.denominator;
	int numer2 = OtherNumber.numerator * this->denominator;
	return (numer1 < numer2);
}

bool Ratio::operator>=(const Ratio& OtherNumber) const
{
	return (*this > OtherNumber)||(*this == OtherNumber);
}

bool Ratio::operator<=(const Ratio& OtherNumber) const
{
	return (*this < OtherNumber) || (*this == OtherNumber);
}

Ratio Ratio::Pow(const int& Exponentiate)
{
    int numer = 1, denom = 1;
	if (Exponentiate == 0)
		return Ratio(1, 1);
	else if(Exponentiate > 0)
		for (int i = 0; i < Exponentiate; i++)
		{
			numer *= (this->numerator);
			denom *= (this->denominator);
		}
	else
		for (int i = 0; i < -Exponentiate; i++)
		{
			numer *= (this->denominator);
			denom *= (this->numerator);
		}
	return Ratio(numer, denom);
}

int Ratio::WholePartRatio()
{
	if (this->denominator != 0)
		return (this->numerator / this->denominator);
	return 0;
}

Ratio Ratio::ShotgunPartRatio()
{
	int shotgun = this->numerator % this->denominator;
	if (shotgun == 0)
		return Ratio(0, 1);
	else
		return Ratio(shotgun, this->denominator);
}

float Ratio::ConverInFloat()
{
	return (float(this->numerator) / float(this->denominator));
}

int Ratio::ConverInInt()
{
	return WholePartRatio();
}

Ratio Ratio::operator=(const Ratio& OtherNumber)
{
	numerator = OtherNumber.numerator;
	denominator = OtherNumber.denominator;
	return *this;
}

Ratio Ratio::operator+=(const Ratio& OtherNumber)
{
	*this = *this + OtherNumber;
	return *this;
}

Ratio Ratio::operator-=(const Ratio& OtherNumber)
{
	*this = *this - OtherNumber;
	return *this;
}

Ratio Ratio::operator*=(const Ratio& OtherNumber)
{
	*this = *this * OtherNumber;
	return *this;
}

Ratio Ratio::operator/=(const Ratio& OtherNumber)
{
	*this = *this / OtherNumber;
	return *this;
}

bool Ratio::IsInt() const
{
	return (numerator % denominator == 0);
}

const char* Ratio::ToString() const
{
	static char buffer[100];
	snprintf(buffer, sizeof(buffer), "Numerator: %d, Denominator: %d, Current Count: %d, Total Count: %d", numerator, denominator, current_count, total_count);
	return buffer; 
}

Ratio Ratio::FromString(const char* str)
{
	int num = 0, denom = 1;
	sscanf_s(str, "Numerator: %d, Denominator: %d", &num, &denom);
	return Ratio(num, denom);
}


