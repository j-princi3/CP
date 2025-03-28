int main()
{
  int a[5] = {1, 2, 3, 4, 5};
  int &b[5] = a;		// illegal
  int &c = a;      	// illegal
  return 1;
}
