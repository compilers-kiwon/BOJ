#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000000+1)

#define CLEAN   0
#define DIRTY   1

static int  N,M,state[MAX_SIZE+1];
static int  cnt_of_dirty_blocks;

int make_dirty(int mid_idx)
{
    int ret = cnt_of_dirty_blocks;

    if( state[mid_idx] == DIRTY )
    {
        return  ret;
    }

    int left_idx = mid_idx-1;
    int right_idx = mid_idx+1;
    
    state[mid_idx] = DIRTY;

    if( state[left_idx] == state[right_idx] )
    {
        ret += (state[left_idx]==CLEAN)?1:-1;
    }

    return  ret;
}

int read_state(void)
{
    for(int i=1;i<=N;i++)
    {
        cin>>state[i];
        
        cnt_of_dirty_blocks +=
            (state[i-1]==CLEAN&&state[i]==DIRTY)?1:0;
    }

    return  0;
}

int simulate(void)
{
    for(int m=1;m<=M;m++)
    {
        int n,i;

        cin>>n;

        if( n == 0 )
        {
            cout<<cnt_of_dirty_blocks<<'\n';
            continue;
        }

        cin>>i;
        cnt_of_dirty_blocks = make_dirty(i);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;

    read_state();
    simulate();
    
    return  0;
}