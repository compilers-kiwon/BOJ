#include <iostream>
#include <string>

using namespace std;

#define REDUNDANT_ZERO_POS (2)
#define REDUNDANT_ZERO_CNT (1)

#define chr2int(c) ((int)((c)-'0'))

string get_half(const string& num) {
    string ret;
    int sub_num = chr2int(num[0]);

    for (int pos = 1; pos < num.length(); pos++) {
        sub_num = (sub_num * 10) + chr2int(num[pos]);
        ret += to_string (sub_num / 2);
        sub_num %= 2;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string ans, cur_num;
    
    cin >> N, cur_num = "1", ans ="0.";

    for (int i = 1; i <= N; i++) {
        if (cur_num.front() == '1') {
            ans.push_back('0');
        }

        cur_num.push_back('0');
        cur_num = get_half(cur_num);
    }

    ans.erase(REDUNDANT_ZERO_POS, REDUNDANT_ZERO_CNT);
    cout << ans << cur_num << '\n';

    return 0;
}