#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100000+1)
#define TBD         -1

int         N,R,Q,num_of_nodes[MAX_SIZE];
bool        visited[MAX_SIZE];
vector<int> connected[MAX_SIZE];
vector<int> query;

void    input(void)
{
    cin>>N>>R>>Q;

    for(int i=1;i<N;i++)
    {
        int U,V;

        cin>>U>>V;

        connected[U].push_back(V);
        connected[V].push_back(U);
    }

    for(int i=1;i<=Q;i++)
    {
        int U;

        cin>>U;
        query.push_back(U);
    }
}

int     get_num_of_nodes_in_subtree(int r)
{
    num_of_nodes[r] = 1;
    visited[r] = true;

    vector<int>&    adj = connected[r];

    for(int i=0;i<adj.size();i++)
    {
        int&    adj_node = adj[i];

        if( visited[adj_node] == false )
        {
            num_of_nodes[r] += get_num_of_nodes_in_subtree(adj_node);
        }
    }

    return  num_of_nodes[r];
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_num_of_nodes_in_subtree(R);

    for(int i=0;i<query.size();i++)
    {
        cout<<num_of_nodes[query[i]]<<'\n';
    }

    return  0;
}