#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    const int PUSH = 1;
    const int POP = 0;

    int S, N, M, cur_cnt;

    cur_cnt = 0;
    cin>>S>>N>>M;

    for (int i = 1; i <= N + M; i++) {
        int op;

        cin>>op;

        switch (op) {
            case POP:--cur_cnt;break;
            case PUSH:S*=(++cur_cnt>S)?2:1;break;
            default:/*do nothing*/;break;
        }
    }

    cout<<S<<'\n';
    return 0;
}