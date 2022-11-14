#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE        (3*500+1)
#define MAX_ORDER_LEN   3
#define GET_ORDER(n)    ((n)%MAX_ORDER_LEN)

typedef struct{int n,l,r;}  State;

int     N;
char    order[MAX_SIZE+1];
bool    visited[MAX_SIZE][MAX_SIZE];

void    input(void)
{
    cin>>N>>&order[1];
}

int     simulate(void)
{
    queue<State>    q;
    State   s = {0,1,N*MAX_ORDER_LEN};
    int     ret = 0;

    const char  m[MAX_ORDER_LEN] = {'B','L','D'};
    
    for(q.push(s),visited[1][N]==true;!q.empty();q.pop())
    {
        int current_num_of_medicines = q.front().n;
        int current_left_idx = q.front().l;
        int current_right_idx = q.front().r;

        if( current_left_idx > current_right_idx )
        {
            continue;
        }

        char    expected = m[GET_ORDER(current_num_of_medicines)];
        char    head = order[current_left_idx];
        char    tail = order[current_right_idx];
        
        if( head==expected &&
                !visited[current_left_idx+1][current_right_idx] )
        {
            State   tmp = {current_num_of_medicines+1,
                            current_left_idx+1,current_right_idx};
            
            q.push(tmp);
            visited[current_left_idx+1][current_right_idx] = true;

            ret = max(ret,current_num_of_medicines+1);
        }

        if( tail==expected &&
                !visited[current_left_idx][current_right_idx-1] )
        {
            State   tmp = {current_num_of_medicines+1,
                            current_left_idx,current_right_idx-1};
            
            q.push(tmp);
            visited[current_left_idx][current_right_idx-1] = true;

            ret = max(ret,current_num_of_medicines+1);
        }
    }    

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}