#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    50
#define MAX_DIR     8

const struct{int d_row,d_col;}  adj[MAX_DIR] =
    {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

typedef struct{int r,c,m,d,s;}  Fireball;

int                 N,M,K;
queue<Fireball>     fq;
vector<Fireball>    grid[MAX_SIZE][MAX_SIZE];

const int   new_fireball_dir[2][4] = {{0,2,4,6},{1,3,5,7}};

void    input(void)
{
    cin>>N>>M>>K;

    for(int i=1;i<=M;i++)
    {
        Fireball    f;

        cin>>f.r>>f.c>>f.m>>f.s>>f.d;
        
        --f.r;--f.c;
        fq.push(f);
    }
}

void    get_next_fireball(Fireball& current,Fireball& next)
{
    int d_row,d_col;

    d_row = (current.s%N)*adj[current.d].d_row;
    d_col = (current.s%N)*adj[current.d].d_col;
    
    if( d_row >= 0 )
    {
        next.r = (current.r+d_row)%N;
    }
    else
    {
        next.r = (current.r+(d_row+N))%N;
    }
    
    if( d_col >= 0 )
    {
        next.c = (current.c+d_col)%N;
    }
    else
    {
        next.c = (current.c+(d_col+N))%N;
    }
    
    next.d = current.d;
    next.m = current.m;
    next.s = current.s;
}

void    place_fireball_at_grid(void)
{
    for(;!fq.empty();fq.pop())
    {
        Fireball    current,next;

        current = fq.front();
        get_next_fireball(current,next);

        grid[next.r][next.c].push_back(next);
    }
}

void    scan_fireballs(int& sum_of_weight,int& sum_of_speed,int& num_of_odd,
                                    int& num_of_even,vector<Fireball>& current)
{
    for(int j=0;j<current.size();j++)
    {
        sum_of_weight += current[j].m;
        sum_of_speed += current[j].s;

        if( current[j].d%2 == 0 )
        {
            num_of_even++;
        }
        else
        {
            num_of_odd++;
        }
    }
}

void    handle_collision(vector<Fireball>& current,int row,int col)
{
    int sum_of_weight,sum_of_speed,num_of_odd,num_of_even,num_of_fireballs;

    sum_of_weight = sum_of_speed = num_of_odd = num_of_even = 0;
    num_of_fireballs = current.size();

    scan_fireballs(sum_of_weight,sum_of_speed,num_of_odd,num_of_even,current);
    current.clear();

    if( sum_of_weight/5 == 0 )
    {
        return;
    }

    int ptr_of_new_dir = ((num_of_even!=0&&num_of_odd!=0)?1:0);

    for(int j=0;j<4;j++)
    {
        Fireball    new_fireball;

        new_fireball.r = row;
        new_fireball.c = col;
        new_fireball.m = sum_of_weight/5;
        new_fireball.d = new_fireball_dir[ptr_of_new_dir][j];
        new_fireball.s = sum_of_speed/num_of_fireballs;

        fq.push(new_fireball);
    }
}

void    move_fireball_to_fq_from_grid(void)
{
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            vector<Fireball>&   current = grid[row][col];

            switch(current.size())
            {
                case    0:
                    // do nothing
                    break;
                case    1:
                    fq.push(current.front());
                    current.pop_back();
                    break;
                default:
                    handle_collision(current,row,col);
                    break;
            }
        }
    }
}

void    simulate(void)
{
    for(int i=1;i<=K&&!fq.empty();i++)
    {
        place_fireball_at_grid();        
        move_fireball_to_fq_from_grid();
    }
}

int     get_sum_of_weight_in_grid(void)
{
    int ret = 0;

    for(;!fq.empty();fq.pop())
    {
        ret += fq.front().m;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    cout<<get_sum_of_weight_in_grid()<<'\n';

    return  0;
}