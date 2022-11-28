#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100000+1)

#define CLEAN   1
#define DIRTY   0

int         N,M,Q,state[MAX_SIZE],query[MAX_SIZE],water[MAX_SIZE];
bool        visited[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    flow(int current,vector<int>& c)
{
    if( visited[current] == true )
    {
        return;
    }

    c.push_back(current);
    visited[current] = true;

    for(int i=0;i<connected[current].size();i++)
    {
        flow(connected[current][i],c);
    }
}

void    get_num_of_water_state(int& clean,int &dirty,vector<int>& c)
{
    clean = dirty = 0;

    for(int i=0;i<c.size();i++)
    {
        (state[c[i]]==CLEAN)?clean++:dirty++;
    }
}

void    write_water_state(int s,vector<int>& c)
{
    for(int i=0;i<c.size();i++)
    {
        water[c[i]] = s;
    }
}

void    set_water(vector<int>& c)
{
    int num_of_clean,num_of_dirty;

    get_num_of_water_state(num_of_clean,num_of_dirty,c);
    write_water_state(((num_of_clean>num_of_dirty)?CLEAN:DIRTY),c);
}

void    input(void)
{
    cin>>N>>M>>Q;

    for(int i=1;i<=N;i++)
    {
        cin>>state[i];
    }

    for(int i=1;i<=M;i++)
    {
        int u,v;

        cin>>u>>v;

        connected[u].push_back(v);
        connected[v].push_back(u);
    }

    for(int i=1;i<=Q;i++)
    {
        cin>>query[i];
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=1;i<=N;i++)
    {
        if( visited[i] == false )
        {
            vector<int> adj;

            flow(i,adj);
            set_water(adj);
        }
    }

    for(int i=1;i<=Q;i++)
    {
        cout<<water[query[i]]<<'\n';
    }

    return  0;
}