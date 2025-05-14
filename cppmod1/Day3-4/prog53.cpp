#include <string.h>
#include <iostream>
using namespace std;

// Abstract Base class
class Employee
{
	protected:
		char name[30];
		double basic, netSal;

	public:
		Employee() { }
	
		Employee(char * s, double d)  
		{ 
			strcpy(name, s);
			basic = d;
		}
		virtual void calSal() = 0;
		
		virtual ~Employee ()
		{
			cout << "destructor of employee called" << endl;
		}
		virtual void Show();
};

void Employee :: Show()
{
	cout << "Employee show" << endl;
	cout << "Name		:" << name << endl;
	cout << "Net Salary	:" << netSal << endl;
}

class Manager : public Employee
{
	protected:
		int type;
	
	public:
		void calSal();
		void Show();

		Manager(char * s, double d, int i) : Employee(s, d)
		{
			type = i;
		}

		~Manager ()
		{
			cout << "destructor of Manager called" << endl;
		}
};

void Manager :: Show()
{
	cout << "Manager show" << endl;
	Employee :: Show();
	cout << "type		:" << type << endl;
}

void Manager :: calSal()
{
	cout << "calsal of manager called" << endl;
	double hra = (5.0/100.0) * basic;		// assuming hra is 5% of basic
	netSal = basic + hra;
}

void main()
{
	Employee *e = new Manager("Ravi", 10000, 1);
	e->calSal();
	e->Show();
	delete e;
	// What happens if the following statement is uncommented?
	// Employee e;
}
