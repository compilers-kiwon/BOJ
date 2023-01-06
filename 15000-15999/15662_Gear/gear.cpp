#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_NUM_OF_GEARS    (1000+1)
#define GEAR_SIZE           8

#define NONE                0
#define CLOCKWISE           1
#define COUNTERCLOCKWISE    -1

#define RIGHT_POS   2
#define LEFT_POS    6

#define NEXT_DIR(d) \
    (((d)==CLOCKWISE)?COUNTERCLOCKWISE:CLOCKWISE)

int     T,K,r[MAX_NUM_OF_GEARS];
string  gear[MAX_NUM_OF_GEARS];

void    rotate_clockwise(int idx)
{
    gear[idx] = gear[idx].substr(GEAR_SIZE-1,1)
                    + gear[idx].substr(0,GEAR_SIZE-1);
}

void    rotate_counterclockwise(int idx)
{
    gear[idx] = gear[idx].substr(1,GEAR_SIZE-1)
                    + gear[idx].substr(0,1);
}

void    get_gears_to_be_rotated(int init_idx,int init_dir)
{
    r[init_idx] = init_dir;

    for(int current_idx=init_idx-1;current_idx>=1;current_idx--)
    {
        int prev_idx = current_idx+1;

        if( gear[current_idx][RIGHT_POS] == gear[prev_idx][LEFT_POS] )
        {
            break;
        }

        r[current_idx] = NEXT_DIR(r[prev_idx]);
    }

    for(int current_idx=init_idx+1;current_idx<=T;current_idx++)
    {
        int prev_idx = current_idx-1;

        if( gear[current_idx][LEFT_POS] == gear[prev_idx][RIGHT_POS] )
        {
            break;
        }

        r[current_idx] = NEXT_DIR(r[prev_idx]);
    }
}

void    read_gear_state(void)
{
    cin>>T;

    for(int i=1;i<=T;i++)
    {
        cin>>gear[i];
    }
}

void    rotate(void)
{
    cin>>K;

    for(int i=1;i<=K;i++)
    {
        int gear_idx,rotate_dir;

        cin>>gear_idx>>rotate_dir;
        get_gears_to_be_rotated(gear_idx,rotate_dir);

        for(int j=1;j<=T;j++)
        {
            if( r[j] != NONE )
            {
                (r[j]==CLOCKWISE)?rotate_clockwise(j)
                                :rotate_counterclockwise(j);
            }

            r[j] = NONE;
        }
    }
}

int     get_num_of_matched_gears(int idx,char p)
{
    int ret = 0;

    for(int i=1;i<=T;i++)
    {
        if( gear[i][idx] == p )
        {
            ret++;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_gear_state();
    rotate();
    cout<<get_num_of_matched_gears(0,'1')<<'\n';

    return  0;
}