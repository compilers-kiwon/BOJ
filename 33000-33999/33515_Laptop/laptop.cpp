#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T1, T2;
    cin>>T1>>T2;
    cout<<min(T1,T2)<<'\n';

    return 0;
}