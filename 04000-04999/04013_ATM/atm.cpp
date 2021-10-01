#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (500000+1)

typedef pair<int,int>   Path;   // first:from,second:to

int         N,M,available_money[MAX_SIZE],money_of_scc[MAX_SIZE];
int         s,num_of_restaurant,v,visited[MAX_SIZE];
int         num_of_scc,my_scc[MAX_SIZE],dp[MAX_SIZE];
bool        finished[MAX_SIZE],reachable[MAX_SIZE];
vector<int> restaurant,st;
vector<int> forward_connected[MAX_SIZE];
vector<int> backward_connected[MAX_SIZE];
vector<int> connected_scc[MAX_SIZE],scc[MAX_SIZE];

vector<Path>    path_info;

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int p1,p2;

        cin>>p1>>p2;

        path_info.push_back(make_pair(p1,p2));
        backward_connected[p2].push_back(p1);
    }

    for(int i=1;i<=N;i++)
    {
        cin>>available_money[i];
    }

    cin>>s>>num_of_restaurant;

    for(int i=1;i<=num_of_restaurant;i++)
    {
        int r;

        cin>>r;
        restaurant.push_back(r);
    }
}

void    reduce_graph(void)
{
    queue<int>      q;

    for(int i=0;i<restaurant.size();i++)
    {
        int&    r = restaurant[i];

        q.push(r);
        reachable[r] = true;
    }

    for(;!q.empty();q.pop())
    {
        int             current = q.front();
        vector<int>&    adj = backward_connected[current];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_node = adj[i];

            if( reachable[adj_node] == false )
            {
                q.push(adj_node);
                reachable[adj_node] = true;
            }
        }
    }

    for(int i=0;i<path_info.size();i++)
    {
        int&    p1 = path_info[i].first;
        int&    p2 = path_info[i].second;

        if( reachable[p1]==true && reachable[p2]==true )
        {
            forward_connected[p1].push_back(p2);
        }
    }
}

int     dfs(int current)
{
    visited[current] = ++v;
    st.push_back(current);
    
    int             parent = visited[current];
    vector<int>&    adj = forward_connected[current];

    for(int i=0;i<adj.size();i++)
    {
        int&    adj_node = adj[i];

        if( visited[adj_node] == 0 )
        {
            parent = min(parent,dfs(adj_node));
        }
        else
        {
            if( finished[adj_node] == false )
            {
                parent = min(parent,visited[adj_node]);
            }
        }
    }

    if( visited[current] == parent )
    {
        int p;

        num_of_scc++;
        
        do{
            p = st.back();
            st.pop_back();

            finished[p] = true;
            scc[num_of_scc].push_back(p);
            my_scc[p] = num_of_scc;
        }while(p!=current);
    }

    return  parent;
}

void    get_money_of_scc(void)
{
    for(int i=1;i<=num_of_scc;i++)
    {
        int&            sum = money_of_scc[i];
        vector<int>&    nodes_in_scc = scc[i];

        for(int j=0;j<nodes_in_scc.size();j++)
        {
            sum += available_money[nodes_in_scc[j]];
        }
    }
}

void    build_scc_graph(void)
{
    for(int i=1;i<=N;i++)
    {
        int             current_scc = my_scc[i];
        vector<int>&    adj = forward_connected[i];
        vector<bool>    visited_scc(num_of_scc,false);
        
        visited_scc[current_scc] = true;

        for(int j=0;j<adj.size();j++)
        {
            int&    adj_node = adj[j];
            int&    adj_scc = my_scc[adj_node];

            if( visited_scc[adj_scc] == false )
            {
                visited_scc[adj_scc] = true;
                connected_scc[current_scc].push_back(adj_scc);
            }
        }
    }
}

void    get_dp(void)
{
    int             start_scc = my_scc[s];
    queue<int>      scc_q;
    vector<bool>    in_queue(num_of_scc+1,false);

    in_queue[start_scc] = true;
    dp[start_scc] = money_of_scc[start_scc];

    for(scc_q.push(start_scc);!scc_q.empty();)
    {
        int current_scc = scc_q.front();
        int current_money = dp[current_scc];

        scc_q.pop();
        in_queue[current_scc] = false;

        vector<int>&    adj = connected_scc[current_scc];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_scc = adj[i];
            int     adj_money = current_money+money_of_scc[adj_scc];

            if( adj_money > dp[adj_scc] )
            {
                dp[adj_scc] = adj_money;

                if( in_queue[adj_scc] == false )
                {
                    scc_q.push(adj_scc);
                    in_queue[adj_scc] = true;
                }
            }
        }
    }
}

int     get_max_money(void)
{
    int ret = 0;

    for(int i=0;i<restaurant.size();i++)
    {
        ret = max(ret,dp[my_scc[restaurant[i]]]);
    }

    return  ret;
}

void    get_scc(void)
{
    for(int i=1;i<=N;i++)
    {
        if( reachable[i]==true && visited[i]==0 )
        {
            dfs(i);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    input();reduce_graph();
    get_scc();

    get_money_of_scc();
    build_scc_graph();

    get_dp();
    cout<<get_max_money()<<'\n';

    return  0;
}