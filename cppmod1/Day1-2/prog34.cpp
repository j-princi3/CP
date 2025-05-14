// Copy constructor

complex :: complex (const complex & c)
{
	rpart = c.rpart;
	ipart = c.ipart;
}

void main()
{
	complex a(0, 1);							
	complex b(a);				// Calls complex (complex &)	
	complex c = a;				// Calls complex (complex &)
}
