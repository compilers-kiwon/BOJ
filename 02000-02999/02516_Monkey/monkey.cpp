#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)
#define MAX_CAGE    2
#define MAX_ALLOWED 1

#define get_adj_cage(c) (((c)+1)%MAX_CAGE)

static int  N,cage[MAX_SIZE];
static vector<int>  excluded[MAX_SIZE];
static queue<int>   q;

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int M;

        cin>>M;
        q.push(i);

        for(int j=1;j<=M;j++)
        {
            int e;

            cin>>e;
            excluded[i].push_back(e);
        }
    }

    return  0;
}

int get_num_of_excluded_in_same_cage(int m,int c)
{
    int ret = 0;

    for(int i=0;i<excluded[m].size();i++)
    {
        if( cage[excluded[m][i]] == c )
        {
            ret++;
        }
    }

    return  ret;
}

int will_be_checked(const vector<int>& m)
{
    for(int i=0;i<m.size();i++)
    {
        q.push(m[i]);
    }

    return  0;
}

int simulate(void)
{
    for(;!q.empty();q.pop())
    {
        int current_monkey = q.front();
        int current_cage = cage[current_monkey];
        
        int num_of_excluded_in_same_cage =
                get_num_of_excluded_in_same_cage(current_monkey,current_cage);

        if( num_of_excluded_in_same_cage > MAX_ALLOWED )
        {
            cage[current_monkey] = get_adj_cage(current_cage);
            will_be_checked(excluded[current_monkey]);
        } 
    }

    return  0;
}

int print(void)
{
    vector<int> g[MAX_CAGE];

    for(int i=1;i<=N;i++)
    {
        g[cage[i]].push_back(i);
    }

    for(int c=0;c<MAX_CAGE;c++)
    {
        cout<<g[c].size();

        for(int i=0;i<g[c].size();i++)
        {
            cout<<' '<<g[c][i];
        }

        cout<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();

    return  0;
}