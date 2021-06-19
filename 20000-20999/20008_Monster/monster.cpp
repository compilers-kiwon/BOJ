#include    <iostream>

using namespace std;

#define MAX_SKILL   (5+1)
#define INF         0x7FFFFFFF

typedef struct{int available,waiting_time,damage;}   Skill; 

int     N,H,min_time;
Skill   s[MAX_SKILL];

void    input(void)
{
    cin>>N>>H;

    for(int i=1;i<=N;i++)
    {
        int C,D;
        
        cin>>C>>D;

        s[i].available = 0;
        s[i].waiting_time = C;
        s[i].damage = D;
    }
}

void    simulate(int current_time,int current_damage)
{
    if( current_damage >= H )
    {
        min_time = min(min_time,current_time);
        return;
    }

    bool    attack = false;

    for(int i=1;i<=N;i++)
    {
        if( s[i].available > current_time )
        {
            continue;
        }

        int prev_time = s[i].available;

        s[i].available = current_time+s[i].waiting_time;

        attack = true;
        simulate(current_time+1,current_damage+s[i].damage);

        s[i].available = prev_time;
    }

    if( attack == false )
    {
        simulate(current_time+1,current_damage);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    min_time = INF;

    simulate(0,0);
    cout<<min_time<<'\n';

    return  0;
}