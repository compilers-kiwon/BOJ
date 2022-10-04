#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (4000+1)
#define INF         0x7FFFFFFF

#define BOOSTER_ON          0
#define BOOSTER_OFF         1
#define MAX_BOOSTER_STATE   2

#define GET_NEXT_BOOSTER_STATE(b)   (((b)+1)%MAX_BOOSTER_STATE)

typedef pair<int,int>   Path;   // first:adj_pos,second:distance
typedef pair<int,int>   State;  // first:booster_state,second:current_pos
typedef pair<int,State> Wolf;   // first:-total_distance,second:State
typedef pair<int,int>   Fox;    // first:-total_distance,second:current_pos

int             N,M;
int             dp_fox[MAX_SIZE];
int             dp_wolf[MAX_BOOSTER_STATE][MAX_SIZE];
vector<Path>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int a,b,d;

        cin>>a>>b>>d;
        d *= 2;

        connected[a].push_back(make_pair(b,d));
        connected[b].push_back(make_pair(a,d));
    }
}

void    fox_run(void)
{
    priority_queue<Fox> pq;

    dp_fox[1] = 0;
    pq.push(make_pair(0,1));

    for(;!pq.empty();)
    {
        int current_dist = -pq.top().first;
        int current_pos = pq.top().second;

        pq.pop();

        if( current_dist > dp_fox[current_pos] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_pos = adj[i].first;
            int adj_dist = current_dist+adj[i].second;

            if( adj_dist < dp_fox[adj_pos] )
            {
                dp_fox[adj_pos] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_pos));
            }
        }
    }
}

void    wolf_run(void)
{
    priority_queue<Wolf>    pq;

    dp_wolf[BOOSTER_OFF][1] = 0;
    pq.push(make_pair(0,make_pair(BOOSTER_OFF,1)));

    for(;!pq.empty();)
    {
        int current_dist = -pq.top().first;
        int current_booster = pq.top().second.first;
        int current_pos = pq.top().second.second;

        pq.pop();

        if( current_dist > dp_wolf[current_booster][current_pos] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int adj_booster = GET_NEXT_BOOSTER_STATE(current_booster);
            int adj_pos = adj[i].first;
            int adj_dist = current_dist+
                            ((adj_booster==BOOSTER_ON)?adj[i].second/2:adj[i].second*2);

            if( adj_dist < dp_wolf[adj_booster][adj_pos] )
            {
                dp_wolf[adj_booster][adj_pos] = adj_dist;
                pq.push(make_pair(-adj_dist,make_pair(adj_booster,adj_pos)));
            }
        }
    }
}

int     get_cnt_of_pos_for_fox(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        if( dp_fox[i]<dp_wolf[BOOSTER_ON][i]
                && dp_fox[i]<dp_wolf[BOOSTER_OFF][i] )
        {
            ret++;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    fill(&dp_fox[1],&dp_fox[N+1],INF);
    fill(&dp_wolf[BOOSTER_ON][1],&dp_wolf[BOOSTER_ON][N+1],INF);
    fill(&dp_wolf[BOOSTER_OFF][1],&dp_wolf[BOOSTER_OFF][N+1],INF);

    fox_run();
    wolf_run();

    cout<<get_cnt_of_pos_for_fox()<<'\n';

    return  0;
}