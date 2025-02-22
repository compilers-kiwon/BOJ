#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T, N, F;

    cin>>T>>N;

    for (F = 0; N > 0; N--) {
        int candy;
        cin>>candy;
        F += candy;
    }

    cout<<"Padaeng_i "<<(F>=T?"Happy":"Cry")<<'\n';

    return 0;
}