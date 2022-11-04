#include    <iostream>

using namespace std;

#define MAX_SIZE            (300+1)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define CONNECTED       1
#define DISCONNECTED    0

typedef pair<int,int>   Pos;

int N,Q,table[MAX_SIZE][MAX_SIZE];
Pos p[MAX_SIZE];

void    get_info(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int&    L = p[i].first;
        int&    R = p[i].second;

        cin>>L>>R;
    }
}

void    build_graph(void)
{
    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            int&    L1 = p[i].first;
            int&    R1 = p[i].second;
            int&    L2 = p[j].first;
            int&    R2 = p[j].second;

            if( IN_RANGE(L1,L2,R1) || IN_RANGE(L2,L1,R2) )
            {
                table[i][j] = table[j][i] = CONNECTED;
            }
        }
    }
}

void    get_distance(void)
{
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if( table[i][k]==DISCONNECTED || table[k][j]==DISCONNECTED )
                {
                    continue;
                }

                if( table[i][j]==DISCONNECTED || table[i][j]>table[i][k]+table[k][j] )
                {
                    table[i][j] = table[i][k]+table[k][j];
                }
            }
        }
    }
}

void    do_query(void)
{
    cin>>Q;

    for(int i=1;i<=Q;i++)
    {
        int A,B;

        cin>>A>>B;
        cout<<((table[A][B]==DISCONNECTED)?-1:table[A][B])<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    get_info();
    build_graph();

    get_distance();
    do_query();

    return  0;
}