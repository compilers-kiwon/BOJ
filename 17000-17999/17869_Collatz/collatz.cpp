#include    <iostream>

using namespace std;

typedef long long int   int64;

#define is_even(n)  ((n)%2==0)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   n,cnt;

    cin>>n;
    
    for(cnt=0;n!=1LL;cnt++)
    {
        is_even(n)?n/=2:n++;
    }

    cout<<cnt<<'\n';
    return  0;
}