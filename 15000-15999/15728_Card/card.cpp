#include    <iostream>
#include    <queue>
#include    <set>

using namespace std;

#define MAX_SIZE    (100+1)

typedef pair<int,int>   Score;

static int  N,K,shared[MAX_SIZE],team[MAX_SIZE];
static priority_queue<Score>    pq;
static set<int> checked;

#define get_score(a,b)      make_pair((a)*(b),(b))
#define is_available(s,n)   ((s).find((n))==(s).end())

int input(void)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>shared[i];
    }

    for(int i=1;i<=N;i++)
    {
        cin>>team[i];
    }

    return  0;
}

int init_score(void)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            pq.push(get_score(shared[i],team[j]));
        }
    }

    return  0;
}

int simulate(void)
{
    int ret;

    for(;checked.size()!=K;pq.pop())
    {
        checked.insert(pq.top().second);
    }

    for(;;pq.pop())
    {
        if( is_available(checked,pq.top().second) )
        {
            ret = pq.top().first;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    init_score();

    cout<<simulate()<<'\n';

    return  0;
}