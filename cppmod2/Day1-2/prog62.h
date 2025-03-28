
# include "prog61.h"

# ifndef  PROTECTED_INT_VECTOR_H
# define  PROTECTED_INT_VECTOR_H

class protected_int_vector :  public virtual int_vector
{
	private:
		int error_value;

	public:
		protected_int_vector(int size = 0, int initial = 0, int error = -1);
	int& operator[](int x);
};
#endif;

protected_int_vector :: protected_int_vector(int size, int initial,
int error) : int_vector(size, initial)
{
	error_value = error;
}

//subscript operator is used to check the validity of the subscript.

int& protected_int_vector :: operator[](int x)
{
	int x1 = get_offset(x);
	
	return((x1 >= 0 && x1< size()) ? int_vector :: operator[](x) 
	: error_value);
}