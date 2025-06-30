#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string S;

    cin>>N>>S;

    int cnt[0x100] = {0, };

    for (size_t i = 0; i < S.length(); i++) {
        cnt[S[i]]++;
    }

    cout<<(cnt['O']>=cnt['X']?"Yes":"No")<<'\n';

    return 0;
}