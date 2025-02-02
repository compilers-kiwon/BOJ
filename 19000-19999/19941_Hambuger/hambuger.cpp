#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string str;
    int N, K, cnt;
    queue<int> p, h;

    cin>>N>>K>>str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'P') {
            p.push(i);
        } else {
            h.push(i);
        }
    }

    cnt = 0;
    
    for (; !p.empty(); p.pop()) {
        bool found = false;
        int p_pos = p.front();

        for (;found != true && !h.empty() && (h.front() <= p_pos + K); h.pop()) {
            int h_pos = h.front();

            if (abs(h_pos - p_pos) <= K) {
                cnt++, found = true;
            }
        }
    }

    cout<<cnt<<'\n';

    return 0;
}