#include <iostream>

using namespace std;

typedef long long int int64;
typedef pair<int64, int64> State;

int64 calculate(int64 num, State s) {
    return ((num * s.second) + s.first);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Q;
    State s;
    int64 pos;

    for (pos = 1, s = {0, 1}, cin >> Q; Q > 0; Q--) {
        int x;
        int64 n;

        cin >> x;

        switch (x) {
            case 0:
                cin >> n;
                s.first += n;
                break;
            case 1:
                cin >> n;
                s.first *= n, s.second *= n;
                break;
            case 2:
                cin >> n;
                pos += n;
                break;
            case 3:
                cout << calculate(pos, s) << '\n';
                break;
            default:
                break;
        }
    }

    return 0;
}