#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     K;
    string  S,D;

    cin>>K>>S;

    for(int i=0;i<S.length();i+=K)
    {
        D.push_back(S[i]);
    }

    cout<<D<<'\n';

    return  0;
}