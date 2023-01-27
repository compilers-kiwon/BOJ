#include    <iostream>
#include    <vector>
#include    <map>
#include    <algorithm>

using namespace std;

typedef pair<int,int>   Pos;

#define virtual_entry_point()   make_pair(-1,0)

void    input(map<int,vector<int>>& m)
{
    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x,y;

        cin>>x>>y;
        m[x].push_back(y);
    }

    map<int,vector<int>>::iterator  it;

    for(it=m.begin();it!=m.end();it++)
    {
        vector<int>&    y_pos = it->second;

        sort(y_pos.begin(),y_pos.end());
    }
}

void    simulate(vector<Pos>& cafe,
                    map<int,vector<int>>& m)
{
    cafe.push_back(virtual_entry_point());

    map<int,vector<int>>::iterator  it;

    for(it=m.begin();it!=m.end();it++)
    {
        int prev_y = cafe.back().second;
        vector<int>& y_pos = it->second;
        int from,to,offset;

        if( prev_y == y_pos.front() )
        {
            from=0;to=y_pos.size();offset=1;
        }
        else
        {
            from=y_pos.size()-1;to=-1;offset=-1;
        }

        for(int i=from;i!=to;i+=offset)
        {
            cafe.push_back(make_pair(it->first,y_pos[i]));
        }
    }
}

void    print(vector<Pos>& cafe)
{
    int m;

    cin>>m;

    for(int i=1;i<=m;i++)
    {
        int p;

        cin>>p;
        cout<<cafe[p].first<<' '<<cafe[p].second<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        vector<Pos> cafe;
        map<int,vector<int>> m;

        input(m);
        simulate(cafe,m);
        print(cafe);
    }

    return  0;
}