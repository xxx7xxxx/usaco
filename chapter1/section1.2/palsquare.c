/*
  ID: longyun3
  LANG: C
  PROB: palsquare
 */

#include <stdio.h>

void 
reverse(char *s, int len)
{
	int i = 0, j = len - 1;
	char tmp;
	while (i < j) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;

		i++;
		j--;
	}
}

void
transfrom_base_k(int n, int k, char *res, int *len)
{
	int i = 0;
	int remainder;
	while (n) {
		remainder = n % k;
		if (remainder <= 9)
			res[i] = remainder + '0';
		else
			res[i] = remainder - 10 + 'A';
		n /= k;
		i++;
	}
	res[i] = '\0';
	*len = i;
	reverse(res, *len);
}

int
is_palind(char *s, int len)
{
	int i = 0, j = len - 1;

	while (i < j) {
		if (s[i] != s[j])
			return 0;
		i++;
		j--;
	}

	return 1;
}
int main()
{
	FILE *fin = fopen("palsquare.in", "r");
	FILE *fout = fopen("palsquare.out", "w");

	int i, n, k, len;
	char s[30];
	fscanf(fin, "%d", &k);

	for (i = 1; i <= 300; i++) {
		n = i * i;
		transfrom_base_k(n, k, s, &len);
		if (is_palind(s, len)) {
			transfrom_base_k(i, k, s, &len);
			fprintf(fout, "%s ", s);
			transfrom_base_k(n, k, s, &len);
			fprintf(fout, "%s\n", s);
		}
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
