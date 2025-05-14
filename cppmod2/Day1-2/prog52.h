#include <string.h>

#include <iostream>
using namespace std;

class point
{
	int x, y;
	public:
		point()
		{
			cout << "\n default constructor of point called";
		}

      point(int i, int j)
		{
			cout << "\n two argument constructor of point called";
			x = i;
			y = j;
		}
		friend ostream & operator << (ostream &, const point &);
};

ostream & operator << (ostream & o, const point & p) 
{
	return o << p.x << " : " << p.y;
}

class color
{
	char *c;
	public:
		color()
		{
			cout << "\n default constructor of color called";
		}
		
      color(char *x)
		{
			cout << "\n one argument constructor of color called";
			c = new char[strlen(x) + 1];
			strcpy(c, x);
		}
};

class shape
{
	shape *next;
	
	protected:
		point center;
		color col;

	public:
		shape()
		{
			cout << "\n default  constructor of shape called";
		}
		
      shape(point p)
		{
			center = p;
			cout << "\n one argument shape constructor called";
		}		
		
      shape(point p, color c1)
		{
			center = p;
			col = c1;
			cout << "\n two argument shape constructor called";
		}

		void move(point to)
		{
			erase();
			center = to;
			draw();
			cout << "\n shape move called";
		}
	 	
		virtual void erase() 
      {
         cout << "\n Shape erase called";
      };	

      virtual void draw() 
      {
         cout << "\n Shape draw called";
      };

		virtual void rotate(int) 
      {
         cout << "\n Shape rotate called";
      };
		
      virtual ~shape()
		{
			cout << "\n Shape destructor called";
		}		
};

class circle : public shape
{
	protected:
		int radius;

	public:
		circle(point p, int r) : shape(p)
		{
			radius = r;
			cout << "\n two argument constructor of circle called";
		}

		circle(point p, int r, color c1) : shape(p, c1)
		{
			radius = r;
			cout << "\n three argument constructor of circle called";
		}

		void erase()
		{
			cout <<"\n circle erase called";
		}

		void draw()
		{
			cout <<"\n circle draw called";
		}
		
		void rotate(int x)
		{
			cout << "\n circle rotate called";
		}

		~circle()
		{
			cout << "\n circle destructor called";
		}
};

class square : public shape
{
	protected:
		int side;

	public:
		square(point p, int s) : shape(p)
		{
			side = s;
			cout << "\n two argument constructor of square called";
		}

		square(point p, int s, color c1) : shape(p, c1)
		{
			side = s;
			cout << "\n three argument constructor of square called";
		}

		void erase()
		{
			cout << "\n square erase called";
		}

		void draw()
		{
			cout << "\n square draw called";
		}
		
		void rotate(int x)
		{
			cout << "\n square rotate called";
		}

		~square()
		{
			cout << "\n square destructor called";
		}
};