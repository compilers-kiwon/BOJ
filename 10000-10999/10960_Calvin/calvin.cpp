#include    <iostream>
#include    <vector>

using namespace std;

typedef vector<int> State;
typedef vector<int> Player;

int n,m;

#define LIKE    0
#define DISLIKE 1

void    input(vector<State>& d)
{
    cin>>n>>m;
    d.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        d[i].resize(n+1,LIKE);
    }

    for(int i=1;i<=m;i++)
    {
        int a,b;

        cin>>a>>b;
        d[a][b] = d[b][a] = DISLIKE;
    }
}

void    build_team(const vector<State>& d,vector<Player>& team)
{
    for(int p=1;p<=n;p++)
    {
        int     t;
        bool    found = false;

        for(int i=0;i<team.size()&&found!=true;i++)
        {
            bool    like_all = true;
            Player& current_team = team[i];

            for(int j=0;j<current_team.size();j++)
            {
                int&    prev_player = current_team[j];

                if( d[p][prev_player] == DISLIKE )
                {
                    like_all = false;
                    break;
                }
            }

            if( like_all == true )
            {
                found = true;
                t = i;
            }
        }

        if( found == true )
        {
            team[t].push_back(p);
        }
        else
        {
            Player  new_team;

            new_team.push_back(p);
            team.push_back(new_team);
        }
    }
}

void    print(const vector<Player>& team)
{
    cout<<team.size()<<'\n';

    for(int i=0;i<team.size();i++)
    {
        for(int j=0;j<team[i].size();j++)
        {
            cout<<team[i][j]<<' ';
        }
        cout<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<State>   s;
    vector<Player>  t;

    input(s);
    build_team(s,t);

    print(t);
    return  0;
}