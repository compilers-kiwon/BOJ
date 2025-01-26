#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int L, R, A;

    cin>>L>>R>>A;

    for (; A > 0; A--) {
        if (L <= R) {
            L++;
        } else {
            R++;
        }
    }

    cout<<2*min(L, R)<<'\n';
    return 0;
}