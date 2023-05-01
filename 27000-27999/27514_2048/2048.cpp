#include    <iostream>

using namespace std;

#define MAX_SIZE    62

static int  N,table[MAX_SIZE+1];

typedef long long int   int64;

#define merge(n) \
    ((table[(n)]>=2)?(table[(n)+1]+=table[(n)]/2):0)

int get_idx(int64 n)
{
    int ret;

    for(int i=0;i<=MAX_SIZE;i++)
    {
        if( ((1LL<<i)&n) != 0 )
        {
            ret = i;
            break;
        }
    }

    return  ret;
}

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int64   a;

        cin>>a;

        if( a != 0 )
        {
            table[get_idx(a)]++;
        }
    }

    return  0;
}

int64   simulate(void)
{
    int64   ret = 0;

    for(int i=0;i<=MAX_SIZE;i++)
    {
        int64   n = 1LL<<i;

        ret = max(ret,((table[i]!=0)?n:0));
        merge(i);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}