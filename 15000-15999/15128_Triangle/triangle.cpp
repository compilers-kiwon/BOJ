#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 p1, q1, p2, q2;
    cin >> p1 >> q1 >> p2 >> q2;
    cout << (((p1*p2)%(2*q1*q2)==0)?1:0) << '\n';

    return 0;
}