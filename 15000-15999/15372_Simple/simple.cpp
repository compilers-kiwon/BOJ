#include    <iostream>

using namespace std;

typedef long long int   int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int64   N;

        cin>>N;
        cout<<N*N<<'\n';
    }

    return  0;
}