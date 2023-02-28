#include    <iostream>
#include    <vector>

using namespace std;

#define TRUE    1
#define FALSE   0

#define MAX_NUM_OF_COWS (20+1)

static int  N,K;
static vector<int>  cow_rank[MAX_NUM_OF_COWS];

int is_batter(const vector<int>& A,
                const vector<int>& B)
{
    for(int i=0;i<A.size();i++)
    {
        if( !(A[i]<B[i]) )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int input(void)
{
    cin>>K>>N;

    for(int s=1;s<=K;s++)
    {
        for(int r=1;r<=N;r++)
        {
            int cow;

            cin>>cow;
            cow_rank[cow].push_back(r);
        }
    }

    return  0;
}

int get_num_of_pairs(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if( is_batter(cow_rank[i],
                        cow_rank[j]) == TRUE )
            {
                ret++;
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_num_of_pairs()<<'\n';

    return  0;
}