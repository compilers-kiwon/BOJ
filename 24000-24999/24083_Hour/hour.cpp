#include <iostream>

using namespace std;

#define get_pos(h) ((h)%12)

int get_hour(int from, int d) {
    int ret = get_pos(from + d);
    return ((ret==0)?12:ret);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    cout << get_hour(A, B) << '\n';

    return 0;
}