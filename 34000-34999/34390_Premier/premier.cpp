#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

enum {
    MP = 0,
    NUM_OF_WINS = 1,
    NUM_OF_DRAWS = 2,
    NUM_OF_LOSSES = 3,
    GF = 4,
    GA = 5,
    GD = 6,
    PTS = 7,
    MAX_SIZE = 8,
};

typedef long long int int64;

unordered_map<string, int64[MAX_SIZE]> tdata;
map<pair<int64, int64>, vector<string>> sorted;

void input(void) {
    string t1, t2;
    int64 X, Y;
    char c;

    cin >> t1 >> X >> c >> Y >> t2;

    tdata[t1][MP]++, tdata[t2][MP]++;
    
    tdata[t1][GF] += X;
    tdata[t2][GF] += Y;

    tdata[t1][GA] += Y;
    tdata[t2][GA] += X;

    tdata[t1][GD] += X - Y;
    tdata[t2][GD] += Y - X;

    if (X > Y) {
        tdata[t1][NUM_OF_WINS]++;
        tdata[t1][PTS] += 3;

        tdata[t2][NUM_OF_LOSSES]++;
    } else if (X < Y) {
        tdata[t2][NUM_OF_WINS]++;
        tdata[t2][PTS] += 3;

        tdata[t1][NUM_OF_LOSSES]++;
    } else {    // X == Y , Draw
        tdata[t1][NUM_OF_DRAWS]++;
        tdata[t1][PTS] += 1;

        tdata[t2][NUM_OF_DRAWS]++;
        tdata[t2][PTS] += 1;
    }
}

void sort_team(void) {
    for (auto it = tdata.begin(); it != tdata.end(); it++) {
        pair<int64, int64> i = {-(it->second[PTS]), -(it->second[GD])};
        sorted[i].push_back(it->first);
    }

    for (auto it = sorted.begin(); it != sorted.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
}

void print(void) {
    for (auto it = sorted.begin(); it != sorted.end(); it++) {
        const vector<string>& teams = it->second;

        for (int i = 0; i < teams.size(); i++) {
            int64* ptr = tdata[teams[i]];

            cout << teams[i] << ' ' << ptr[MP] << ' ' << ptr[NUM_OF_WINS] << ' '
                    << ptr[NUM_OF_DRAWS] << ' ' << ptr[NUM_OF_LOSSES] << ' '
                    << ptr[GF] << ' ' << ptr[GA] << ' ' << ptr[GD] << ' '
                    << ptr[PTS] << '\n';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        input();
    }

    sort_team();
    print();

    return 0;
}