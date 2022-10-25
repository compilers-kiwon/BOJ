#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000000+1)
#define NONE        -1

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int     N,S,D,F,B,K,visited[MAX_SIZE];
bool    police_station[MAX_SIZE];

void    input(void)
{
    cin>>N>>S>>D>>F>>B>>K;

    for(int i=1;i<=K;i++)
    {
        int l;

        cin>>l;
        police_station[l] = true;
    }
}

void    move_player(int p,int offset,queue<int>& q)
{
    int pos = p+offset;

    if( !IN_RANGE(1,pos,N) || visited[pos]!=NONE )
    {
        return;
    }

    q.push(pos);
    visited[pos] = visited[p]+1;
}

int     play(void)
{
    int         ret;
    queue<int>  q;

    fill(&visited[1],&visited[N+1],NONE);

    q.push(S);
    visited[S] = 0;

    for(ret=NONE;!q.empty();q.pop())
    {
        int current_pos = q.front();
        int current_step = visited[current_pos];
        
        if( current_pos == D )
        {
            ret = current_step;
            break;
        }

        if( police_station[current_pos] == true )
        {
            continue;
        }

        move_player(current_pos,-B,q);
        move_player(current_pos,F,q);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_operation;

    input();
    num_of_operation = play();

    if( num_of_operation == NONE )
    {
        cout<<"BUG FOUND\n";
    }
    else
    {
        cout<<num_of_operation<<'\n';
    }

    return  0;
}