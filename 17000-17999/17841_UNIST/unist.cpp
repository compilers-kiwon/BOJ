#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define MOD(n) ((n)%1000000007LL)

typedef long long int int64;

unordered_map<string, int64> prefix;

const string target = "UNIST";

void add_prefix(const string& sub, size_t pos) {
    if (pos == (size_t)0) {
        prefix[sub] = MOD(prefix[sub] + 1LL);
        return;
    }

    string ahead = target.substr(0, pos);
    string merged = ahead + sub;
    prefix[merged] = MOD(prefix[merged] + prefix[ahead]);
}

void get_prefix(const string& w) {
    string sub;

    for (int i = 0; i < min(w.length(), target.length()); ++i) {
        size_t pos;

        sub.push_back(w[i]);
        pos = target.find(sub);

        if (pos != string::npos) {
            add_prefix(sub, pos);
        } else {
            break;
        }
    }
}

void input(vector<string>& words) {
    int N;

    for (cin >> N; N > 0; --N) {
        string W;
        cin >> W;
        words.push_back(W);
    }
}

int64 simulate(const vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
        get_prefix(words[i]);
    }

    return prefix[target];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> words;

    input(words);
    cout << simulate(words) << '\n';

    return 0;
}