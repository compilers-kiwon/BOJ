#include    <iostream>
#include    <vector>

using namespace std;

typedef pair<int,int>   Mission;

#define MAX_PLACES  3
#define MAX_ACTIONS 2

static int  N,M,p[MAX_ACTIONS][MAX_PLACES];

int get_progress(const vector<Mission>& m)
{
    int ret = 0;

    for(int i=0;i<m.size();i++)
    {
        int place = m[i].first;
        int action = m[i].second;

        ret += p[action][place]/
            ((i!=0&&place==m[i-1].first)?2:1);
    }

    return  ret;
}

int dfs(vector<Mission>& m,int& cnt)
{
    if( m.size() == N )
    {
        cnt += (get_progress(m)>=M)?1:0;
        return  0;
    }

    for(int place=0;place<MAX_PLACES;place++)
    {
        for(int action=0;action<MAX_ACTIONS;action++)
        {
            m.push_back({place,action});
            dfs(m,cnt);
            m.pop_back();
        }
    }

    return  0;
}

int input(void)
{
    cin>>N>>M;

    for(int action=0;action<MAX_ACTIONS;action++)
    {
        for(int place=0;place<MAX_PLACES;place++)
        {
            cin>>p[action][place];
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt = 0;
    vector<Mission> m;

    input();
    dfs(m,cnt);
    cout<<cnt<<'\n';

    return  0;
}