#include    <iostream>
#include    <string>
#include    <stack>
#include    <map>

using namespace std;

const string    operators = "()*/+-";
map<char,int>   prior;

#define LOW_PRIOR   1
#define MID_PRIOR   2
#define HIGH_PRIOR  3

bool    is_operator(char c)
{
    return  (operators.find(c)!=string::npos);
}

void    init_operator_prior(void)
{
    prior['('] = prior[')'] = LOW_PRIOR;
    prior['+'] = prior['-'] = MID_PRIOR;
    prior['*'] = prior['/'] = HIGH_PRIOR;
}

void    pop_until_expected_operator(char expected,stack<char>& st)
{
    for(;;)
    {
        char    op = st.top();

        st.pop();

        if( op == expected )
        {
            break;
        }

        cout<<op;
    }
}

void    pop_until_lower_prior(int current_prior,stack<char>& st)
{
    for(;!st.empty();)
    {
        char    prev_operator = st.top();

        if( prior[prev_operator] < current_prior )
        {
            break;
        }

        cout<<prev_operator;
        st.pop();
    }
}

void    print_stack(stack<char>& st)
{
    for(;!st.empty();st.pop())
    {
        cout<<st.top();
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string      exp;
    stack<char> st;

    cin>>exp;
    init_operator_prior();

    for(int i=0;i<exp.length();i++)
    {
        char&   c = exp[i];

        if( is_operator(c) != true )
        {
            cout<<c;
            continue;
        }

        switch(c)
        {
            case    '(':
                st.push(c);
                break;
            case    ')':
                pop_until_expected_operator('(',st);
                break;
            default:
                pop_until_lower_prior(prior[c],st);
                st.push(c);
                break;
        }
    }

    print_stack(st);

    return  0;
}