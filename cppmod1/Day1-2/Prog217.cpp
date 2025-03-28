#include <stdarg.h>
#include <iostream>
using namespace std;

void print(char *fmt, ...)
{
	va_list ptr;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ptr, fmt);

	for(p = fmt; *p; p++)
	{
		if(*p != '%')
		{
			cout << (*p);
			continue;
		}

		switch(*++p)
		{
			case 'd':
				ival = va_arg(ptr, int);
				cout << ival;
				break;

			case 'f':
				dval = va_arg(ptr, double);
				cout << dval;
				break;

			case 's':
				for(sval = va_arg(ptr, char*); *sval; sval++)
				cout << *sval;
				break;

			default :
				cout << *p;
				break;
		}
	}
}

int main()
{
   int i = 10;
   char s[20] = "genesis";
   double f = 12.12;
   print("%d\n", i);
   print("%s\n", s);
   print("%f\n", f);
   print("%d %f %s", 10, 5.5, "hello");
   return 1;
}