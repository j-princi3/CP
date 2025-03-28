# include <iostream.h>
# include <stdlib.h>

# ifndef  INT_VECTOR_H
# define INT_VECTOR_H

class int_vector
{
	private:	
		int sz;
		int init_value;
		int *ip;

	protected:
		// This function returns the offset given the array index 
		virtual int get_offset(int x)	
		{
			return x;
		}

	public:
		int_vector(int size = 0, int default_value = 0);
		~int_vector();
		int size()
		{
			return sz;
		}

		void resize(int new_size);
		int_vector& operator = (int_vector &);
		int_vector(int_vector &);
		int& operator [](int x);
		friend int_vector operator + (int_vector & a, int_vector & b);
		friend ostream & operator << (ostream & o, int_vector & v);
};
#endif