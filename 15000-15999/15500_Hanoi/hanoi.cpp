#include    <iostream>
#include    <vector>

using namespace std;

#define NUM_OF_TOWERS   3
#define MAX_SIZE        (123+1)

typedef pair<int,int>   Move;

static int  N,where_i_am[MAX_SIZE];
static vector<int>  tower[NUM_OF_TOWERS+1];
static vector<Move> m;

#define MOVE(from,to) {\
    m.push_back(make_pair((from),(to)));\
    where_i_am[tower[(from)].back()] = (to);\
    tower[(to)].push_back(tower[(from)].back());\
    tower[(from)].pop_back();\
}

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int a;

        cin>>a;

        tower[1].push_back(a);
        where_i_am[a] = 1;
    }

    return  0;
}

int simulate(void)
{
    for(int a=N;tower[3].size()!=N;a--)
    {
        int from = where_i_am[a];
        int to = (from==1)?2:1;

        for(;tower[from].back()!=a;)
        {
            MOVE(from,to);
        }

        MOVE(from,3);
    }

    return  0;
}

int print(void)
{
    cout<<m.size()<<'\n';

    for(int i=0;i<m.size();i++)
    {
        cout<<m[i].first<<' '<<m[i].second<<'\n';
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