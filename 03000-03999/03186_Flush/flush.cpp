#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (10000+1)

#define DONE        0
#define OCCUPIED    1

int     K,L,N,cnt[MAX_SIZE];
char    state[MAX_SIZE+1];

void    input(void)
{
    cin>>K>>L>>N>>&state[1];

    for(int i=1;i<=N;i++)
    {
        if( state[i-1] == state[i] )
        {
            cnt[i] = cnt[i-1]+1;
        }
        else
        {
            cnt[i] = 1;
        }
    }
}

void    simulate(vector<int>& flush)
{
    int current_state = DONE;

    for(int i=1;i<=N;i++)
    {
        switch(current_state)
        {
            case    DONE:
                if( state[i]=='1' && cnt[i]==K )
                {
                    current_state = OCCUPIED;
                }
                break;
            case    OCCUPIED:
                if( state[i]=='0' && cnt[i]==L )
                {
                    current_state = DONE;
                    flush.push_back(i);
                }
                break;
            default:
                // do nothing
                break;
        }
    }

    if( current_state == OCCUPIED )
    {
        int tmp = N+L;

        if( state[N] == '0' )
        {
            tmp -= cnt[N];
        }

        flush.push_back(tmp);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> f;

    input();
    simulate(f);

    if( f.empty() )
    {
        cout<<"NIKAD\n";
    }
    else
    {
        for(int i=0;i<f.size();i++)
        {
            cout<<f[i]<<'\n';
        }
    }

    return  0;
}