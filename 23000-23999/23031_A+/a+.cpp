#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MAX_SIZE    (15+1)
#define START_POS   {1,1}

typedef pair<int,int>   Pos;    // first:row, second:col
typedef pair<int,Pos>   State;  // first:dir, second:Pos

#define UP      0
#define RIGHT   1
#define DOWN    2
#define LEFT    3
#define MAX_DIR 4

#define turn_back(d)    (((d)+2)%MAX_DIR)
#define trun_left(d)    (((d)+(MAX_DIR-1))%MAX_DIR)
#define turn_right(d)   (((d)+1)%MAX_DIR)

const struct{int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

static int      N;
static string   A;
static char     grid[MAX_SIZE][MAX_SIZE+1];
static State    ari;
static bool     is_light[MAX_SIZE+1][MAX_SIZE+1];

static vector<State>    z;

#define FAINT   0
#define SAFE    1

#define TRUE    1
#define FALSE   0

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define meet_zombi(a,z) \
        ((a).second==(z).second&&!is_light[(a).second.first][(a).second.second])

int light_on(int row,int col)
{
    for(int d_row=-1;d_row<=1;d_row++)
    {
        for(int d_col=-1;d_col<=1;d_col++)
        {
            int adj_row = row+d_row;
            int adj_col = col+d_col;

            is_light[adj_row][adj_col] = true;
        }
    }

    return  0;
}

int input(void)
{
    cin>>N>>A;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=N;col++)
        {
            if( grid[row][col] == 'Z' )
            {
                z.push_back({DOWN,{row,col}});
            }
        }
    }

    ari = {DOWN,START_POS};
    return  0;
}

int go_forward(State& s,bool stop_flag)
{
    int&    d = s.first;
    int&    row = s.second.first;
    int&    col = s.second.second;

    int adj_row = row+adj[d].d_row;
    int adj_col = col+adj[d].d_col;

    if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
    {
        if(!stop_flag) d=turn_back(d);
        return  0;
    }

    row = adj_row;
    col = adj_col;

    if( stop_flag==true && grid[row][col]=='S' )
    {
        light_on(row,col);
    }

    return  0;
}

int move(State& s,char action,bool stop_flag)
{
    switch(action)
    {
        case 'F':
            go_forward(s,stop_flag);
            break;
        case 'L':
            s.first = trun_left(s.first);
            break;
        case 'R':
            s.first = turn_right(s.first);
            break;
        default:
            /*do nothing*/;
            break;
    }

    return  0;
}

int simulate(void)
{
    for(int i=0;i<A.length();i++)
    {
        move(ari,A[i],true);
        
        for(int j=0;j<z.size();j++)
        {
            if(meet_zombi(ari,z[j])) return FAINT;
            move(z[j],'F',false);
            if(meet_zombi(ari,z[j])) return FAINT;
        }
    }

    return  SAFE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<(simulate()==FAINT?"Aaaaaah!":"Phew...")<<'\n';

    return  0;
}