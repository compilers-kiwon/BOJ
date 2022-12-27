#include    <iostream>
#include    <queue>
#include    <cmath>
#include    <set>

using namespace std;

typedef pair<int,int> Pos;

#define MAX_SIZE        (15+1)
#define NUM_OF_ARCHERS  3

#define NONE    make_pair(0,0)

#define EMPTY   0
#define ENEMY   1

#define get_distance(p1,p2) (abs((p1).first-(p2).first)+abs((p1).second-(p2).second))

void    move(queue<Pos>& enemy_q,int castle_row)
{
    for(int i=1,size=enemy_q.size();i<=size;i++,enemy_q.pop())
    {
        int current_row = enemy_q.front().first;
        int current_col = enemy_q.front().second;

        if( current_row+1 == castle_row )
        {
            continue;
        }

        enemy_q.push(make_pair(current_row+1,current_col));
    }
}

void    get_target(queue<Pos>& enemy_q,Pos* archer_arr,
                        set<Pos>& result,int shooting_range)
{
    for(int i=1;i<=NUM_OF_ARCHERS;i++)
    {
        Pos archer = archer_arr[i];
        Pos target = NONE;

        for(int j=1,size=enemy_q.size();j<=size;j++,enemy_q.pop())
        {
            Pos enemy = enemy_q.front();

            if( get_distance(archer,enemy) <= shooting_range )
            {
                if( target==NONE || (get_distance(archer,enemy)<get_distance(archer,target)) ||
                    (get_distance(archer,enemy)==get_distance(archer,target)&&enemy.second<target.second) )
                {
                    target = enemy;
                }
            }

            enemy_q.push(enemy);
        }

        if( target != NONE )
        {
            result.insert(target);
        }
    }
}

void    destroy_target(queue<Pos>& enemy_q,set<Pos>& targets)
{
    for(int i=1,size=enemy_q.size();i<=size;i++,enemy_q.pop())
    {
        Pos enemy = enemy_q.front();

        if( targets.find(enemy) != targets.end() )
        {
            continue;
        }

        enemy_q.push(enemy);
    }
}

int     simulate(queue<Pos> enemy_q,Pos* archer,int max_distance)
{
    int ret = 0;
    int castle_row = archer[1].first;

    for(;!enemy_q.empty();)
    {
        set<Pos>    target;

        get_target(enemy_q,archer,target,max_distance);
        destroy_target(enemy_q,target);
        
        move(enemy_q,castle_row);
        ret += target.size();
    }

    return  ret;
}

void    input(int& row_size,int& col_size,
                int& shooting_range,queue<Pos>& enemy_q)
{
    cin>>row_size>>col_size>>shooting_range;

    for(int row=1;row<=row_size;row++)
    {
        for(int col=1;col<=col_size;col++)
        {
            int grid;

            cin>>grid;

            if( grid == ENEMY )
            {
                enemy_q.push(make_pair(row,col));
            }
        }
    }
}   

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M,D,max_num_of_destroyed_enemies;
    queue<Pos>  enemy_q;
    Pos archer[NUM_OF_ARCHERS+1];

    input(N,M,D,enemy_q);
    max_num_of_destroyed_enemies = 0;
    
    for(int col_1=1;col_1<=M;col_1++)
    {
        for(int col_2=col_1+1;col_2<=M;col_2++)
        {
            for(int col_3=col_2+1;col_3<=M;col_3++)
            {
                archer[1] = make_pair(N+1,col_1);
                archer[2] = make_pair(N+1,col_2);
                archer[3] = make_pair(N+1,col_3);

                max_num_of_destroyed_enemies = 
                    max(max_num_of_destroyed_enemies,simulate(enemy_q,archer,D));
            }
        }
    }

    cout<<max_num_of_destroyed_enemies<<'\n';

    return  0;
}