#include    <iostream>

using namespace std;

#define MAX_SIZE    (10000+1)

typedef long long int   int64;

static int N,Q;
static int64 money[MAX_SIZE],sum[MAX_SIZE];

int update(int day,int64 m)
{
    money[day] = m;
    
    for(int i=1;i<=N;i++)
    {
        sum[i] = sum[i-1]+money[i];
    }

    return  0;
}

int64 get_amount_of_change(int from,int to)
{
    return  sum[to]-sum[from-1];
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>Q;

    for(int i=1;i<=Q;i++)
    {
        int     a,b;
        int64   c;

        cin>>a>>b>>c;

        if( a == 1 )
        {
            update(b,c);
        }
        else
        {
            cout<<get_amount_of_change(b,(int)c)<<'\n';
        }
    }

    return  0;
}