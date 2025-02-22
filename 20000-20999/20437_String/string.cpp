#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define NONE (-1)
#define NUM_OF_LETTERS (26)
#define get_idx(c) ((int)((c)-'a'))

void analyze_string(const string& str, vector<int>* table) {
    for (int i = 1; i < str.length(); i++) {
        table[get_idx(str[i])].push_back(i);
    }
}

pair<int,int> play_game(const string& str, int K) {
    int ret3, ret4;
    vector<int> table[NUM_OF_LETTERS];

    analyze_string(str, table);
    ret3 = str.length();
    ret4 = NONE;

    for (int i = 0; i < NUM_OF_LETTERS; i++) {
        const vector<int>& cur = table[i];

        if (cur.size() < K) {
            continue;
        }

        for (int head = 0; head <= cur.size() - K; head++) {
            int tail = head + K - 1;
            ret3 = min(ret3, cur[tail] - cur[head] + 1);
            ret4 = max(ret4, cur[tail] - cur[head] + 1);
        }
    }

    if (ret3 == str.length() || ret4 == NONE) {
        ret3 = ret4 = NONE;
    }

    return {ret3, ret4};
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int i = 1; i <= T; i++) {
        string W;
        int K;

        cin>>W>>K;
        W.insert(W.begin(), ' ');

        pair<int,int> result = play_game(W, K);
        
        if (result.first == NONE && result.second == NONE) {
            cout<<NONE<<'\n';
        } else {
            cout<<result.first<<' '<<result.second<<'\n';
        }
    }

    return 0;
}