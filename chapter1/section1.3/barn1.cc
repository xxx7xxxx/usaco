/*
ID:     longyun3
PROG:   barn1
LANG:   C++
*/

#include <bits/stdc++.h>

using namespace std;

bool bigger_fun(int x, int y)
{
        return x > y;
}

int main()
{
        ifstream fin("barn1.in");
        ofstream fout("barn1.out");
        int i, max = 0, min = 201;
        int ans;
        int max_board, total_stall, cow_stall;
        int cow_in_stall[205];
        int gap[205], gap_cnt = 0;
        //memset(gap, 0, sizeof(gap));

        fin >> max_board >> total_stall >> cow_stall;
        if (max_board >= cow_stall) {
                fout << cow_stall << endl;
                return 0;
        }

        for (i = 0; i < cow_stall; i++)
                fin >> cow_in_stall[i];
        sort(cow_in_stall, cow_in_stall + cow_stall);

        for (i = 0; i < cow_stall; i++) {
                if (cow_in_stall[i] > max)
                        max = cow_in_stall[i];
                if (cow_in_stall[i] < min)
                        min = cow_in_stall[i];
                if (i != 0) {
                        gap[gap_cnt] = cow_in_stall[i] - cow_in_stall[i-1] - 1;
                        gap_cnt++;
                }
        }

        sort(gap, gap + gap_cnt, bigger_fun);
        ans = max - min + 1;
        for (i = 0; i < max_board - 1; i++)
                ans -= gap[i];
        fout << ans << endl;

        return 0;
}
