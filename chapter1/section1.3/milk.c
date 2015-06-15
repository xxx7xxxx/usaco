/*
ID: longyun3
LANG: C
TASK: milk
*/

#include <stdio.h>
#include <stdlib.h>

struct farmer {
        int price;
        int amount;
};

int farmer_comp(const void *x, const void *y)
{
        const struct farmer *xx = (const struct farmer *)x;
        const struct farmer *yy = (const struct farmer *)y;
        return xx->price - yy->price;
}

int main()
{
        FILE *fin = fopen("milk.in", "r");
        FILE *fout = fopen("milk.out", "w");
        int i, total, num, sum, cur_amount;
        struct farmer fms[5000];

        fscanf(fin, "%d %d", &total, &num);

        for (i = 0; i < num; i++)
                fscanf(fin, "%d %d", &fms[i].price, &fms[i].amount);

        qsort(fms, num, sizeof(fms[0]), farmer_comp);
        sum = 0;
        for (i = 0; i < num; i++) {
                if (total <= 0)
                        break;
                cur_amount = fms[i].amount;
                if (total < cur_amount) {
                        cur_amount = total;
                }
                total -= cur_amount;
                sum += cur_amount * fms[i].price;
        }

        fprintf(fout, "%d\n", sum);

        fclose(fin);
        fclose(fout);
        return 0;
}
