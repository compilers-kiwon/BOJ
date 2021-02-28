#include    <iostream>

using namespace std;

#define MAX_SIZE    (15+1)

int     N,L,R,X,d[MAX_SIZE],cnt;
bool    selected[MAX_SIZE];

void    select_problem(int n,int easy,int difficult,int sum)
{
    if( n > N )
    {
        if( difficult-easy>=X && (sum>=L&&sum<=R) )
        {
            cnt++;
        }

        return  ;
    }

    select_problem(n+1,easy,difficult,sum);
    select_problem(n+1,min(easy,d[n]),max(difficult,d[n]),sum+d[n]);
}

void    input(void)
{
    cin>>N>>L>>R>>X;

    for(int i=1;i<=N;i++)
    {
        cin>>d[i];
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    select_problem(1,0x7FFFFFFF,0,0);

    cout<<cnt<<'\n';

    return  0;
}