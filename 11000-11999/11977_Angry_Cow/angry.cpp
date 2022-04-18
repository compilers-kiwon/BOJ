#include    <iostream>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (100+1)

int N,x[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>x[i];
    }
}

int     get_num_of_expolosions(int pos)
{
    int     ret,left_pos,right_pos;
    bool    left_updated,right_updated;
    
    ret = 1;
    
    left_pos = right_pos = pos;
    left_updated = right_updated = true;

    for(int blast=1;;blast++)
    {
        int cnt_of_left_expolosions,cnt_of_right_expolosions;

        cnt_of_left_expolosions = cnt_of_right_expolosions = 0;

        // left
        for(int current_pos=left_pos;
            left_updated&&(left_pos-1)>=1&&(x[current_pos]-x[left_pos-1])<=blast;
            left_pos--)
        {
            ret++;
            cnt_of_left_expolosions++;
        }

        // right
        for(int current_pos=right_pos;
            right_updated&&(right_pos+1)<=N&&(x[right_pos+1]-x[current_pos])<=blast;
            right_pos++)
        {
            ret++;
            cnt_of_right_expolosions++;
        }

        left_updated = (cnt_of_left_expolosions>0);
        right_updated = (cnt_of_right_expolosions>0);

        if( !left_updated && !right_updated )
        {
            break;
        }
    }
    
    return  ret;
}

int     simulate(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        ret = max(ret,get_num_of_expolosions(i));
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    sort(&x[1],&x[N+1]);

    cout<<simulate()<<'\n';

    return  0;
}