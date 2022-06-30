#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,m,k;

    cin>>n>>m>>k;
    cout<<((m>=k)?(m/k+k-1)*n:n*m)<<'\n';

    return  0;
}