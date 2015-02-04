/*
ID: longyun3
PROG: milk2
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

struct interval {
	int begin;
	int end;
};

int comp_int(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int main()
{
	FILE *fin = fopen("milk2.in", "r");
	FILE *fout = fopen("milk2.out", "w");

	int i;
	int num;
	int b, e;
	int max1, max2;
	fscanf(fin, "%d", &num);
	struct interval *arr = malloc(sizeof(struct interval) * num);

	for (i = 0; i < num; i++)
		fscanf(fin, "%d %d", &arr[i].begin, &arr[i].end);
	qsort((void *)arr, num, sizeof(struct interval), comp_int);
	
	b = arr[0].begin;
	e = arr[0].end;
	max1 = e - b;
	max2 = 0;

	for (i = 1; i < num; i++) {
		if (arr[i].begin <= e && arr[i].end > e) {
			if (arr[i].end - b > max1)
				max1 = arr[i].end - b;
			e = arr[i].end;
		} else if (arr[i].begin > e) {
			if (arr[i].begin - e > max2)
				max2 = arr[i].begin - e;
			b = arr[i].begin;
			e = arr[i].end;
		}
	}

	fprintf(fout, "%d %d\n", max1, max2);
	fclose(fin);
	fclose(fout);
	free(arr);

	return 0;
}
