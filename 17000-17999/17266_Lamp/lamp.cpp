#include    <iostream>

using namespace std;

#define MAX_SIZE    (100000+1)
#define get_mid(n)  (((n)>>1)+((n)&1))

int N,M,pos[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        cin>>pos[i];
    }
}

int     get_head_gap(void)
{
    return  pos[1]-0;
}

int     get_tail_gap(void)
{
    return  N-pos[M];
}

int     place_lamp(void)
{
    int max_gap = 0;

    for(int i=2;i<=M;i++)
    {
        max_gap = max(max_gap,pos[i]-pos[i-1]);
    }

    return  max(get_mid(max_gap),
                max(get_head_gap(),get_tail_gap()));
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<place_lamp()<<'\n';

    return  0;
}