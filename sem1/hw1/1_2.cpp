#include <iostream>

using namespace std;

bool isPositive(int x)
{
	return (x >= 0)
}

int absoluteValue(int x)
{
	if (isPositive(x))
	{
		return x;
	}
	else
	{
		return (-x);
	}
}

int main()
{
	int divisible;
	cout << "Enter the divisible: ";
	cin >> divisible;
	int modulusDivisible = absoluteValue(divisible);

	int divider;
	cout << "Enter the divider: ";
	cin >> divider;
	int modulusDivider = absoluteValue(divider);

	int reminder;
	reminder = modulusDivisible;

	int floorQuotient = 0;
	while (reminder >= modulusDivider)
	{
		reminder -= modulusDivider;
		floorQuotient++;
	}

	cout << "The integer part of the quotient: ";

	if (isPositive(divisible))
	{
		if (not isPositive(divider))
		{
			floorQuotient = -floorQuotient;
		}
	}
	else
	{
		if (isPositive(divider))
		{
			floorQuotient = -floorQuotient - 1;
		}
		else
		{
			floorQuotient = floorQuotient + 1;
		}
	}
	cout << floorQuotient;
	return 0;
}