#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "Enter the value of the variable x: ";
	cin >> number;
	int squared = number * number;
	int result = (squared + number) * (squared + 1) + 1;
	cout << "x^4 + x^3 + x^2 + x + 1 = " << result;
	return 0;
}