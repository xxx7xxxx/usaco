/*
ID: longyun3
LANG: C
PROG: gift1
*/
#include <stdio.h>

struct person {
	char name[15];
	int money;
};

int main()
{
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	struct person np[10];
	char tmp_name[15];
	int sum, divide_count;
	int i, j, k, n;

	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(fin, "%s", np[i].name);
		np[i].money = 0;
	}
	for (i = 0; i < n; i++) {
		fscanf(fin, "%s", tmp_name);
		fscanf(fin, "%d", &sum);
		fscanf(fin, "%d", &divide_count);
		if (divide_count == 0)
			continue;
		for (j = 0; j < n; j++) {
			if (strcmp(tmp_name, np[j].name) == 0) {
				np[j].money -= sum - sum%divide_count;
				break;
			}
		}

		for (j = 0; j < divide_count; j++) {
			fscanf(fin, "%s", tmp_name);
			for (k = 0; k < n; k++) {
				if (strcmp(tmp_name, np[k].name) == 0) {
					np[k].money += sum / divide_count;
					break;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
		fprintf(fout, "%s %d\n", np[i].name, np[i].money);

	return 0;
}
