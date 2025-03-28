// Assignment operator

complex & complex :: operator =  (const complex & c)
{
	rpart = c.rpart;
	ipart = c.ipart;
	return (*this);
}

void main()
{
	complex a(0, 1);							
	complex b, c;
	b = a;						// Calls operator = (complex &)	
	c = a + b;					// Calls operator = (complex &)
}
