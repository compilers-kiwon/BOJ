#include    <iostream>

using namespace std;

#define QUATA   60
#define WITHIN  1500
#define EXTRA   3000

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,k,q;

    cin>>n>>k;
    q = min(k+QUATA,n);

    cout<<q*WITHIN+max(0,n-q)*EXTRA<<'\n';

    return  0;
}