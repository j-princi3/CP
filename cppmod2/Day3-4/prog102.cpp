#include <iostream>
using namespace std;

namespace F 
{
	float x = 9;
}

namespace G
{
	using namespace F;
  float y = 12.0;	
	namespace INNER_G
	{
    float z = 10.01;
	}
}

int main()
{
	using namespace G;  			// this directive gives you everything declared in "g"
	using namespace G :: INNER_G; 	// this directive gives you only "inner_g"
	float x = 19.1;     			// local declaration takes precedence

	cout << "x = " << x << endl; 	// local variable
	cout << "y = " << y << endl; 	// In G
	cout << "z = " << z << endl; 	// In G :: Inner

	return 0;
}