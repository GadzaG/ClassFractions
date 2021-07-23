#pragma once
#include <iostream>
#include <string>
using namespace std;



class Fractions
{
private:
	int numeratorand;//���������
	int denominator; //�����������

	friend ostream& operator<<(ostream& out, const Fractions& ToOut);
	friend istream& operator>>(istream& is, Fractions& ToIn);


public:
	//�� ���������
	Fractions();
	//������������
	Fractions(int a, int b=1);
	//�����������
	Fractions(const Fractions& name);
	//�����������
	Fractions(Fractions&& name);

	// �������������� ��������
	friend Fractions operator +(const Fractions& dr1, const Fractions& dr2);
	friend Fractions operator -(const Fractions& dr1, const Fractions& dr2);
	friend Fractions operator *(const Fractions& dr1, const Fractions& dr2);
	friend Fractions operator /(const Fractions& dr1, const Fractions& dr2);

	// �������� ������������
	Fractions operator =(Fractions frac);
	Fractions operator +=(Fractions frac);
	Fractions operator -=(Fractions frac);
	Fractions operator *=(Fractions frac);
	Fractions operator /=(Fractions frac);
	// ��������� ���������
	bool operator ==(Fractions frac);
	bool operator !=(Fractions frac);
	bool operator <(Fractions frac);
	bool operator >(Fractions frac);
	bool operator >=(Fractions frac);
	bool operator <=(Fractions frac);
	// �������������� �����
	explicit operator float();
	explicit operator double();
	// ���������� ������
	void Reduction();

};