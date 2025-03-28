#include <iostream>
using namespace std;

class test {
  int val;
  public:
    test(int x = 0)
    {
      val = x;
    } 
    friend ostream & operator << (ostream & o, test & t)
    {
      return (cout << t.val );
    }
};

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

template<class T> myvector<T> :: myvector()
{
	sz = 0;
	ip = 0;
	init_value = 0;
}

template<class T> myvector<T> :: myvector(myvector<T>& a)
{
 	sz = a.sz;
  ip = new T[sz];

	for(int i = 0; i < sz; i++)
		ip[i] = a.ip[i];

	init_value = a.init_value;
}

template <class T> ostream & operator << (ostream &os,  myvector<T> &b)
{
	os << "[";
 	
	for(int i = 0; i < b.size(); i++)
	{
		if(i > 0)	os << ",";
		os << b[i];
	}
	return os << "]";
}

template <class T> myvector<T> :: myvector(int size, T initial)
{

	sz = size;
	init_value = initial;
	ip = new T[size];

	for(int i = 0; i < size; i++)
		ip[i] = initial;
}

template <class T> myvector <T> :: ~myvector()
{
	delete[] ip;
}

template <class T> T& myvector<T> :: operator[] (int x)
{
	return ip[getoffset(x)];
}

template <class T> myvector<T>& myvector<T> :: operator = (myvector<T> &v)
{
	if(this != &v)
	{
		delete ip;
		ip = new T[sz = v.size()];
	
		for(int i = 0; i < sz; i++)
	 		ip[i] = v.ip[i];
	}
	return *this;
}

template <class T> void myvector<T> :: resize(int new_size)
{
	T *new_p = new T[new_size];

	for(int i = 0; i < new_size; i++)
		new_p[i] = (i < sz) ? ip[i] : init_value;

	delete ip;
	sz = new_size;
	ip = new_p;
}

template <class T> myvector<T> myvector<T> :: operator + (myvector<T> &b)
{
	if(size() != b.size())
	{
		cout << "Attempt to add int_myvectors of unequal sizes" << endl;
		exit(1);
	}
	myvector<T> c(size(), 0);

	for(int i = 0; i < size(); i++)
		c.ip[i] = ip[i] + b.ip[i];

	return c;
}

void main()
{
	myvector <int> i(10, 4);
  myvector <int> j(10, 4);
  myvector <int> k(10, 4);
	myvector <double> d(5, 4.55);
  k = i + j;
		
  cout << k << endl;
  cout << d << endl;

  myvector <test> obj(5, test(22));
  cout << obj;
}