#include    <iostream>

using namespace std;

typedef long long int   int64;

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    int64 num;

    cin>>N;
    num = 0;

    for (int i=1;i<=N;i++) {
        char    c;
        cin>>c;
        num = (num<<1)+(c=='O'?1:0);
    }

    cout<<num<<'\n';
    return  0;
}