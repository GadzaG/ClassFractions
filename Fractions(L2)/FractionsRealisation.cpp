#include "Fractions.h"

//конструкторы:
Fractions::Fractions()
{
	numeratorand = 0;
	denominator = 1;
	//this->Reduction();
}
Fractions::Fractions(int a, int b)
{
	numeratorand = a;
	denominator = b;
	this->Reduction();
}
Fractions::Fractions(const Fractions& name)
{
	numeratorand = name.numeratorand;
	denominator = name.denominator;
}
Fractions::Fractions(Fractions&& name)
{
	numeratorand = name.numeratorand;
	denominator = name.denominator;
}

//арифметические операции:
Fractions operator +(const Fractions& dr1, const Fractions& dr2)
{
	Fractions AddResult(0, 0);
	AddResult.denominator = dr1.denominator * dr2.denominator;
	AddResult.numeratorand = dr1.numeratorand * dr2.denominator + dr2.numeratorand * dr1.denominator;

	AddResult.Reduction();

	return AddResult;
}
Fractions operator -(const Fractions& dr1, const Fractions& dr2)
{
	Fractions SubResult(0, 0);
	SubResult.denominator = dr1.denominator * dr2.denominator;
	SubResult.numeratorand = dr1.numeratorand * dr2.denominator - dr2.numeratorand * dr1.denominator;

	SubResult.Reduction();

	return SubResult;
}
Fractions operator *(const Fractions& dr1, const Fractions& dr2)
{
	Fractions MulResult(0, 0);
	MulResult.numeratorand = dr1.numeratorand * dr2.numeratorand;
	MulResult.denominator = dr1.denominator * dr2.denominator;

	MulResult.Reduction();

	return MulResult;
}
Fractions operator /(const Fractions& dr1, const Fractions& dr2)
{
	Fractions DivResult(0, 0);
	DivResult.numeratorand = dr1.numeratorand * dr2.denominator;
	DivResult.denominator = dr1.denominator * dr2.numeratorand;

	DivResult.Reduction();

	return DivResult;
}

// операторы присваивания:
Fractions Fractions::operator =(Fractions frac)
{
	this->numeratorand = frac.numeratorand;
	this->denominator = frac.denominator;
	this->Reduction();
	return *this;
}
Fractions Fractions::operator +=(Fractions frac)
{
	operator =(operator +(*this, frac));
	this->Reduction();
	return *this;
}
Fractions Fractions::operator -=(Fractions frac)
{
	operator =(operator -(*this, frac));
	this->Reduction();
	return *this;
}
Fractions Fractions::operator *=(Fractions frac)
{
	operator =(operator *(*this, frac));
	this->Reduction();
	return *this;
}
Fractions Fractions::operator /=(Fractions frac)
{
	operator =(operator /(*this, frac));
	this->Reduction();
	return *this;
}
// операторы сравнения

bool Fractions::operator ==(Fractions frac)
{
	this->Reduction();
	if ((this->numeratorand == frac.numeratorand) && (this->denominator == frac.denominator))
		return true;
	else
		return false;
}
bool Fractions::operator !=(Fractions frac)
{
	if (*this == frac)
		return false;
	else
		return true;
}
bool Fractions::operator <(Fractions frac)
{
	int tmp_num1 = this->numeratorand * frac.denominator;
	int tmp_num2 = frac.numeratorand * this->denominator;
	if (tmp_num1 < tmp_num2)
		return true;
	else
		return false;
}
bool Fractions::operator >(Fractions frac)
{
	if (*this < frac)
		return false;
	else
		return true;
}
bool Fractions::operator <=(Fractions frac)
{
	if ((*this < frac) && (*this == frac))
		return true;
	else
		return false;
}
bool Fractions::operator >=(Fractions frac)
{
	if ((*this > frac) && (*this == frac))
		return true;
	else
		return false;
}
// преобразование типов:

Fractions::operator float()
{
	return (float)this->numeratorand / (float)this->denominator;
}
Fractions::operator double()
{
	return (double)this->numeratorand / (double)this->denominator;
}

// сокращение дроби
void Fractions::Reduction()
{
	if (this->numeratorand < this->denominator)
	{
		for (int i = this->numeratorand; i > 0; i--)
		{
			if ((this->numeratorand % i == 0) && (this->denominator % i == 0))
			{
				this->numeratorand /= i;
				this->denominator /= i;
				break;
			}
		}
	}
	else
	{
		for (int i = this->denominator; i > 0; i--)
		{
			if ((this->numeratorand % i == 0) && (this->denominator % i == 0))
			{
				this->numeratorand /= i;
				this->denominator  /= i;
				break;
			}
		}
	}
}

// вывод:
ostream& operator<<(ostream& out,const Fractions& ToOut)
{
	cout << ToOut.numeratorand << "/" << ToOut.denominator << endl;
	return out;
}
// ввод:
istream& operator>>(istream& is, Fractions& ToIn)
{
	string frac, num = "", den = "";
	int pos = 0;
	is >> frac;
	int pos_sym = frac.find('/');
	while (frac[pos] < pos_sym)
	{
		num += frac[pos];
		pos++;
	}
	pos++;
	while (pos < frac.size())
	{
		den += frac[pos];
		pos++;
	}

	ToIn.numeratorand = atoi(num.c_str());
	ToIn.denominator = atoi(den.c_str());

	return is;
}