#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S, T;
    bool included[0x100] = {false, };

    cin>>S>>T;

    for (size_t i = 0; i < S.length(); i++) {
        included[S[i]] = true;
    }

    string ans;

    for (size_t i = 0; i < T.length(); i++) {
        if (!included[T[i]]) {
            ans.push_back(T[i]);
        }
    }

    cout<<ans<<'\n';

    return 0;
}