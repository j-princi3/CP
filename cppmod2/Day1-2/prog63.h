# include "prog61.h"

# ifndef  RANGE_INT_VECTOR_H
# define RANGE_INT_VECTOR_H

class range_int_vector : virtual public int_vector
{
	private:
		int offset;
		int get_offset(int x);
	public:
		range_int_vector(int = 0, int = 0, int = 0);
		friend ostream & operator << (ostream &, range_int_vector &);
};
#endif

range_int_vector :: range_int_vector(int low, int high, int initial_value) : 
	int_vector(high - low + 1, initial_value)
{
	offset = low;
}

//get_offset routine converts the subscript
//passed into the real offset into the array.

int range_int_vector :: get_offset(int x)
{
	return (x - offset);
}

// output operator outputs the offset and a colon.

ostream & operator << (ostream & o, range_int_vector & v)
{
	int_vector & iv = v;
	return o << v.offset << ":" << iv;
}