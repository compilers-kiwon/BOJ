#include    <iostream>
#include    <stack>
#include    <queue>

using namespace std;

#define MAX_SIZE    8
#define MAX_DIR     4
#define MAX_STEP    4

typedef pair<char,int>  Pos;    // first:col,second:row
typedef pair<int,Pos>   State;  // first:step,second:Pos

const struct{int d_col,d_row;}
    adj[MAX_DIR] = {{-1,-1},{-1,1},{1,-1},{1,1}};

static Pos  visited[MAX_SIZE+1][0x100];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define IMPOSSIBLE   -1

#define row second
#define col first

int init(void)
{
    for(int row=1;row<=MAX_SIZE;row++)
    {
        for(int col='A';col<='H';col++)
        {
            visited[row][col] = {0,0};
        }
    }

    return  0;
}

int input(Pos& X,Pos& Y)
{
    cin>>X.first>>X.second>>Y.first>>Y.second;
    return  0;
}

int simulate(const Pos& X,const Pos& Y)
{
    queue<State>    q;
    const Pos       unvisited = {0,0};

    q.push({MAX_STEP,X});
    visited[X.row][X.col] = X;

    for(;!q.empty();q.pop())
    {
        int current_step = q.front().first;

        if( q.front().second == Y )
        {
            return  MAX_STEP-current_step;
        }

        if( current_step == 0 )
        {
            continue;
        }
        
        int current_row = q.front().second.row;
        int current_col = q.front().second.col;

        for(int d=0;d<MAX_DIR;d++)
        {
            for(int offset=1;;offset++)
            {
                int adj_row = current_row+adj[d].d_row*offset;
                int adj_col = current_col+adj[d].d_col*offset;

                if( !IN_RANGE(1,adj_row,MAX_SIZE) || !IN_RANGE('A',adj_col,'H') )
                {
                    break;
                }

                if( visited[adj_row][adj_col] != unvisited )
                {
                    continue;
                }

                q.push({current_step-1,{adj_col,adj_row}});
                visited[adj_row][adj_col] = {current_col,current_row};
            }
        }
    }

    return  IMPOSSIBLE;
}

int print(const Pos& s,int len)
{
    stack<Pos>  st;

    cout<<len;

    for(Pos current=s;st.size()!=(len+1);)
    {
        st.push(current);
        current = visited[current.row][current.col];
    }

    for(;!st.empty();st.pop())
    {
        cout<<' '<<st.top().col<<' '<<st.top().row;
    }

    cout<<'\n';

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
        Pos X,Y;
        int num_of_steps;

        input(X,Y);init();
        num_of_steps = simulate(X,Y);

        if( num_of_steps == IMPOSSIBLE )
        {
            cout<<"Impossible\n";
        }
        else
        {
            print(Y,num_of_steps);
        }
    }

    return  0;
}