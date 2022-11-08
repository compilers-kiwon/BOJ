#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (2000+1)
#define UNKNOWN     -1

#define HOSTILE     0
#define FRIENDLY    1
#define EXPECTED(a) (((a)+1)%2)

int         N,M,attr[MAX_SIZE];
vector<int> hostile[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int A,B;

        cin>>A>>B;

        hostile[A].push_back(B);
        hostile[B].push_back(A);
    }
}

bool    verify_theory(int s)
{
    queue<int>  q;

    q.push(s);
    attr[s] = FRIENDLY;

    for(;!q.empty();q.pop())
    {
        int             current = q.front();
        vector<int>&    adj = hostile[current];

        for(int i=0;i<adj.size();i++)
        {
            if( attr[adj[i]] == UNKNOWN )
            {
                q.push(adj[i]);
                attr[adj[i]] = EXPECTED(attr[current]);
            }
            else
            {
                if( attr[adj[i]] == attr[current] )
                {
                    return  false;
                }
            }
        }
    }

    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    fill(&attr[1],&attr[N+1],UNKNOWN);

    for(int i=1;i<=N;i++)
    {
        if( attr[i]==UNKNOWN && verify_theory(i)==false )
        {
            cout<<"0\n";
            return  0;
        }
    }

    cout<<"1\n";
    return  0;
}