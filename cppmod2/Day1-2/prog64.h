# include "prog62.h"
# include "prog63.h"
# ifndef COMBINED_INT_VECTOR_H
# define COMBINED_INT_VECTOR_H

class combined_int_vector : public protected_int_vector, 
	public range_int_vector
{
	public:  
		combined_int_vector(int l = 0, int h = 0, int i = 0, int e = 0);
};
#endif;

combined_int_vector :: combined_int_vector(int l, int h, int i, int e) :
	protected_int_vector(h - l +1, i, e), 
	range_int_vector(l, h, i), int_vector(h - l + 1, i)
{
	// Nothing here
}
