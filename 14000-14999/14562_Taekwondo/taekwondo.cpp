#include    <iostream>
#include    <queue>

using namespace std;

typedef struct{int n,current,target;}   State;

int get_num_of_steps(int my_score,int opposite_score)
{
    int             ret;
    State           s;
    queue<State>    state_q;

    s.n = 0;
    s.current = my_score;
    s.target = opposite_score;

    for(state_q.push(s);!state_q.empty();state_q.pop())
    {
        State   current = state_q.front();

        if( current.current == current.target )
        {
            ret = current.n;
            break;
        }

        s.n = current.n+1;

        // A
        if( current.current*2 <= current.target+3 )
        {
            s.current = current.current*2;
            s.target = current.target+3;

            state_q.push(s);
        }

        // B
        s.current = current.current+1;
        s.target = current.target;

        state_q.push(s);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int C;

    cin>>C;

    for(int c=1;c<=C;c++)
    {
        int S,T;

        cin>>S>>T;
        cout<<get_num_of_steps(S,T)<<'\n';
    }

    return  0;
}