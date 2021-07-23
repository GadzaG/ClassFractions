#include "Fractions.h"

int main()
{
	setlocale(LC_ALL, "ru");

	
	Fractions tst0(1, 3), tst1(5, 5);


	cout << (float)tst0;

	tst0 = 1 + tst1;

}