#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double x1, y1, r1, x2, y2, r2, dist;

    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

    if (dist < (r1+r2)*(r1+r2)) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }

    return 0;
}