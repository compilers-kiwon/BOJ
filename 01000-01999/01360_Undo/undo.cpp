#include    <iostream>
#include    <string>
#include    <stack>

using namespace std;

typedef struct{string op;char c;int t,op_time;} Command;

int input(stack<Command>& st)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        Command c;

        cin>>c.op;
        
        if( c.op == "type" )
        {
            cin>>c.c;
        }
        else
        {
            cin>>c.t;
        }

        cin>>c.op_time;
        st.push(c);
    }

    return  0;
}

int get_available_commands(stack<Command>& st,
                                stack<char>& available)
{
    int available_time = 0x7FFFFFFF;

    for(;!st.empty();st.pop())
    {
        if( st.top().op_time >= available_time )
        {
            continue;
        }

        if( st.top().op == "type" )
        {
            available.push(st.top().c);
        }
        else
        {
            available_time = min(available_time,
                                max(0,st.top().op_time-st.top().t));
        }
    }

    return  0;
}

int simulate(stack<char>& st)
{
    for(;!st.empty();st.pop())
    {
        cout<<st.top();
    }

    cout<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    stack<char>     typed;
    stack<Command>  c;

    input(c);
    get_available_commands(c,typed);
    simulate(typed);

    return  0;
}