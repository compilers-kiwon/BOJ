#include    <iostream>

using namespace std;

typedef long long int int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   N;

    cin>>N;
    
    for (int64 base=1;base<=N;base*=10)
    {
        int64   d = (N/base)%10;

        if (d >= 5) {
            N += base*10;
            N -= N%(base*10);
        }
    }

    cout<<N<<'\n';

    return  0;
}