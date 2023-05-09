#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_NUM_OF_TEAMS    (200+1)
#define MAX_NUM_OF_PLAYERS  (1000+1)
#define NUM_OF_TEAM_MEMBERS 6

#define NUM_OF_SCORED_PLAYER    4
#define EXTRA_SCORE_PLAYER      5

#define INF 0x7FFFFFFF

typedef struct{
    int num,sum,ptr,score[NUM_OF_TEAM_MEMBERS+1];
} Team_Info;

static int  N,order[MAX_NUM_OF_PLAYERS];
static int  available[MAX_NUM_OF_PLAYERS];

static Team_Info team_info[MAX_NUM_OF_TEAMS];

#define compare_extra_player(t1,t2) \
    (team_info[(t1)].score[EXTRA_SCORE_PLAYER] < \
        team_info[(t2)].score[EXTRA_SCORE_PLAYER])

#define is_better(current_team,winner,min_score) \
    (team_info[(current_team)].sum < (min_score)) || \
        (team_info[(current_team)].sum==(min_score) && \
            compare_extra_player((current_team),(winner)))

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>order[i];
        team_info[order[i]].num++;
    }

    return  0;
}

int get_available_team(void)
{
    int cnt = 0;

    for(int i=1;i<=N;i++)
    {
        int&    current_team = order[i];

        if( team_info[current_team].num == NUM_OF_TEAM_MEMBERS )
        {
            available[++cnt] = current_team;
        }
    }

    return  cnt;
}

int get_score(int num_of_available)
{
    for(int i=1;i<=num_of_available;i++)
    {
        int&    current_team = available[i];
        int&    pos = team_info[current_team].ptr;

        team_info[current_team].score[++pos] = i;

        if( pos <= NUM_OF_SCORED_PLAYER )
        {
            team_info[current_team].sum += i;
        }
    }

    return  0;
}

int get_winner(int num_of_available)
{
    int winner,min_score;

    min_score = INF;

    for(int i=1;i<=num_of_available;i++)
    {
        int&    current_team = available[i];

        if( is_better(current_team,winner,min_score) )
        {
            winner = current_team;
            min_score = team_info[current_team].sum;
        }
    }

    return  winner;
}

int init(void)
{
    int*    from = (int*)&team_info[1];
    int*    to = (int*)&team_info[MAX_NUM_OF_TEAMS];

    fill(from,to,0);
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int num_of_available;

        init();
        input();

        num_of_available = get_available_team();
        get_score(num_of_available);
        
        cout<<get_winner(num_of_available)<<'\n';
    }

    return  0;
}