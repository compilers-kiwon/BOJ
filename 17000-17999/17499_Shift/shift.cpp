#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_SIZE    200000

static int  N,Q,a[MAX_SIZE];

#define ADD     1
#define RIGHT   2
#define LEFT    3

int read_arr(void)
{
    cin>>N>>Q;

    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }

    return  0;
}

int add_num(int head)
{
    int i,x;

    cin>>i>>x;
    a[(head+(i-1))%N] += x;

    return  0;
}

int shift_right(int head)
{
    int s,new_head;

    cin>>s;
    new_head = (head+N-s)%N;

    return  new_head;
}

int shift_left(int head)
{
    int s,new_head;

    cin>>s;
    new_head = (head+abs(s))%N;

    return  new_head;
}

int simulate(void)
{
    int head = 0;

    for(int q=1;q<=Q;q++)
    {
        int op;

        cin>>op;

        switch(op)
        {
            case ADD:add_num(head);break;
            case RIGHT:head=shift_right(head);break;
            case LEFT:head=shift_left(head);break;
            default: break; 
        }
    }

    return  head;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int head;

    read_arr();
    head = simulate();
    
    for(int i=0;i<N;i++)
    {
        cout<<a[(head+i)%N]<<((i==N-1)?'\n':' ');
    }

    return  0;
}