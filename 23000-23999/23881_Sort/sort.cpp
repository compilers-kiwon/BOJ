#include    <iostream>
#include    <queue>
#include    <map>

using namespace std;

#define MAX_SIZE    (10000+1)
#define NONE        (-1)

static int  N,K,A[MAX_SIZE];
static priority_queue<int>  pq;
static map<int,int> idx_table;

int input(void)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
        pq.push(A[i]);
        idx_table[A[i]] = i;
    }

    return  0;
}

int simulate(int& small,int& big)
{
    int ret = NONE;
    int num_of_swaps = 0;

    for(int i=N;i>=2;i--,pq.pop())
    {
        int     max_num = pq.top();
        int&    current_num = A[i];

        if( current_num == max_num )
        {
            continue;
        }

        big = max_num;
        small = current_num;

        swap(current_num,A[idx_table[max_num]]);

        if( ++num_of_swaps == K )
        {
            ret = ~NONE;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int big,small;

    input();

    if( simulate(small,big) == NONE )
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<small<<' '<<big<<'\n';
    }

    return  0;
}