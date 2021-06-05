#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_NUM 1000000

typedef unsigned long long  uint64;

bool    visited[MAX_NUM+1];

bool    is_prime(int n)
{
    bool    ret = true;

    for(int i=2,to=sqrt(n);i<=to;i++)
    {
        if( n%i == 0 )
        {
            ret = false;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    uint64  m = 1;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int A;

        cin>>A;

        if( visited[A]==false && is_prime(A)==true )
        {
            m *= (uint64)A;
            visited[A] = true;
        }
    }

    if( m == 1 )
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<m<<'\n';
    }
    
    return  0;
}