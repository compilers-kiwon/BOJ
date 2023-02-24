#include    <iostream>

using namespace std;

#define MAX_SIZE    4

const struct{int low,high,num;} item[MAX_SIZE]
    = {{200,209,8},{200,219,4},{200,229,2},{200,239,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int simulate(int current,int item_idx)
{
    int ret = current;

    for(int i=1;i<=item[item_idx].num&&
            IN_RANGE(item[item_idx].low,ret,item[item_idx].high);i++,ret++);
    
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,best_item,max_level;

    cin>>N;
    max_level = N;

    for(int i=0;i<MAX_SIZE;i++)
    {
        int level_up = simulate(N,i);

        if( max_level <= level_up )
        {
            best_item = i;
            max_level = level_up;
        }
    }

    cout<<best_item+1<<'\n';

    return  0;
}