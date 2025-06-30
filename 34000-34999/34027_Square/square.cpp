#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t = 1; t <= T; t++) {
        int N;

        cin>>N;
        cout<<(((int)sqrt(N)*(int)sqrt(N))==N?1:0)<<'\n';
    }

    return 0;
}