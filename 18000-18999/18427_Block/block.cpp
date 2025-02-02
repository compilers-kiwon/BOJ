#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_NUM_OF_STUDENTS (50+1)
#define MAX_HEIGHT (1000+1)

#define MOD(n) ((n)%10007)
#define char2int(c) ((int)((c)-'0'))

int N, H, M, table[MAX_NUM_OF_STUDENTS][MAX_HEIGHT];
vector<int> blocks_in_hand[MAX_NUM_OF_STUDENTS];

void get_numbers(const string& str, vector<int>& numbers) {
    int num = 0;

    for (size_t i = 0; i < str.length(); i++) {
        const char& c = str[i];

        if (c == ' ') {
            numbers.push_back(num);
            num = 0;
        } else {
            num = (num * 10) + char2int(c); 
        }
    }
}

void input(void) {
    cin>>N>>M>>H;
    getchar();

    for (int i = 1; i <= N; i++) {
        string str;

        getline(cin, str);
        str.push_back(' ');

        get_numbers(str, blocks_in_hand[i]);
        sort(blocks_in_hand[i].begin(), blocks_in_hand[i].end());
    }
}

int simulate(void) {
    for (int cur = 1; cur <= N; cur++) {
        for (int i = 0; i < blocks_in_hand[cur].size(); i++) {
            table[cur][blocks_in_hand[cur][i]] = 1;
        }

        int prev = cur - 1;

        for (int h = 1; h <= H; h++) {
            if (table[prev][h] != 0) {
                table[cur][h] = MOD(table[cur][h] + table[prev][h]);

                for (int i = 0; i < blocks_in_hand[cur].size(); i++) {
                    int block = blocks_in_hand[cur][i];

                    if ((h + block) > H) {
                        break;
                    }

                    table[cur][h+block] = MOD(table[cur][h+block] + table[prev][h]); 
                }
            }
        }
    }

    return table[N][H];
}

int main(void) {
    input();
    cout<<simulate()<<'\n';
    return 0;
}