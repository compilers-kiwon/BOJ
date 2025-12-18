#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define SECONDS_OF_DAY (24*60*60)
#define BLOCKED_SECONDS (40)

#define HOUR_POS (0)
#define MINUTE_POS (1)
#define SECOND_POS (2)

bool blocked[SECONDS_OF_DAY];

int convert_seconds(int h, int m, int s) {
    return (h * 3600) + (m * 60) + s;
}

void mark_seconds(int s) {
    for (int i = 0; i < BLOCKED_SECONDS; i++) {
        blocked[s+i] = true;
    }
}

void simulate(const string& h, const string& m, const string& s) {
    int sec = convert_seconds(stoi(h), stoi(m), stoi(s));
    mark_seconds(sec);
}

void parse_time(const string& str, vector<string>& result) {
    string cur;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ':') {
            result.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(str[i]);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int c, h;

    cin >> c >> h;

    for (int i = 1; i <= c + h; i++) {
        string t;
        vector<string> s;

        cin >> t;
        t.push_back(':');
        
        parse_time(t, s);
        simulate(s[HOUR_POS], s[MINUTE_POS], s[SECOND_POS]);
    }

    int cnt = 0;

    for (int i = 0; i < SECONDS_OF_DAY; i++) {
        cnt += (blocked[i])?0:1;
    }

    cout << cnt << '\n';

    return 0;
}