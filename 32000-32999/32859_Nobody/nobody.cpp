#include <iostream>
#include <set>

using namespace std;

#define MAX_NUM_OF_POEPLE (2000)
#define MAX_NUM_OF_EVENTS (2*MAX_NUM_OF_POEPLE+1)

const int DEPOSIT = 1;
const int FORM = 0;

typedef pair<int, int> Event;

Event e[MAX_NUM_OF_EVENTS];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M, S;
    bool nobody = true;

    cin>>N>>M>>S;

    for (int n = 1; n <= M; n++) {
        cin>>e[n].first>>e[n].second;
    }

    for (int i = 1; i <= N; i++) {
        bool deposit = false;
        bool form = false;
        int num_of_prev_forms = 0;

        for (int j = 1; j <= M; j++) {
            int& who = e[j].first;
            int& what = e[j].second;

            if (who == i) {
                if (what == DEPOSIT) {
                    deposit = true;
                } else {
                    form = true;
                }
            } else {
                if (what == FORM && deposit == true && form == false) {
                    num_of_prev_forms++;
                }
            }
        }

        if (num_of_prev_forms >= S) {
            cout<<i<<'\n';
            nobody = false;
        }
    }

    if (nobody) {
        cout<<"-1\n";
    }

    return 0;
}