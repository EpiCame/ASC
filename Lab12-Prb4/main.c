//4.Se da un sir de numere. Sa se afiseze valorile in baza 16 si in baza 2.
#include <stdio.h>

void print_number(int, int);
int Base10To2(int n) 
{
	int b2 = 0;
	int p = 1;
	while (n > 0) 
	{
		int c = n % 2;
		b2 = b2 + c*p;
		p *= 10;
		n /= 2;
	}
	return b2;
}

int main()
{
	int v[3] = {2,34,27};

	for (int i = 0; i <= 2; i++)
	{
		int n = Base10To2(v[i]);
		print_number(v[i], n);
			
	}

	return 0;
}