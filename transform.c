/*
ID: longyun3
LANG: C
PROG: transform
*/

#include <stdio.h>
#include <stdlib.h>

#define R_90 		1
#define R_180		2
#define R_270		3
#define R_REFLECTION	4
#define R_COMBINATION	5
#define R_NOCHANGE	6
#define R_INVAILD	7

char **malloc_2d(int n)
{
	int i;
	char **arr = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
		arr[i] = (char *)malloc(n * sizeof(char));
	return arr;
}

void free_2d(char **arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
}

void copy_2d(char **arr, char **arr2, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			arr2[i][j] = arr[i][j];
}

int equal_2d(char **arr, char **arr2, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (arr[i][j] != arr2[i][j])
				return 0;
	return 1;
}

void swap(char *a, char *b)
{
	char x = *a;
	*a = *b;
	*b = x;
}

void r_90(char **arr, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++) {
			swap(&arr[i][j], &arr[j][i]);
		}

	for (j = 0; j < n/2; j++)
		for (i = 0; i < n; i++)
			swap(&arr[i][j], &arr[i][n-j-1]);
}

void r_180(char **arr, int n)
{
	int i, j;
	for (i = 0; i < n/2; i++)
		for (j = 0; j < n; j++)
			swap(&arr[i][j], &arr[n-i-1][j]);
	for (j = 0; j < n/2; j++)
		for (i = 0; i < n; i++)
			swap(&arr[i][j], &arr[i][n-j-1]);
}

void r_270(char **arr, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++)
			swap(&arr[i][j], &arr[j][i]);
	for (i = 0; i < n/2; i++)
		for (j = 0; j < n; j++)
			swap(&arr[i][j], &arr[n-i-1][j]);
}

void r_reflection(char **arr, char **arr2, int n)
{
	int i, j;
	for (j = n-1; j >= 0; j--)
		for (i = 0; i < n; i++)
			arr2[i][n-j-1] = arr[i][j];
}

void r_combination(char **arr, char **arr2, int n)
{
	int i, j;
	r_reflection(arr, arr2, n);//need not
	for (i = n-1; i >= 0; i--)
		for (j = 0; j < n; j++)
			arr2[n-i-1][j] = arr[i][j];
}

int main()
{
	FILE *fin = fopen("transform.in", "r");
	FILE *fout = fopen("transform.out", "w");

	int i, j;
	int n;
	fscanf(fin, "%d", &n);
	char **arr = malloc_2d(n);
	char **arr2 = malloc_2d(n);
	char **arr3 = malloc_2d(n);

	for (i = 0; i < n; i++)
		fscanf(fin, "%s", arr[i]);
	for (i = 0; i < n; i++)
		fscanf(fin, "%s", arr2[i]);


	copy_2d(arr, arr3, n);
	r_90(arr3, n);

	if (equal_2d(arr2, arr3, n)) {
		fprintf(fout, "%d\n", R_90);
		goto end;
	}

	copy_2d(arr, arr3, n);
	r_180(arr3, n);
	if (equal_2d(arr2, arr3, n)) {
		fprintf(fout, "%d\n", R_180);
		goto end;
	}

	copy_2d(arr, arr3, n);
	r_270(arr3, n);
	if (equal_2d(arr2, arr3, n)) {
		fprintf(fout, "%d\n", R_270);
		goto end;
	}

	r_reflection(arr, arr3, n);
	if (equal_2d(arr2, arr3, n)) {
		fprintf(fout, "%d\n", R_REFLECTION);
		goto end;
	}

	/*combination*/
	r_reflection(arr, arr3, n);/*have not to write this line*/
	r_90(arr3, n);/*90 degrees*/
	if (equal_2d(arr2, arr3, n)) {
		fprintf(fout, "%d\n", R_COMBINATION);
		goto end;
	}
	r_90(arr3, n);/*180 degrees*/
	if (equal_2d(arr2, arr3, n)) {
		fprintf(fout, "%d\n", R_COMBINATION);
		goto end;
	}
	r_90(arr3, n);/*270 degrees*/
	if (equal_2d(arr2, arr3, n)) {
		fprintf(fout, "%d\n", R_COMBINATION);
		goto end;
	}

	if (equal_2d(arr, arr2, n)) {
		fprintf(fout, "%d\n", R_NOCHANGE);
		goto end;
	}

	fprintf(fout, "%d\n", R_INVAILD);

end:
	free_2d(arr, n);
	free_2d(arr2, n);
	free_2d(arr3, n);
	fclose(fin);
	fclose(fout);
}
