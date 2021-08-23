#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100000+1)

int N,K,pos[MAX_SIZE];

void    input(void)
{
    cin>>N>>K;

    for(int i=2;i<=N;i++)
    {
        int L;

        cin>>L;
        pos[i] = pos[i-1]+L;
    }
}

void    get_reachable_block(vector<int>& cnt)
{
    cnt.push_back(1);

    for(int i=2;i<=N;i++)
    {
        if( pos[i] <= pos[i-1]+K )
        {
            cnt.back()++;
        }
        else
        {
            cnt.push_back(1);
        }
    }
}

int     get_max_num_of_pair_blocks(const vector<int>& cnt)
{
    int ret = cnt.front();
    
    for(int i=0;i<cnt.size()-1;i++)
    {
        ret = max(ret,cnt[i]+cnt[i+1]);
    }
    
    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    vector<int> block;

    get_reachable_block(block);
    cout<<get_max_num_of_pair_blocks(block)<<'\n';

    return  0;
}