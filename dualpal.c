/*
 ID: longyun3
 LANG: C
 TASK: dualpal
*/

#include <stdio.h>
#include <string.h>

int is_dualpal_helper(char *s)
{
        int len = strlen(s);
        int i = 0, j = len - 1;
        while (i < j){
                if (s[i] != s[j])
                        return 0;
                i++;
                j--;
        }
        return 1;
}

void transfrom_base_k(char *s, int n, int k)
{
        if (n == 0) {
                strcpy(s, "");
                return;
        }
        int len;

        transfrom_base_k(s, n/k, k);
        len = strlen(s);
        s[len] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n%k];
        s[len+1] = '\0';
}

int is_dualpal(int n)
{
        char s[100];
        int k;
        int cnt = 0;
        for (k = 2; k <= 10; k++) {
                transfrom_base_k(s, n, k);
                if (is_dualpal_helper(s)) {
                        cnt++;
                }
                if (cnt >= 2)
                        return 1;
        }
        return 0;
}

int main()
{
        FILE *fin = fopen("dualpal.in", "r");
        FILE *fout = fopen("dualpal.out", "w");
        int i, num, start;

        fscanf(fin, "%d %d", &num, &start);
        for (i = start+1; ; i++) {
                if (is_dualpal(i)) {
                        if (num-- <= 0)
                                break;
                        fprintf(fout, "%d\n", i);
                }
        }

        fclose(fin);
        fclose(fout);

        return 0;
}
