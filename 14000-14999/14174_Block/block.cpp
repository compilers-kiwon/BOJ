#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_SIZE (26)
#define get_idx(c) ((int)((c)-'a'))

void count_letters(const string& str, vector<int>& result) {
    for (int i = 0; i < str.length(); ++i) {
        ++result[get_idx(str[i])];
    }
}

void analyze_word(const string& front, const string& back, vector<int>& sum) {
    vector<int> front_cnt(MAX_SIZE, 0);
    vector<int> back_cnt(MAX_SIZE, 0);

    count_letters(front, front_cnt);
    count_letters(back, back_cnt);

    for (int i = 0; i < MAX_SIZE; ++i) {
        sum[i] += max(front_cnt[i], back_cnt[i]);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> sum(MAX_SIZE, 0);

    for (cin >> N; N > 0; --N) {
        string a, b;
        cin >> a >> b;
        analyze_word(a, b, sum);
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        cout << sum[i] << '\n';
    }

    return 0;
}