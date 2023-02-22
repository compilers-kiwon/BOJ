#include    <iostream>
#include    <map>

using namespace std;

typedef long long int   int64;

static int64    N,P,Q;
static map<int64,int64> dp;

int64   get_dp(int64 n)
{
    if( n == 0 )
    {
        return  1;
    }

    map<int64,int64>::iterator  it;

    if( (it=dp.find(n)) != dp.end() )
    {
        return  it->second;
    }

    return  (dp[n]=get_dp(n/P)+get_dp(n/Q)); 
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>P>>Q;
    cout<<get_dp(N)<<'\n';

    return  0;
}