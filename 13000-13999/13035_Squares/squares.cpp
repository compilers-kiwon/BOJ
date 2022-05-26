#include    <iostream>

using namespace std;

typedef unsigned long long  uint64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        uint64          A,B,C,n,diff,answer;

        cin>>A>>B>>C;
        n = max(A*B/(C*C),1ULL);

        diff = max(A*B,C*C*n)-min(A*B,C*C*n);
        answer = n;

        if( max(A*B,C*C*(n+1))-min(A*B,C*C*(n+1)) < diff )
        {
            answer = n+1;
        }

        cout<<answer*C*C<<'\n';
    }

    return  0;
}