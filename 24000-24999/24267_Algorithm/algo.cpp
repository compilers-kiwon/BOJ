#include    <iostream>

using namespace std;

typedef long long int   int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   n,cnt;

    cin>>n;
    cnt = 0;

    for(int64 i=1;i<=n-2;i++)
    {
        cnt += i*(i+1)/2;
    }

    cout<<cnt<<'\n'<<3<<'\n';
    return  0;
}