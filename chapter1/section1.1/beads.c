/*
ID: longyun3
LANG: C
PROG: beads
*/

/*My solotion is a bit complex, I'll improve it in future*/
#include <stdio.h>

#define MAX_LEN 400

int is_same_color(char x, char y);
int left_count(char necklace[], int point, int len);
int right_count(char necklace[], int point, int len);

int main()
{
	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");
	char necklace[MAX_LEN];
	int len;
	int i, cur_max, max = 2;

	fscanf(fin, "%d %s", &len, necklace);


	for (i = 0; i < len; i++) {
		cur_max = left_count(necklace, i, len) +
		 right_count(necklace, i, len);
		if (cur_max > max) {
			max = cur_max;
		}
		printf("%d %d\n", i, cur_max);
	}
	if (max > len)
		max = len;
	fprintf(fout, "%d\n", max);

	fclose(fin);
	fclose(fout);
	return 0;
}

/*x is always original(head) color*/
inline int is_same_color(char x, char y)
{
	if (x == y || y == 'w')
		return 1;
	else
		return 0;
}

int left_count(char necklace[], int point, int len)
{
	int i, count = 1;
	int left_point;
	char original_color;
	int is_change = 0;

	if (point == 0)/*left do not count current index*/
		point = len - 1;
	else
		point--;
	original_color = necklace[point];

	for (i = 0; i < len-1; i++) {
		left_point =
		point == 0 ? len-1 : point-1;
		/*if original_color is 'w', we shoule change it to the color
		  we meet firstly, which is not 'w'*/
		if (!is_change && original_color == 'w' &&
				necklace[left_point] != 'w') {
			original_color = necklace[left_point];
			is_change = 1;
		}

		if (is_same_color(original_color, necklace[left_point]))
			count++;
		else
			break;
		point = left_point;
	}
	return count;
}

int right_count(char necklace[], int point, int len)
{
	int i, count = 1;
	int right_point;
	int is_change = 0;
	char original_color = necklace[point];

	for (i = 0; i < len-1; i++) {
		right_point =
		point == len-1 ? 0 : point+1;
		/*if original_color is 'w', we shoule change it to the color
		  we meet firstly, which is not 'w'*/
		if (!is_change && original_color == 'w' &&
				necklace[right_point] != 'w') {
			original_color = necklace[right_point];
			is_change = 1;
		}

		if (is_same_color(original_color, necklace[right_point]))
			count++;
		else
			break;
		point = right_point;
	}

	return count;
}
