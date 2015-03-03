/*
ID: longyun3
LANG: C
PROG: namenum
*/

#include <stdio.h>
#include <string.h>

#define NUM_DICT 4617

int main()
{
	FILE *fin = fopen("namenum.in", "r");
	FILE *fout = fopen("namenum.out", "w");
	FILE *fd = fopen("dict.txt", "r");
	char keys[10][4] = {{}, {},
		"ABC", "DEF",
		"GHI", "JKL",
		"MNO", "PRS",
		"TUV", "WXY"
	};
	char str[13];
	char num[13];
	int i, j, k, len;

	fscanf(fin, "%s", num);
	len = strlen(num);

	for (i = 0; i < NUM_DICT; i++) {
		fscanf(fd, "%s", str);
		if (strlen(str) != len)
			continue;
		for (j = 0; j < len; j++) {
			for (k = 0; k < 3; k++)
				if (str[j] == keys[num[j]-'0'][k])
					break;
			if (k == 3)
				break;
		}
		if (j != len)
			continue;
		fprintf(fout, "%s\n", str);
	}
	if (ftell(fout) == 0)
		fprintf(fout, "NONE\n");

	fclose(fd);
	fclose(fin);
	fclose(fout);
	return 0;
}
