#include <iostream>
using namespace std;

int Gl_Var = 1;
int& fun(int&);

// A namespace declaration, identifier name is GlobalSpace1
namespace GlobalSpace1	
{
	int Gl_Var = 2 ;		// Member of GlobalSpace1
	int fun(int&);			// Member function of GlobalSpace1
}

// A namespace declaration, identifier name is GlobalSpace2
namespace GlobalSpace2	
{
	int Gl_Var = 3;		// Member of GlobalSpace2
	int fun(int&);			// Member function of GlobalSpace2
}

// An extension-namespace-definition for GlobalSpace1
namespace GlobalSpace1	
{
	int Set_Var(int);
}

// 'Alias1' is an alias name for GlobalSpace1
namespace Alias1 = GlobalSpace1;		

// Implementation of member of GlobalSpace1
int Alias1 :: Set_Var(int Set_to_Gl_Var) 
{
	return Gl_Var = Set_to_Gl_Var;
}

// Implementation of member of GlobalSpace1
int GlobalSpace1 :: fun(int& Ref_to_Arg) 	
{
	return Ref_to_Arg++ + Gl_Var;		// Uses GlobalSpace1 :: Gl_Var
}

// Implementation of member of GlobalSpace2
int GlobalSpace2 :: fun (int& Ref_to_Arg) 	
{
	return Ref_to_Arg++ + ::Gl_Var;	// Uses GlobalSpace2 :: Gl_Var
}

// Implementation of member of global space
int& fun(int& Ref_to_Arg) 			
{
	GlobalSpace1 :: Gl_Var += GlobalSpace2 :: Gl_Var + ++Ref_to_Arg;
	return GlobalSpace1 :: Gl_Var;
}