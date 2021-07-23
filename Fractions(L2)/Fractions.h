#pragma once
#include <iostream>
#include <string>
using namespace std;



class Fractions
{
private:
	int numeratorand;//числитель
	int denominator; //знаменатель

	friend ostream& operator<<(ostream& out, const Fractions& ToOut);
	friend istream& operator>>(istream& is, Fractions& ToIn);


public:
	//по умолчанию
	Fractions();
	//присваивание
	Fractions(int a, int b=1);
	//копирование
	Fractions(const Fractions& name);
	//перемещение
	Fractions(Fractions&& name);

	// аримфетические операции
	friend Fractions operator +(const Fractions& dr1, const Fractions& dr2);
	friend Fractions operator -(const Fractions& dr1, const Fractions& dr2);
	friend Fractions operator *(const Fractions& dr1, const Fractions& dr2);
	friend Fractions operator /(const Fractions& dr1, const Fractions& dr2);

	// оператор присваивания
	Fractions operator =(Fractions frac);
	Fractions operator +=(Fractions frac);
	Fractions operator -=(Fractions frac);
	Fractions operator *=(Fractions frac);
	Fractions operator /=(Fractions frac);
	// операторы сравнения
	bool operator ==(Fractions frac);
	bool operator !=(Fractions frac);
	bool operator <(Fractions frac);
	bool operator >(Fractions frac);
	bool operator >=(Fractions frac);
	bool operator <=(Fractions frac);
	// преобразование типов
	explicit operator float();
	explicit operator double();
	// сокращение дробей
	void Reduction();

};