#include    <iostream>
#include    <stack>

using namespace std;

#define MAX_SIZE    (200000+1)
#define NONE        0

int         N,M,stack_of_book[MAX_SIZE];
stack<int>  st[MAX_SIZE];

#define remove_book_from_stack(st)  ((st).pop())

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int k;

        cin>>k;

        for(int j=1;j<=k;j++)
        {
            int b;

            cin>>b;
            st[i].push(b);
        }
    }
}

void    init(void)
{
    for(int i=1;i<=M;i++)
    {
        stack_of_book[st[i].top()] = i;
    }
}

void    update_stack(int st_ptr)
{
    if( !st[st_ptr].empty() )
    {
        stack_of_book[st[st_ptr].top()] = st_ptr;
    }
}

bool    simulate(void)
{
    bool    ret = true;

    for(int i=1;i<=N;i++)
    {
        int current_stack_idx = stack_of_book[i];

        if( current_stack_idx == NONE )
        {
            ret = false;
            break;
        }

        remove_book_from_stack(st[current_stack_idx]);
        update_stack(current_stack_idx);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    init();

    cout<<(simulate()?"Yes":"No")<<'\n';

    return  0;
}