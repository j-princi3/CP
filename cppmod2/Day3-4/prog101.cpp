#include "prog101.h"

int main()
{
	int Gl_Var = 55;
	// Calls Globally declared function 'fun' and argument global variable 'Gl_Var'
	cout << fun( ::Gl_Var) << endl ;

	// Calls GlobalSpace1 member function 'fun' and argument is GlobalSpace2 member 'Gl_Var'
	cout << GlobalSpace1 :: fun(GlobalSpace2 :: Gl_Var) << endl;

	// Calls GlobalSpace2 member function 'fun' and argument is GlobalSpace1 member 'Gl_Var'
	cout << GlobalSpace2 :: fun (GlobalSpace1 :: Gl_Var) << endl;

	// Calls GlobalSpace1 member function 'Set_Var' 
	cout << GlobalSpace1 :: Set_Var(-2) << endl;

	/* Calls GlobalSpace1 member function 'fun' since 'Alias1' is an alternative name to 	GlobalSpace1 */

	cout << Alias1 :: fun(Alias1 :: Gl_Var) <<endl;

	return 0;
}