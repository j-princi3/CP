//Illustrates how to throw and catch a simple exception - Divide by Zero
#include <iostream>
using namespace std;

double divide(long numerator, long denominator)
{
	if(denominator == 0) throw "Division by Zero";
		return (double) numerator / denominator;
}	

int main()
{
	long numerator, denominator;

	cout << "Enter two numbers";
	cin >> numerator >> denominator;
	// Press ctrl z for eof

	while(!cin.eof())
	{
		try
		{
			cout << divide(numerator, denominator) << endl;
			cout << "After Divide" << endl;
		} 
		catch(const char* message)
		{
			cerr << message << endl;
		} 

		cout << "Enter another numerator and denominator ";
		cin >> numerator >> denominator;
	}
	return 0;
}