#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_NUM (9)
#define NUM_OF_DIGITS (6)
#define NUM_OF_SEGMENTS (7)
#define BROKEN ('-')

#define chr2int(c) ((int)((c)-'0'))

const string digits[MAX_NUM+1] = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111010",
};

void get_all_time(vector<string>& table) {
    string t(NUM_OF_DIGITS, ' ');

    for (t[0] = '0'; t[0] <= '2'; t[0]++) {
        for (t[1] = '0'; t[1] <= ((t[0]=='2')?'3':'9'); t[1]++) {
            for (t[2] = '0'; t[2] <= '5'; t[2]++) {
                for (t[3] = '0'; t[3] <= '9'; t[3]++) {
                    for (t[4] = '0'; t[4] <= '5'; t[4]++) {
                        for (t[5] = '0'; t[5] <= '9'; t[5]++) {
                            table.push_back(t);
                        }
                    }
                }
            }
        }
    }
}

void build_segments(vector<string>& segments, const string& cur_time) {
    for (int i = 0; i < NUM_OF_DIGITS; i++) {
        segments.push_back(digits[chr2int(cur_time[i])]);
    }
}

void read_clock(vector<string>& clock) {
    for (int d = 0; d < NUM_OF_DIGITS; d++) {
        string n;

        for (int s = 0; s < NUM_OF_SEGMENTS; s++) {
            char c;
            cin >> c;
            n.push_back(c);
        }

        clock.push_back(n);
    }
}

bool is_matched(const vector<string>& clock, const vector<string>& time) {
    for (int d = 0; d < NUM_OF_DIGITS; d++) {
        for (int s = 0; s < NUM_OF_SEGMENTS; s++) {
            if (clock[d][s] != BROKEN && clock[d][s] != time[d][s]) {
                return false;
            }
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> clock, all_time;

    read_clock(clock);
    get_all_time(all_time);

    for (int i = 0; i < all_time.size(); i++) {
        vector<string> seg_state;
        const string& cur_time = all_time[i];

        build_segments(seg_state, cur_time);

        if (is_matched(clock, seg_state)) {
            cout << cur_time.substr(0, 2) << ':'
                    << cur_time.substr(2, 2) << ':'
                    << cur_time.substr(4, 2) << '\n';
        }
    }

    return 0;
}