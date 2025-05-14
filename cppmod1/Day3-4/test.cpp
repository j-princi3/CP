# include "mystring.h"

void main()
{
	mystring s1("Qualcomm");
	
	mystring s3("Genesis");
   s3 = s1;

	s3[0] = 'h';

	cout << "s1 = " << s1 <<endl;	
	cout << "s3 = " << s3 <<endl;	
}