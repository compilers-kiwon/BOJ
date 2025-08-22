#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef pair<int, string> State;

int N, M, K;
vector<State> cur;
unordered_set<string> required;

void input(void) {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        State s;
        cin >> s.second >> s.first;
        cur.push_back(s);
    }

    for (int i = 1; i <= K; i++) {
        string s;
        cin >> s;
        required.insert(s);
    }
}

int get_base_score(void) {
    int ret = 0;

    for (int i = 0; i < cur.size(); i++) {
        const int& p = cur[i].first;
        const string& s = cur[i].second;
        
        if (required.find(s) != required.end()) {
            ret += p;
        }
    }

    return ret;
}

int get_min_score(int num) {
    int ret = 0;

    for (int i = 0; i < cur.size() && num > 0; i++) {
        const int& p = cur[i].first;
        const string& s = cur[i].second;
        
        if (required.find(s) == required.end()) {
            ret += p, num--;
        }
    }

    return ret;
}

int get_max_score(int num) {
    int ret = 0;

    for (int i = cur.size() - 1; i >= 0 && num > 0; i--) {
        const int& p = cur[i].first;
        const string& s = cur[i].second;
        
        if (required.find(s) == required.end()) {
            ret += p, num--;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int base_score;

    input();
    base_score = get_base_score();
    sort(cur.begin(), cur.end());

    cout << base_score + get_min_score(M - K) << ' '
            << base_score + get_max_score(M - K) << '\n';
    
    return 0;
}