/*
ID: longyun3
LANG: C
PROG: friday
 */

#include <stdio.h>

int main()
{
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");
	int days_in_month[13] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	int res[7] = {0};
	int year = 1900, month = 1, day = 1;
	int n, end_year;
	int which_day = 1;
	/*0 is Sunday*/

	fscanf(fin, "%d", &n);
	end_year = 1900 + n -1;

	while (year <= end_year) {
		if (day == 13)
			res[which_day]++;
		/*add a day and adjust other variable*/
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
			days_in_month[2] = 29;
		else
			days_in_month[2] = 28;

		if (day < days_in_month[month])
			day++;
		else {
			day = 1;
			if (month < 12)
				month++;
			else {
				month = 1;
				year++;
			}
		}
		which_day++;
		which_day %= 7;
	}

	fprintf(fout, "%d %d %d %d %d %d %d\n",
		res[6], res[0], res[1], res[2], 
		res[3], res[4], res[5]);
	fclose(fin);
	fclose(fout);
	
	return 0;
}
