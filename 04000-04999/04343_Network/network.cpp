#include    <iostream>
#include    <queue>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (500+1)

typedef pair<int,int>       Pos;
typedef pair<int,int>       Channel;
typedef pair<int,Channel>   Radio;

int     find_parent(int me,int* p)
{
    int&    ret = p[me];

    if( ret != me )
    {
        ret = find_parent(ret,p);
    }

    return  ret;
}

void    input(int& num_of_channels,
                int& num_of_outposts,
                priority_queue<Radio>& all)
{
    Pos p[MAX_SIZE];

    cin>>num_of_channels>>num_of_outposts;

    for(int i=1;i<=num_of_outposts;i++)
    {
        cin>>p[i].first>>p[i].second;
    }

    for(int i=1;i<num_of_outposts;i++)
    {
        for(int j=i+1;j<=num_of_outposts;j++)
        {
            int dx = (p[i].first-p[j].first)*(p[i].first-p[j].first);
            int dy = (p[i].second-p[j].second)*(p[i].second-p[j].second);

            all.push(make_pair(-(dx+dy),make_pair(i,j)));
        }
    }
}

void    build_network(int num_of_outposts,
                        priority_queue<Radio>& all,
                        priority_queue<int>& selected)
{
    int parent[MAX_SIZE];

    for(int i=1;i<=num_of_outposts;i++)
    {
        parent[i] = i;
    }

    for(;selected.size()!=num_of_outposts-1;all.pop())
    {
        int dist = -all.top().first;
        int op1 = all.top().second.first;
        int op2 = all.top().second.second;

        int p1 = find_parent(op1,parent);
        int p2 = find_parent(op2,parent);

        if( p1 == p2 )
        {
            continue;
        }

        selected.push(dist);
        parent[max(p1,p2)] = min(p1,p2);
    }
}

double  get_max_power(int& num_of_channels,
                        priority_queue<int>& selected)
{
    for(int i=1;i<num_of_channels;i++)
    {
        selected.pop();
    }

    return  sqrt(selected.top());
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int S,P;

        priority_queue<Radio>   all;
        priority_queue<int>     selected;

        input(S,P,all);
        build_network(P,all,selected);

        cout.precision(2);
        cout<<fixed<<get_max_power(S,selected)<<'\n';
    }

    return  0;
}