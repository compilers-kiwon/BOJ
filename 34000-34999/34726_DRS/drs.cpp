#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int const head = 0;
int const allowed = 1000;

void input(map<int, string>& track) {
    int N, T, pos;

    for (cin >> N >> T, pos = 0; N > 0; --N) {
        int t;
        string D;

        cin >> D >> t;
        pos = (pos + t) % T;
        track[pos] = D;
    }

    track[T] = track[head];
}

void simulate(set<string>& drs, map<int, string> track) {
    int prev_pos = -(allowed + 1);

    for (auto it = track.begin(); it != track.end(); ++it) {
        int cur_pos = it->first;

        if (cur_pos - prev_pos <= allowed) {
            drs.insert(it->second);
        }

        prev_pos = cur_pos;
    }

    if (drs.empty()) {
        drs.insert("-1");
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    set<string> drs;
    map<int, string> track;

    input(track);
    simulate(drs, track);

    for (auto it = drs.begin(); it != drs.end(); ++it) {
        cout << *it << ' ';
    }

    cout << '\n';

    return 0;
}