#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M;

    cin>>N>>M;
    cout<<min(N>>1,M>>1)<<'\n';

    return  0;
}