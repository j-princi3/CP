#include <time.h>
#include <iostream>
using namespace std;

class DATE
{
	private:
   	int	Day, Mon, Year;

 	public:
   	DATE() {}
		DATE(int dd, int mm, int yy) : Day(dd), Mon(mm), Year(yy) {}
		
		int day() 
		{ 
			return Day; 
		};

		int mon() 
		{ 
			return Mon; 
		};

    	int year() 
		{ 
			return Year; 
		};

     	void SetCurrDate();
      friend ostream& operator << (ostream& , DATE &);
};

void DATE :: SetCurrDate()
{
	time_t a;
	struct tm *t;

	a = time(NULL);
	t = localtime(&a);

	Day = t->tm_mday;
   Mon = t->tm_mon + 1;
   Year = t->tm_year + 1900;
}

ostream& operator << (ostream& O, DATE & d)
{
 	O << " Date : " << d.Day << "/" << d.Mon<<"/" << d.Year;
	return O;
}

namespace American
{
	void format(DATE &d)
   {
		cout << endl << " American Date : "<< d.mon() << "/";
		cout << d.day() << "/" << d.year();
   }
}

namespace British
{
   void format(DATE &d)
   {
  		cout << endl << " British Date : " << d.day();
		cout << "/" << d.mon() << "/" << d.year();
   }
}

void main()
{
   DATE d;
   d.SetCurrDate();

   cout<<endl<<" Current "<<d;

   American :: format(d);
   British :: format(d);
}