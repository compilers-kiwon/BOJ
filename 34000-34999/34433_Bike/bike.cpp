#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> state;

int get_pos(const string& s) {
    int ret;

    if (s == "just me") {
        ret = 0;
    } else {
        ret = stoi(s.substr(0, s.find(' ')));
    }

    return ret;
}

int simulate(const vector<string>& data) {
    for (int i = 0; i < data.size(); i++) {
        int cur_pos = get_pos(data[i]);

        state[cur_pos+1] = max(0, state[cur_pos+1] - 1);
        state[cur_pos]++;
    }

    int ret = 0;

    for (auto it = state.begin(); it != state.end(); it++) {
        ret += it->second;
    }

    return ret;
}

int input(vector<string>& data) {
    int N;
    string s;

    getline(cin, s);
    N = stoi(s);

    for (int i = 1; i <= N; i++) {
        getline(cin, s);
        data.push_back(s);
    }

    return N;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int N;
    vector<string> data;

    N = input(data);
    cout << simulate(data) << ' ' << N << '\n';

    return 0;
}