#include "prog52.h"

void main()
{
	point p(20, 17), q(5, 73);

	shape *sp = new circle(p, 10);
	sp->draw();
	sp->move(q);

	delete sp;
}
