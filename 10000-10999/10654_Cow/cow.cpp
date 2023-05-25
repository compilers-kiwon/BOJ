#include    <iostream>
#include    <vector>

using namespace std;

typedef long long int   int64;

typedef pair<int64,int64>   Cow;

int simulate(int64 minutes,vector<Cow>& c)
{
    vector<int64>   group;

    for(;!c.empty();c.pop_back())
    {
        int64   start_pos = c.back().first;
        int64   speed = c.back().second;
        int64   last_pos = start_pos+speed*minutes;

        if( group.empty() || group.back()>last_pos )
        {
            group.push_back(last_pos);
        }
    }

    return  group.size();
}

int input(vector<Cow>& c)
{
    int N,T;

    cin>>N>>T;

    for(int i=1;i<=N;i++)
    {
        int64   p,s;

        cin>>p>>s;
        c.push_back({p,s});
    }

    return  T;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         T;
    vector<Cow> state;

    T = input(state);
    cout<<simulate(T,state)<<'\n';

    return  0;
}