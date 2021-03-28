#include    <iostream>
#include    <queue>
#include    <map>

using namespace std;

#define MAX_SIZE    8

int final_arr[MAX_SIZE+1],final_num;

typedef struct{int num_of_operations,arr[MAX_SIZE+1],num;}  State;

void    input(void)
{
    for(int i=1;i<=MAX_SIZE;i++)
    {
        cin>>final_arr[i];
    }
}

int     get_num(const int* arr)
{
    int ret = 0;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        ret = ret*10+arr[i];
    }

    return  ret;
}

void    do_operation(char op,const int* src,int* result)
{
    int tmp;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        result[i] = src[i];
    }

    switch(op)
    {
        case    'A':
            for(int i=1;i<=MAX_SIZE/2;i++)
            {
                swap(result[i],result[MAX_SIZE+1-i]);
            }
            break;
        case    'B':
            swap(result[4],result[3]);swap(result[3],result[2]);swap(result[2],result[1]);
            swap(result[5],result[6]);swap(result[6],result[7]);swap(result[7],result[8]);
            break;
        case    'C':
            tmp = result[6];
            result[6]=result[7];result[7]=result[2];
            result[2]=result[3];result[3]=tmp;
            break;
        case    'D':
            swap(result[1],result[5]);
            break;
        default:
            // do nothing
            break;
    }
}

int     bfs(void)
{
    int             ret;
    State           s;
    queue<State>    state_q;
    map<int,bool>   visited;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        s.arr[i] = i;
    }

    s.num_of_operations = 0;
    s.num = 12345678;

    state_q.push(s);
    visited[s.num] = true;

    for(;!state_q.empty();state_q.pop())
    {
        State   current;

        current = state_q.front();

        if( current.num == final_num )
        {
            ret = current.num_of_operations;
            break;
        }

        for(char c='A';c<='D';c++)
        {
            State   adj;

            do_operation(c,current.arr,adj.arr);
            adj.num = get_num(adj.arr);

            if( visited[adj.num] == false )
            {
                adj.num_of_operations = current.num_of_operations+1;
                
                state_q.push(adj);
                visited[adj.num] = true;
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    final_num = get_num(final_arr);

    cout<<bfs()<<'\n';

    return  0;
}