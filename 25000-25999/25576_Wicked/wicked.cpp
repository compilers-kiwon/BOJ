#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_NUM_OF_STREAMERS    (10000+1)
#define MAX_LEN_OF_TREND        (100+1)

#define RALPH       1
#define CRITERIA    2000

#define TRUE    1
#define FALSE   0

#define get_half(n) (((n)>>1)+((n)&0x1))

static int  N,M,L[MAX_NUM_OF_STREAMERS][MAX_LEN_OF_TREND];

int input(void)
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin>>L[i][j];
        }
    }

    return  0;
}

int get_along(int idx)
{
    int diff = 0;

    for(int i=1;i<=M;i++)
    {
        diff += abs(L[RALPH][i]-L[idx][i]);
    }

    return  (diff<=CRITERIA)?TRUE:FALSE;
}

int is_wicked_viewer(int allowed)
{
    int cnt = 0;

    for(int i=2;i<=N&&cnt<allowed;i++)
    {
        cnt += get_along(i)?0:1;
    }

    return  (cnt>=allowed)?TRUE:FALSE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<(is_wicked_viewer(get_half(N-RALPH))?"YES":"NO")<<'\n';

    return  0;
}