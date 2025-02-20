#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

#define MAX_SIZE (100+1)

int N, M;
string game[MAX_SIZE], candidate[MAX_SIZE];
unordered_set<string> used;

#define is_connected(left,right) ((left).back()==(right).front())

int input(void) {
    int ret;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        cin>>game[i];

        if (game[i] == "?") {
            ret = i;
        } else {
            used.insert(game[i]);
        }
    }

    cin>>M;

    for (int i = 1; i <= M; i++) {
        cin>>candidate[i];
    }

    return ret;
}

int simulate(int empty_pos) {
    int ret;

    for (int i = 1; i <= M; i++) {
        const string& w = candidate[i];

        if (used.find(w) != used.end()) {
            continue;
        }

        if (empty_pos == 1) {
            if (is_connected(w,game[empty_pos+1])) {
                ret = i;
                break;
            }
        } else if (empty_pos == N) {
            if (is_connected(game[empty_pos-1],w)) {
                ret = i;
                break;
            }
        } else {
            if (is_connected(game[empty_pos-1],w)
                    && is_connected(w,game[empty_pos+1])) {
                ret = i;
                break;
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int q_pos, missed;
    
    q_pos = input();
    missed = ((N==1)?1:simulate(q_pos));
    cout<<candidate[missed]<<'\n';

    return 0;
}