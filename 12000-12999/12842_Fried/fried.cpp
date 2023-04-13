#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)

typedef pair<int,int>   State;  // first:-time,second:-person

static int  n,s,m,t[MAX_SIZE];
static priority_queue<State> pq;

#define get_time(c,p)   (-((c)+t[(p)]))

int input(void)
{
    cin>>n>>s>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>t[i];
        pq.push(make_pair(0,-i));
    }

    return  0;
}

int simulate(void)
{
    int ret;

    for(;n!=s;n--)
    {
        int time = -pq.top().first;
        int person = -pq.top().second;

        pq.pop();
        ret = person;

        pq.push(make_pair(get_time(time,person),-person));
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}