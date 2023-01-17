#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)
#define INF         0x7FFFFFFF
#define SCALER      (1000)

#define update_team(t,s,a)  {(t).S+=(s);(t).A+=(a);}

typedef struct{int S,A;}    Team;
typedef long long int       int64;

void    input(int& num_of_teams,
                int& num_of_games,Team* t)
{
    cin>>num_of_teams>>num_of_games;
    
    for(int i=1;i<=num_of_teams;i++)
    {
        t[i].S = t[i].A = 0;
    }

    for(int i=1;i<=num_of_games;i++)
    {
        int a,b,p,q;

        cin>>a>>b>>p>>q;

        update_team(t[a],p,q);
        update_team(t[b],q,p);
    }
}

int     calculate_expectation(const Team& t)
{
    int W;

    if( (W=t.S*t.S+t.A*t.A) == 0 )
    {
        return  0;
    }

    W = (int64)SCALER*(int64)(t.S*t.S)/(int64)W;

    return  W;
}

pair<int,int>   get_expectations(Team* t,int num_of_teams)
{
    int min_expectation,max_expectation;

    max_expectation = 0;
    min_expectation = INF;

    for(int i=1;i<=num_of_teams;i++)
    {
        int e = calculate_expectation(t[i]);

        max_expectation = max(max_expectation,e);
        min_expectation = min(min_expectation,e);
    }

    return  make_pair(max_expectation,min_expectation);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int             n,m;
        Team            t[MAX_SIZE];
        pair<int,int>   expectations;

        input(n,m,t);
        expectations = get_expectations(t,n);

        cout<<expectations.first<<'\n'
                <<expectations.second<<'\n';
    }

    return  0;
}