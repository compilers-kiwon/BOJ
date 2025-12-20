#include <iostream>

using namespace std;

int get_value(int width) {
    int ret = 0;

    switch (width) {
        case 136: ret = 1000; break;
        case 142: ret = 5000; break;
        case 148: ret = 10000; break;
        case 154: ret = 50000; break;
        default: break;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, sum;

    for (cin >> N, sum = 0; N > 0; N--) {
        int w, h;
        cin >> w >> h;
        sum += get_value(w);
    }

    cout << sum << '\n';

    return 0;
}