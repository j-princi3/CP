#include <iostream>
using namespace std;

template <class T> class myvector
{
	protected:
		int sz;
		T init_value;
		T *ip;
		
		virtual int getoffset(int x)
		{
			return x;
		}

	public:
		myvector(myvector<T>& a);
		myvector(int size, T def_val);
		myvector();
		~myvector();
		
		int size()
		{
			return sz;
		}

		void resize(int new_sz);
		myvector<T> & operator = (myvector<T> &);
		virtual T & operator[](int x);
		myvector<T> operator + (myvector<T> &);
    friend ostream & operator << (ostream &, const myvector &);
   // friend ostream & operator << <T>(ostream &, const myvector<T> &);
};

