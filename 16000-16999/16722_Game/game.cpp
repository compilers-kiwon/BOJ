#include <iostream>
#include <string>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

#define MAX_SIZE (9)

typedef tuple<string, string, string> Shape; 
Shape s[MAX_SIZE+1];
bool table[MAX_SIZE+1][MAX_SIZE+1][MAX_SIZE+1];
set<tuple<int, int, int>> solutions;

bool is_equal(const string& a, const string& b, const string& c) {
    return (a == b && b == c && c == a);
}

bool is_different(const string& a, const string& b, const string& c) {
    return (a != b && b != c && c != a);
}

bool is_hab(int s1, int s2, int s3) {
    auto [a1, b1, c1] = s[s1];
    auto [a2, b2, c2] = s[s2];
    auto [a3, b3, c3] = s[s3];

    if (is_equal(a1, a2, a3) == false &&
            is_different(a1, a2, a3) == false) {
        return false;
    }

    if (is_equal(b1, b2, b3) == false &&
            is_different(b1, b2, b3) == false) {
        return false;
    }

    if (is_equal(c1, c2, c3) == false &&
            is_different(c1, c2, c3) == false) {
        return false;
    }

    return true;
}

void build_table(void) {
    for (int  i = 1; i <= MAX_SIZE - 2; ++i) {
        for (int j = i + 1; j <= MAX_SIZE - 1; ++j) {
            for (int k = j + 1; k <= MAX_SIZE; ++k) {
                if (is_hab(i, j, k) == true) {
                    table[i][j][k] = true;
                    solutions.insert({i, j, k});
                }                
            }
        }
    }
}

void read_shapes(void) {
    for (int i = 1; i <= MAX_SIZE; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        s[i] = {a, b, c};
    }
}

int play_hab(void) {
    int ret, num[3];
    tuple<int, int, int> n;

    cin >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);
    n = {num[0], num[1], num[2]};

    if (table[num[0]][num[1]][num[2]] == true
            && solutions.find(n) != solutions.end()) {
        solutions.erase(n);
        table[num[0]][num[1]][num[2]] = false;
        ret = 1;
    } else {
        ret = -1;
    }

    return ret;
}

int play_gyul(void) {
    static bool visited = false;

    if (!solutions.empty() || visited == true) {
        return -1;
    }

    visited = true;
    return 3;
}

int play_game(void) {
    int score, n;

    for (cin >> n, score = 0; n > 0; --n) {
        char c;

        cin >> c;

        if (c == 'H') {
            score += play_hab();
        } else {
            score += play_gyul();
        }
    }

    return score;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_shapes();
    build_table();
    cout << play_game() << '\n';

    return 0;
}