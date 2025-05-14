char *buffer, *name;
int main()
{
	char* const q=buffer;
	q=name;			   	// illegal
	*q='x';
  return 1;
}
