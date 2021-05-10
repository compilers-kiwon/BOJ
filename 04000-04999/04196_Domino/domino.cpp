#include    <iostream>
#include    <vector>
#include    <stack>

using namespace std;

#define MAX_SIZE    (100000+1)
#define NONE        0

int         N,M,v,visited[MAX_SIZE];
int         cnt_of_scc,my_scc[MAX_SIZE];
bool        finished[MAX_SIZE],prev_scc[MAX_SIZE];
vector<int> adj_domino[MAX_SIZE];

int     dfs(int current,stack<int>& st)
{
    visited[current] = ++v;
    st.push(current);
        
    int             parent = visited[current];
    vector<int>&    adj = adj_domino[current];

    for(int i=0;i<adj.size();i++)
    {
        if( visited[adj[i]] == NONE )
        {
            parent = min(parent,dfs(adj[i],st));
        }
        else
        {
            if( finished[adj[i]] == false )
            {
                parent = min(parent,visited[adj[i]]);
            }
        }
    }
    
    if( visited[current] == parent )
    {
        int latest_domino;
        
        cnt_of_scc++;
       
        do{
            latest_domino = st.top();
            st.pop();
            
            finished[latest_domino] = true;
            my_scc[latest_domino] = cnt_of_scc;
        }while(latest_domino!=current);
    }

    return  parent;
}

int     count_head_scc(void)
{
    for(int i=1;i<=N;i++)
    {
        vector<int>&    adj = adj_domino[i];

        for(int j=0;j<adj.size();j++)
        {
            int&    current_scc = my_scc[i];
            int&    adj_scc = my_scc[adj[j]];

            if( current_scc != adj_scc )
            {
                prev_scc[adj_scc] = true;
            }
        } 
    }

    int ret = 0;

    for(int i=1;i<=cnt_of_scc;i++)
    {
        if( prev_scc[i] == false )
        {
            ret++;
        }
    }

    return  ret;
}

void    input(void)
{
    cin>>N>>M;
    cnt_of_scc = v = 0;
    
    for(int i=1;i<=N;i++)
    {
        adj_domino[i].clear();
        finished[i] = prev_scc[i] = false;
        my_scc[i] = visited[i] = NONE;
    }
    
    for(int i=1;i<=M;i++)
    {
        int x,y;

        cin>>x>>y;
        adj_domino[x].push_back(y);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        stack<int>  st;

        input();

        for(int i=1;i<=N;i++)
        {
            if( visited[i] == NONE )
            {
                dfs(i,st);
            }
        }
        
        cout<<count_head_scc()<<'\n';
    }

    return  0;
}