#include    <iostream>

using namespace std;

#define MAX_SIZE        (100+1)
#define MAX_RESET_SCORE (1000+1)

static int  N,M,A[MAX_SIZE];
static bool is_reset[MAX_RESET_SCORE];

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    cin>>M;
    
    for(int i=1;i<=M;i++)
    {
        int B;

        cin>>B;
        is_reset[B] = true;
    }

    return  0;
}

int simulate(void)
{
    int cur_score = 0;

    for(int i=1;i<=N;i++)
    {
        cur_score += A[i];
        cur_score = (is_reset[cur_score])?0:cur_score;
    }

    return  cur_score;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}