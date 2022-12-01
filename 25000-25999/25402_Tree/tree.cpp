#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (250000+1)
#define BIG_SIZE    125

typedef long long int   int64;

int         N,Q,parent[MAX_SIZE];
int64       tree_size[MAX_SIZE];
bool        available[MAX_SIZE];
vector<int> connected[MAX_SIZE];

#define is_connected(n1,n2) (binary_search(connected[(n1)].begin(),\
                                            connected[(n1)].end(),(n2)))

int     find_parent(int me)
{
    int&    ret = parent[me];

    if( ret != me )
    {
        ret = find_parent(ret);
    }

    return  ret;
}

void    read_query(vector<int>& set)
{
    int K;

    cin>>K;

    for(int i=1;i<=K;i++)
    {
        int s;

        cin>>s;
        set.push_back(s);

        parent[s] = s;
        tree_size[s] = 1;
    }

    sort(set.begin(),set.end());
}

void    read_tree(void)
{
    cin>>N;

    for(int i=1;i<N;i++)
    {
        int u,v;

        cin>>u>>v;
        connected[min(u,v)].push_back(max(u,v));
    }

    for(int i=1;i<=N;i++)
    {
        sort(connected[i].begin(),connected[i].end());
    }
}

void    build_edge(int n1,int n2)
{
    int p1 = find_parent(n1);
    int p2 = find_parent(n2);

    if( p1 == p2 )
    {
        return;
    }

    parent[max(p1,p2)] = min(p1,p2);
    tree_size[min(p1,p2)] += tree_size[max(p1,p2)];
}

void    mark_available(vector<int>& set)
{
    for(int i=0;i<set.size();i++)
    {
        available[set[i]] = true;
    }
}

void    unmark_available(vector<int>& set)
{
    for(int i=0;i<set.size();i++)
    {
        available[set[i]] = false;
    }
}

int64   get_sum_of_each_tree_strength(vector<int>& set)
{
    int64   ret = 0;

    for(int i=0;i<set.size();i++)
    {
        int&    n = set[i];

        if( find_parent(n) == n )
        {
            ret += tree_size[n]*(tree_size[n]-1)/2;
        }
    }

    return  ret;
}

void    build_trees(vector<int>& set)
{
    if( set.size() > BIG_SIZE )
    {
        for(int i=0;i<set.size();i++)
        {
            int&            n1 = set[i];
            vector<int>&    adj = connected[n1];

            for(int j=0;j<adj.size();j++)
            {
                int&    n2 = adj[j];

                if( available[n2] == true )
                {
                    build_edge(n1,n2);
                } 
            }
        }
    }
    else
    {
        for(int i=0;i<set.size();i++)
        {
            for(int j=i+1;j<set.size();j++)
            {
                int&    n1 = set[i];
                int&    n2 = set[j];

                if( is_connected(n1,n2) == true )
                {
                    build_edge(n1,n2);
                }
            }
        }
    }
}

int64   get_strength(vector<int>& set)
{
    int64   ret = 0;

    mark_available(set);
    build_trees(set);
    ret = get_sum_of_each_tree_strength(set);
    unmark_available(set);

    return  ret;
}

void    process_query(void)
{
    cin>>Q;
    
    for(int i=1;i<=Q;i++)
    {
        vector<int>    S;

        read_query(S);
        cout<<get_strength(S)<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_tree();
    process_query();
    
    return  0;
}