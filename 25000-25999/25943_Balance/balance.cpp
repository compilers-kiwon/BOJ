#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_NUM_OF_STONES   (10000+1)
#define NUM_OF_WEIGHTS      7

const static int weight[NUM_OF_WEIGHTS+1] = {0,100,50,20,10,5,2,1};

static int  n,stone[MAX_NUM_OF_STONES],left_side,right_side;

#define SAME    0
#define LEFT    -1
#define RIGHT   1

#define get_light_side(l,r) ((l)==(r)?SAME:((l)-(r))/abs((l)-(r)))

int input(void)
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>stone[i];
    }

    return  0;
}

int init(void)
{
    left_side = stone[1];
    right_side = stone[2];

    return  0;
}

int place_stone(void)
{
    for(int i=3;i<=n;i++)
    {
        int lighter = get_light_side(left_side,right_side);

        switch(lighter)
        {
            case SAME:
            case LEFT:
                left_side+=stone[i];break;
            case RIGHT: right_side+=stone[i];break;
            default:/*do nothing*/;break;
        }
    }

    return  abs(left_side-right_side);
}

int simulate(void)
{
    int ret = 0;
    int diff = place_stone();

    // place weights
    for(int i=1;i<=NUM_OF_WEIGHTS;i++)
    {
        ret += diff/weight[i];
        diff %= weight[i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();init();
    cout<<simulate()<<'\n';

    return  0;
}