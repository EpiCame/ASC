#include <stdio.h>

//Se dau trei siruri de caractere. 
//Sa se afiseze cel mai lung sufix comun pentru fiecare din cele trei perechi de cate doua siruri ce se pot forma.

int len_of_string(char s[])
{
	int nr = 0;
	for (int i = 0; i < 100; i++)
	{
		if (s[i] != '\0')
			nr = nr + 1;
		else
			break;
	}
	return nr;
}
int cauta_sufix(char s1[], int len_s1, char s2[], int len_s2, char *suf_1_2)
{
	int len_suf = -1;
	char aux;
	while (len_s1 > 0 && len_s2 > 0)
	{
		if (s1[len_s1] == s2[len_s2])
		{
			len_suf += 1;
			suf_1_2[len_suf] = s1[len_s1];
			len_s1 -= 1;
			len_s2 -= 1;
		}
		else
		{
			len_suf += 1;
			for (int i = 0; i <= len_suf / 2-1; i++)
			{
				aux = suf_1_2[i];
				suf_1_2[i] = suf_1_2[len_suf - i- 1];
				suf_1_2[len_suf - i- 1] = aux;
			}
			suf_1_2[len_suf] = 0;
			break;
		}
	}
	return len_suf;
}
void afisare_sufix(char s1[], char s2[], char suf[]);
int main()
{ 
	char s1[100]="ramrampam";
	int len_s1 = len_of_string(s1)-1;
	char s2[100] = "goosebumpsam";
	int len_s2 = len_of_string(s2)-1;
	char s3[100] = "epicamepsam";
	int len_s3 = len_of_string(s3)-1;
	char suf_1_2[100], suf_2_3[100], suf_1_3[100];
	int len_suf_1_2 = cauta_sufix(s1, len_s1, s2, len_s2, suf_1_2);
	int len_suf_2_3 = cauta_sufix(s3, len_s3, s2, len_s2, suf_2_3);
	int len_suf_1_3 = cauta_sufix(s1, len_s1, s3, len_s3, suf_1_3);
	afisare_sufix(s1, s2, suf_1_2);
	afisare_sufix(s2, s3, suf_2_3);
	afisare_sufix(s1, s3, suf_1_3);

	return 0;
}