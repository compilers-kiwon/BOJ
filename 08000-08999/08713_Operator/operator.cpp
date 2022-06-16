#include    <iostream>
#include    <climits>

using namespace std;

#define ADD 0
#define SUB 1
#define MUL 2
#define NUM_OF_OPERATORS    3

int     calculate(int a,int b,int op)
{
    int ret = 0;

    switch(op)
    {
        case    ADD:
            ret = a+b;
            break;
        case    SUB:
            ret = a-b;
            break;
        case    MUL:
            ret = a*b;
            break;
        default:
            // do nothing
            break;
    }

    return  ret;
}

void    print_op(int op)
{
    char    c = '\0';

    switch(op)
    {
        case    ADD:
            c = '+';
            break;
        case    SUB:
            c = '-';
            break;
        case    MUL:
            c = '*';
            break;
        default:
            // do nothing
            break;
    }

    cout<<c;
}

void    print_num(int n)
{
    if( n < 0 )
    {
        cout<<'('<<n<<')';
    }
    else
    {
        cout<<n;
    }
}

void    print_exp(int a,int b,int op,int result,int cnt)
{
    if( cnt != 1 )
    {
        cout<<"NIE\n";
        return;
    }

    print_num(a);print_op(op);print_num(b);cout<<'=';print_num(result);cout<<'\n';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a,b,op,cnt,result;

    cin>>a>>b;
    result = INT_MIN;

    for(int i=0;i<NUM_OF_OPERATORS;i++)
    {
        int tmp;

        tmp = calculate(a,b,i);

        if( tmp >= result )
        {
            if( tmp > result )
            {
                cnt = 0;
            }

            cnt++;
            result = tmp;
            op = i;
        }
    }

    print_exp(a,b,op,result,cnt);

    return  0;
}