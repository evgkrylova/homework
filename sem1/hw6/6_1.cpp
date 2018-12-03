#include <iostream>

using namespace std;

char getSign(double number)
{
	unsigned char *binaryForm = (unsigned char*)&number;
	if (binaryForm[7] & 0b10000000)
		return '-';
	return '+';
}

int getExponent(double number)
{
	unsigned char *binaryForm = (unsigned char*)&number;
	return (((binaryForm[7] & 0b01111111) << 4) | ((binaryForm[6] & 0b11110000) >> 4)) - 0b1111111111;
}

double getMantissa(double number)
{
	((unsigned char*)&number)[7] = 0b00111111;
	((unsigned char*)&number)[6] = ((unsigned char*)&number)[6] | 0b11110000;
	return number;
}

int main()
{
	double number = 0;
	cout << "Enter a number: ";
	cin >> number;

	cout << "Result: ";
	if (number == 0)
	{
		cout << '0';
	}
	cout << getSign(number) << getMantissa(number) << "*2^" << getExponent(number);
	return 0;
}

