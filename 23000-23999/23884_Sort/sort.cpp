#include    <iostream>
#include    <map>

using namespace std;

#define MAX_SIZE    (500000+1)

int             N,K,A[MAX_SIZE];
map<int,int>    table;  // table[value] = index;

void    input(void)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
        table[A[i]] = i;
    }
}

bool    simulate(void)
{
    bool    ret = false;

    for(int i=N,cnt=0;i>=1;i--)
    {
        int max_value = table.rbegin()->first;
        int max_pos = table.rbegin()->second;

        table.erase(max_value);
        
        if( max_pos == i )
        {
            continue;
        }

        table[A[i]] = max_pos;
        swap(A[max_pos],A[i]);

        if( ++cnt == K )
        {
            ret = true;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    if( simulate() == true )
    {
        for(int i=1;i<=N;i++)
        {
            cout<<A[i]<<' ';
        }
        cout<<'\n';
    }
    else
    {
        cout<<"-1\n";
    }

    return  0;
}