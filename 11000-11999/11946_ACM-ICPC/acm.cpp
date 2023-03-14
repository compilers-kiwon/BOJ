#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

#define MAX_NUM_OF_TEAMS    (100+1)
#define MAX_NUM_OF_PROBLEMS (15+1)

typedef struct{
    int     idx;
    int     num_of_solved_problems;
    int     total_time_to_solve;
    int     num_of_wrong_solutions[MAX_NUM_OF_PROBLEMS];
    bool    solved[MAX_NUM_OF_PROBLEMS];
} Team;

static int  n,m,q;
static Team t[MAX_NUM_OF_TEAMS];

#define already_solved(team,p_idx) ((team).solved[(p_idx)])

#define get_penalty(team,p_idx) \
            ((team).num_of_wrong_solutions[(p_idx)]*20)

int init(void)
{
    cin>>n>>m>>q;

    for(int i=1;i<=n;i++)
    {
        t[i].idx = i;
    }

    return  0;
}

int simulate(void)
{
    int     time,team_no,problem_no;
    string  result;

    cin>>time>>team_no>>problem_no>>result;

    Team&   current = t[team_no];

    if( already_solved(current,problem_no) )
    {
        return  0;
    }

    if( result == "AC" )
    {
        current.num_of_solved_problems++;
        current.total_time_to_solve += 
                time+get_penalty(current,problem_no);
        current.solved[problem_no] = true;
    }
    else
    {
        current.num_of_wrong_solutions[problem_no]++;
    }

    return  0;
}

bool    is_better(const Team& t1,const Team& t2)
{
    if( t1.num_of_solved_problems > t2.num_of_solved_problems )
    {
        return  true;
    }

    if( t1.num_of_solved_problems < t2.num_of_solved_problems )
    {
        return  false;
    }
    
    if( t1.total_time_to_solve < t2.total_time_to_solve )
    {
        return  true;
    }

    if( t1.total_time_to_solve > t2.total_time_to_solve )
    {
        return  false;
    }

    return  (t1.idx<t2.idx);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    
    for(int i=1;i<=q;i++)
    {
        simulate();
    }

    sort(&t[1],&t[n+1],is_better);

    for(int i=1;i<=n;i++)
    {
        cout<<t[i].idx<<' '
            <<t[i].num_of_solved_problems<<' '
            <<t[i].total_time_to_solve<<'\n';
    }

    return  0;
}