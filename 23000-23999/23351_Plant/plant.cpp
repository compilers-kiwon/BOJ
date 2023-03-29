#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

#define TRUE    1
#define FALSE   0

static int  N,K,A,B,w[MAX_SIZE];

int is_available(void)
{
    for(int i=1;i<=N;i++)
    {
        if( --w[i] == 0 )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int water(int pos)
{
    for(int i=pos;i<=min(N,pos+A-1);i++)
    {
        w[i] += B;
    }

    return  0;
}

int simulate(void)
{
    int ret;

    for(int day=1,p=1;;day++,p+=A)
    {
        p = (p>N)?1:p;
        water(p);

        if( is_available() == FALSE )
        {
            ret = day;
            break;
        }
    }

    return  ret;
}

int input(void)
{
    cin>>N>>K>>A>>B;
    fill(&w[1],&w[N+1],K);

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}