#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    10

typedef struct{int a,b,p,q;} Ratio;

int     N,quantity[MAX_SIZE];
Ratio   r[MAX_SIZE];

vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<N;i++)
    {
        cin>>r[i].a>>r[i].b>>r[i].p>>r[i].q;
        
        connected[r[i].a].push_back(r[i].b);
        connected[r[i].b].push_back(r[i].a);
    }

    fill(&quantity[0],&quantity[N],1);
}

int     get_gcd(int a,int b)
{
    int big = max(a,b);
    int small = min(a,b);

    for(int mod=big%small;mod!=0;mod=big%small)
    {
        big = small;
        small = mod;
    }

    return  small;
}

void    print_quantity(void)
{
    for(int i=0;i<N;i++)
    {
        cout<<quantity[i]<<' ';
    }
}

void    dfs(int idx,int multiplier,bool visited[])
{
    for(int i=0;i<connected[idx].size();i++)
    {
        int&    adj = connected[idx][i];
        int&    q = quantity[adj];

        if( visited[adj] == true )
        {
            continue;
        }
        
        q *= multiplier;
        visited[adj] = true;

        dfs(adj,multiplier,visited);
    }
}

void    get_quantity(void)
{
    for(bool updated=true;updated!=false;)
    {
        updated = false;

        for(int i=1;i<N;i++)
        {
            int&    q1 = quantity[r[i].a];
            int&    q2 = quantity[r[i].b];
            bool    visited[MAX_SIZE] = {false,};

            if( q1*r[i].q == q2*r[i].p )
            {
                continue;
            }

            q1 *= r[i].p;
            q2 *= r[i].q;
            
            visited[r[i].a] = visited[r[i].b] = true;

            dfs(r[i].a,r[i].p,visited);
            dfs(r[i].b,r[i].q,visited);

            updated = true;
        }
    }
}

void    scale_down_quantity(void)
{
    int g = 0;

    for(int i=0;i<N;i++)
    {
        if( g == 0 )
        {
            g = quantity[i];
        }
        else
        {
            g = get_gcd(g,quantity[i]);
        }
    }

    for(int i=0;i<N;i++)
    {
        quantity[i] /= g;
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_quantity();

    scale_down_quantity();
    print_quantity();

    return  0;
}