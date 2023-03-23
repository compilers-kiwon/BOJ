#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

typedef pair<int,int>   Card;

static int  N,M,op[MAX_SIZE];
static Card c[MAX_SIZE];

int input(void)
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        cin>>c[i].first>>c[i].second;
    }

    for(int i=1;i<=M;i++)
    {
        cin>>op[i];
    }

    return  0;
}

int turn_around(int K)
{
    for(int i=1;i<=N;i++)
    {
        if( c[i].first <= K )
        {
            swap(c[i].first,c[i].second);
        }
    }

    return  0;
}

int get_sum(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        ret += c[i].first;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=1;i<=M;i++)
    {
        turn_around(op[i]);
    }

    cout<<get_sum()<<'\n';

    return  0;
}