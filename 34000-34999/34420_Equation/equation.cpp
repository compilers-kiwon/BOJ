#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t1, e1, t2, e2, t3, e3;

    cin >> t1 >> e1;
    cin >> t2 >> e2;
    cin >> t3 >> e3;

    int A1 = t2*t2 - t1*t1;
    int B1 = t2 - t1;
    int C1 = e2 - e1;

    int A2 = t3*t3 - t2*t2;
    int B2 = t3 - t2;
    int C2 = e3 - e2;

    int n = A1*B2 - A2*B1;
    int a = (C1*B2 - C2*B1) / n;
    int b = (A1*C2 - A2*C1) / n;
    int c = e1 - a*t1*t1 - b*t1;

    cout << a << " " << b << " " << c << '\n';

    return 0;
}