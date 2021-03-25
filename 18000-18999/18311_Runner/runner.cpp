#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100000+1)

typedef long long int   int64;

int     N;
int64   K,course[MAX_SIZE];

void    input(void)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>course[i];
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 current;

    input();
    current = 0;

    for(int i=1;i<=N;i++)
    {
        int64 end = current+course[i];

        if( current<=K && K<end )
        {
            cout<<i<<'\n';
            return  0;
        }

        current = end;
    }

    for(int i=N;i>=1;i--)
    {
        int64 end = current+course[i];

        if( current<=K && K<end )
        {
            cout<<i<<'\n';
            return  0;
        }

        current = end;
    }

    return  0;
}