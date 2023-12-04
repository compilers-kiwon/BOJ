#include    <iostream>
#include    <string>

using namespace std;

const static char NONE = ' ';

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  S;
    char prev = NONE;
    int cnt[0x100] = {0,};

    cin>>S;

    for (int i=0;i<S.length();i++) {
        if (prev == S[i]) continue;
        cnt[S[i]]++;
        prev = S[i];
    }

    cout<<min(cnt['0'],cnt['1'])<<'\n';
    return  0;
}