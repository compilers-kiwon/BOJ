#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE (3)

string input(void) {
    string ret;

    for (int i = 1; i <= MAX_SIZE; i++) {
        string s;
        cin >> s;
        ret += s;
    }

    return ret;
}

int get_num_of_green(string& c, string& g) {
    int ret = 0;

    for (int i = 0; i < MAX_SIZE * MAX_SIZE; i++) {
        if (c[i] == g[i]) {
            ret++, c[i] = g[i] = ' ';
        }
    }

    return ret;
}

int get_num_of_yellow(const string& c, const string& g) {
    int correct_cnt[0x100], guess_cnt[0x100];

    fill(&correct_cnt['A'], &correct_cnt['Z'+1], 0);
    fill(&guess_cnt['A'], &guess_cnt['Z'+1], 0);

    for (int i = 0; i < MAX_SIZE * MAX_SIZE; i++) {
        if (isalpha(c[i])) {
            correct_cnt[c[i]]++;
        }

        if (isalpha(g[i])) {
            guess_cnt[g[i]]++;
        }
    }

    int ret = 0;

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        ret += (correct_cnt[ch]!=0)?
                min(correct_cnt[ch], guess_cnt[ch]):0;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string correct = input();
    string guess = input();

    cout << get_num_of_green(correct, guess) << '\n';
    cout << get_num_of_yellow(correct, guess) << '\n';

    return 0;
}