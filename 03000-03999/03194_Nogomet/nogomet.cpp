#include    <iostream>
#include    <algorithm>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_NUM_OF_TEAMS    (100+1)
#define MAX_NUM_OF_MATCHES  (1000+1)

typedef struct{int A,B,C,D;}    Match;
typedef struct{int p,d,g,w;}    Team;
typedef pair<int,int>           State;  // first:point,second:team_idx

int     N,K;
Team    team[MAX_NUM_OF_TEAMS];
Match   match[MAX_NUM_OF_MATCHES];

vector<int> final_rank;

void    play_match(vector<int>& teams);

void    input(void)
{
    scanf("%d %d",&N,&K);

    for(int i=1;i<=K;i++)
    {
        int&    A = match[i].A;
        int&    B = match[i].B;
        int&    C = match[i].C;
        int&    D = match[i].D;

        scanf("%d %d %d:%d",&A,&B,&C,&D);

        team[A].d += C-D;
        team[B].d += D-C;

        team[A].g += C;
        team[B].g += D;

        if( C == D )
        {
            team[A].p++;
            team[B].p++;
        }
        else
        {
            if( C > D )
            {
                team[A].p += 3;
                team[A].w++;
            }
            else
            {
                team[B].p += 3;
                team[B].w++;
            }
        }
    }
}

bool    is_better(const int& t1,const int& t2)
{
    if( team[t1].d != team[t2].d )
    {
        return  (team[t1].d>team[t2].d);
    }

    if( team[t1].g != team[t2].g )
    {
        return  (team[t1].g>team[t2].g);
    }

    if( team[t1].w != team[t2].w )
    {
        return  (team[t1].w>team[t2].w);
    }

    return  (t1<t2);
}

void    place_rank(priority_queue<State>& rank,int size)
{
    for(;!rank.empty();)
    {
        vector<int> new_league;
        
        int p = rank.top().first;
        int t = rank.top().second;

        new_league.push_back(t);
        rank.pop();

        for(;;)
        {
            if( rank.empty() || p!=rank.top().first )
            {
                break;
            }

            new_league.push_back(rank.top().second);
            rank.pop();
        }

        if( new_league.size() != 1 )
        {
            if( new_league.size() == size )
            {
                sort(new_league.begin(),new_league.end(),is_better);

                for(int i=0;i<new_league.size();i++)
                {
                    final_rank.push_back(new_league[i]);
                }
            }
            else
            {
                play_match(new_league);
            }
        }
        else
        {
            final_rank.push_back(new_league.front());
        }
    }
}

void    play_match(vector<int>& teams)
{
    vector<bool>    league(N+1,false);
    vector<int>     point(N+1,0);

    for(int i=0;i<teams.size();i++)
    {
        league[teams[i]] = true;
    }

    for(int i=1;i<=K;i++)
    {
        int&    A = match[i].A;
        int&    B = match[i].B;
        int&    C = match[i].C;
        int&    D = match[i].D;

        if( league[A]==false || league[B]==false )
        {
            continue;
        }

        if( C == D )
        {
            point[A]++;
            point[B]++;
        }
        else
        {
            if( C > D )
            {
                point[A] += 3;
            }
            else
            {
                point[B] += 3;
            }
        }
    }

    priority_queue<State>   rank;

    for(int i=0;i<teams.size();i++)
    {
        int&    t = teams[i];

        rank.push(make_pair(point[t],t));
    }

    place_rank(rank,teams.size());
}

void    get_rank(vector<int>& teams)
{
    priority_queue<State>   rank;

    for(int i=0;i<teams.size();i++)
    {
        int&    t = teams[i];

        rank.push(make_pair(team[t].p,t));
    }

    place_rank(rank,teams.size());
}

int     main(void)
{
    vector<int> t;

    input();

    for(int i=1;i<=N;i++)
    {
        t.push_back(i);
    }

    get_rank(t);
    
    for(int i=0;i<final_rank.size();i++)
    {
        cout<<final_rank[i]<<((i==final_rank.size()-1)?'\n':' ');
    }

    return  0;
}