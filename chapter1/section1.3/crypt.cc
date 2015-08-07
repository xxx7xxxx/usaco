/*
ID: longyun3
LANG: C++
PROG: crypt1
*/

/*official method is better and simpler*/

#include <bits/stdc++.h>

using namespace std;

bool is_in_group(int num, vector<int> &vec)
{
        while (num) {
                if (find(vec.begin(), vec.end(), num % 10)
                                == vec.end())
                        return false;
                num /= 10;
        }
        return true;
}

bool next_perm(int &rec_num, vector<int> &vec)
{
        if (rec_num == 0) {
                rec_num = vec[0];
                int i = 4;
                while (i--) {
                        rec_num *= 10;
                        rec_num += vec[0];
                }
                return true;
        }
        int tmp_num = rec_num;
        vector<int>::iterator iter;
        int div_cnt = 0;
        while (tmp_num) {
                iter = find(vec.begin(), vec.end(), tmp_num % 10);
                if (iter == vec.end())
                        return false;   //should never happen
                if (iter+1 != vec.end()) {
                        tmp_num += *(iter+1) - tmp_num%10;
                        while (div_cnt--) {
                                tmp_num *= 10;
                                tmp_num += vec[0];
                        }
                        rec_num = tmp_num;
                        return true;
                }
                tmp_num /= 10;
                div_cnt++;
        }

        return false;
}

int main()
{
        ifstream        fin("crypt1.in");
        ofstream        fout("crypt1.out");
        vector<int>     vec;
        int i, n;

        fin >> n;
        while (n--) {
                fin >> i;
                vec.push_back(i);
        }

        sort(vec.begin(), vec.end());

        int rec_num = 0;
        n = 0;
        int abc, de, p1, p2, sum;
        for ( ;; ) {
                if (!next_perm(rec_num, vec))
                        break;
                abc = rec_num / 100;
                de = rec_num % 100;
                p1 = abc * (de % 10);
                p2 = abc * (de / 10);
                if (p1 > 999 || p2 > 999 ||
                        !is_in_group(p1, vec) || !is_in_group(p2, vec))
                        continue;
                sum = p1 + (p2*10);
                if (sum > 9999 || !is_in_group(sum, vec))
                        continue;
                n++;
        }

        fout << n << endl;

        return 0;
}
