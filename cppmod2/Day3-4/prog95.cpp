#include <stdlib.h>
#include <iostream>
using namespace std;

template <class T> class List
{
	struct node
	{
		T data;
		node* next;
	}*p;

	public:
		List();
		~List();
		void addatbeg(T);
		void append(T);
		void addbefore(T,T);
		void insertat(int,T);
		void addafter(T,T);
		void del_node(T);
		void display();
};

template <class T> List<T> :: List()
{
	p = 0;
}

template <class T> List<T> :: ~List()
{
	node*run = p;
	while(p != 0)
	{
		run = p;
		p = p->next;
		delete run;
	}
}

template <class T> void List<T> :: display() 
{
	node *run = p;
	while(run)
	{
		cout << run->data <<" ";
		run = run->next;
	}
}

template <class T> void List<T> :: addatbeg(T val)
{
	node *temp = new node;
	temp->data = val;
	temp->next = p;
	p = temp;
}

template <class T> void List<T> :: addbefore(T before, T val)
{
	if(p->data == before)
	{
		addatbeg(val);
		return;
	}
	node *old = p;
	node *run = p->next;
	while(run)
	{
		if(before == run->data)
		{
			node *temp = new node;
			temp->data = val;
			temp->next = run;
			old->next = temp;
			return;
		}

		old = run;
		run = run->next;
	}
	cout<<"Required node not found\n";
}

template <class T> void List<T> :: addafter(T after, T val)
{
	node *run = p;
	while(run)
	{
		if(after == run->data)
		{
			node *temp = new node;
			temp->data = val;
			temp->next = run->next;
			run->next = temp;
			return;	
		}
		run = run->next;
	}
	cout<<"Required node not found\n";
}
	
template <class T> void List<T> :: append(T val)
{
	if(p == 0)
		addatbeg(val);
	else
	{
		node *run = p;
		while(run->next)
			run = run->next;

		run->next = new node;
		run->next->data = val;
		run->next->next = 0;
	}
}

template <class T> void List<T> :: del_node(T del)
{
	node *old = p;	
	if(p->data == del)
	{
		p = p->next;
		delete old;
		return;
	}
	
	node *run = p->next;
	while(run)
	{
		if(run->data == del)
		{
			old->next = run->next;
			delete run;
			return;
		}	
		old = run;
		run = run->next;
	}
	cout<<"Required node not found\n";
}

template <class T> void List<T> :: insertat(int at, T val)
{
	if(at == 1)
	{
		addatbeg(val);
		return;
	}

	node *old = p;
	node *run = p->next;
	int i = 2;

	while(run != 0)
	{
		if(i == at)
			break;
		old = run;
		run = run->next;
		i++;
	}

	if(i != at)	{
		append(val);	
		return;
	}
	node *temp = new node;
	temp->data = val;
	temp->next = run;
	old->next = temp;			
}

void main()
{
	List <int> ob;		
	ob.addatbeg(10);	
	cout<<"\n values in the list are : "; 
	ob.display();	

	ob.addbefore(10,5);
	cout<<"\n values in the list are : "; 
	ob.display();	

	ob.addafter(5,2);
	cout<<"\n values in the list are : "; 
	ob.display();	

	ob.append(20);
	cout<<"\n values in the list are : "; 
	ob.display();	

	ob.insertat(4,15);
	cout<<"\n values in the list are : "; 
	ob.display();	

	ob.del_node(5);
	cout<<"\n values in the list are : "; 
	ob.display();	
}
