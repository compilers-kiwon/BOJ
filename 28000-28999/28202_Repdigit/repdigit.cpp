#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_LEN (4000)

#define char2int(c) ((int)((c)-'0'))
#define int2char(i) ((char)((i)+(int)'0'))

vector<string> repdigit[10];

void init(void) {
    string str[10];

    for (int i = 1; i <= MAX_LEN; ++i) {
        for (int j = 1; j <= 9; j++) {
            str[j].push_back(int2char(j));
            repdigit[j].push_back(str[j]);
        }
    }
}

// left: input number, right: repdigit
bool is_greater(const string& left, const string& right) {
    return (left.length() > right.length() ||
            (left.length() == right.length() && left > right));
}

bool sub(const string& big, const string& small, string& result,
            int big_pos, int small_pos, int carry, int cur_digit) {
    if (big_pos < 0 && small_pos < 0) {
        return true;
    }

    int big_num = char2int(big[big_pos]) + carry;
    int small_num = char2int(small_pos<0?'0':small[small_pos]);
    
    int digit = big_num - small_num;

    if (big_pos == 0 && digit == 0) {
        return true;
    }

    if (digit < 0) {
        digit += 10;
        carry = -1;
    } else {
        carry = 0;
    }

    if (cur_digit == -1) {
        cur_digit = digit;
    } else {
        if (cur_digit != digit) {
            return false;
        }
    }

    result.push_back(int2char(digit));

    return sub(big, small, result, big_pos - 1, small_pos -1, carry, cur_digit);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;
    init();
    
    for (int i = 1; i <= t; ++i) {
        string n;

        cin>>n;

        for (int digit = 1; digit <= 9; ++digit) {
            bool found = false;

            for (int i = 0; i < repdigit[digit].size(); ++i) {
                string result;
                string& cur_num = repdigit[digit][i];

                if (is_greater(n, cur_num) == false) {
                    break;
                }

                if (sub(n, cur_num, result, n.length() - 1, cur_num.length() - 1, 0, -1)) {
                    cout<<cur_num<<' '<<result<<'\n';
                    found = true;
                    break;
                }
            }

            if (found == true) {
                break;
            }
        }
    }

    return 0;
}