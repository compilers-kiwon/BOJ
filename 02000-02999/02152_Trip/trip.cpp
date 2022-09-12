#include    <iostream>
#include    <vector>
#include    <queue>
#include    <stack>
#include    <set>

using namespace std;

#define MAX_SIZE        (10000+1)
#define FIRST_PHASE     1
#define SECOND_PHASE    2

int         N,M,S,T,dp[MAX_SIZE];
int         my_scc[MAX_SIZE],scc_size[MAX_SIZE];
bool        visited[MAX_SIZE];
vector<int> fw[MAX_SIZE],bw[MAX_SIZE];
stack<int>  st;
set<int>    scc_graph[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>S>>T;

    for(int i=1;i<=M;i++)
    {
        int A,B;

        cin>>A>>B;

        fw[A].push_back(B);
        bw[B].push_back(A);
    }
}

void    dfs1(int current)
{
    visited[current] = true;

    vector<int>&    adj = fw[current];

    for(int i=0;i<adj.size();i++)
    {
        if( visited[adj[i]] == false )
        {
            dfs1(adj[i]);
        }
    }

    st.push(current);
}

void    dfs2(int current,int scc_no)
{
    visited[current] = true;
    my_scc[current] = scc_no;
    scc_size[scc_no]++;

    vector<int>&    adj = bw[current];

    for(int i=0;i<adj.size();i++)
    {
        if( visited[adj[i]] == false )
        {
            dfs2(adj[i],scc_no);
        }
    }
}

void    find_scc(void)
{
    for(int i=1;i<=N;i++)
    {
        if( visited[i] == false )
        {
            dfs1(i);
        }
    }
    
    fill(&visited[1],&visited[N+1],false);
    
    for(int scc_idx=0;!st.empty();st.pop())
    {
        int current = st.top();

        if( visited[current] == true )
        {
            continue;
        }

        scc_idx++;
        dfs2(current,scc_idx);
    }
}

void    build_scc_graph(void)
{
    for(int i=1;i<=N;i++)
    {
        vector<int>&    adj = fw[i];

        for(int j=0;j<adj.size();j++)
        {
            int scc1 = my_scc[i];
            int scc2 = my_scc[adj[j]];
            
            if( scc1 != scc2 )
            {
                scc_graph[scc1].insert(scc2);
            }
        }
    }
}

int     move_in_scc(void)
{
    int from = my_scc[S];
    int to = my_scc[T];

    queue<int>  q;
    
    q.push(from);
    dp[from] = scc_size[from];

    for(;!q.empty();q.pop())
    {
        int current = q.front();
        
        if( current == to )
        {
            continue;
        }

        set<int>&   adj = scc_graph[current];

        for(set<int>::iterator it=adj.begin();it!=adj.end();it++)
        {
            if( dp[*it]==0 || dp[*it]<dp[current]+scc_size[*it] )
            {
                q.push(*it);
                dp[*it] = dp[current]+scc_size[*it];
            }
        }
    }

    return  dp[to];
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    find_scc();
    
    build_scc_graph();
    cout<<move_in_scc()<<'\n';

    return  0;
}