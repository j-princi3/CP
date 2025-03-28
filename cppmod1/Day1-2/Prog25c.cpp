char *buffer, *name;
int main()
{
	const char* const r = buffer;
	r = name;				// illegal
	*r='x';					// illegal
  return 1;
}
