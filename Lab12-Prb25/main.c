#include <stdio.h>
// Se citeste de la tastatura un sir de numere in baza 10, cu semn. 
// Sa se determine valoarea maxima din sir si sa se afiseze in fisierul max.txt (fisierul va fi creat) valoarea maxima, in baza 16.
int maxim(int v[],int);
int main()
{
	int n=5;
	printf("n = ");
	scanf("%d", &n);
	int v[100];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	int maxi = maxim(v, n);
	FILE* f;
	f = fopen("max.txt", "w");
	fprintf(f, "Maximul din sir este: %x.", maxi);
	fclose(f);

	return 0;
}