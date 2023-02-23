#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (5002+1)

static int  num_of_missed[MAX_SIZE];
static bool attendance[MAX_SIZE],sleep[MAX_SIZE];

typedef pair<int,int>   Query;

int init(vector<Query>& q)
{
    int N,K,Q,M;

    cin>>N>>K>>Q>>M;

    for(int i=1;i<=K;i++)
    {
        int s;

        cin>>s;
        sleep[s] = true;
    }

    for(int i=1;i<=Q;i++)
    {
        int n;

        cin>>n;

        if( sleep[n] == true )
        {
            continue;
        }

        for(int j=n;j<=N+2;j+=n)
        {
            attendance[j] = true;
        }
    }

    for(int i=1;i<=M;i++)
    {
        int S,E;

        cin>>S>>E;
        q.push_back(make_pair(S,E));
    }

    for(int i=3;i<=N+2;i++)
    {
        num_of_missed[i] = num_of_missed[i-1]+
                    ((attendance[i]&&!sleep[i])?0:1);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Query>   q;

    init(q);

    for(int i=0;i<q.size();i++)
    {
        int&    S = q[i].first;
        int&    E = q[i].second;

        cout<<num_of_missed[E]-num_of_missed[S-1]<<'\n';
    }

    return  0;
}