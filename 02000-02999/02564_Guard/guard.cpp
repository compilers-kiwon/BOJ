#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (100+1)
#define MY_POS      0

#define NORTH   1
#define SOUTH   2
#define WEST    3
#define EAST    4

int width,height,num_of_stores,pos[MAX_SIZE];

#define TOTAL_DISTANCE  (2*width+2*height)

int     convert_linear_pos(void)
{
    int dir,pos,ret;
    
    cin>>dir>>pos;
    ret = 0;

    switch(dir)
    {
        case    NORTH:
            ret = pos;
            break;
        case    SOUTH:
            ret = width+height+(width-pos);
            break;
        case    WEST:
            ret = width+height+width+(height-pos);
            break;
        case    EAST:
            ret = width+pos;
            break;
        default:
            // do nothing
            break;    
    }

    return  ret;
}

int     get_distance(int p1,int p2)
{
    return  min(abs(p1-p2),
        min(p1,p2)+TOTAL_DISTANCE-max(p1,p2));
}

void    input(void)
{
    cin>>width>>height>>num_of_stores;

    for(int i=1;i<=num_of_stores;i++)
    {
        pos[i] = convert_linear_pos();
    }

    pos[MY_POS] = convert_linear_pos();
}

int     get_sum_of_distance(void)
{
    int ret = 0;

    for(int i=1;i<=num_of_stores;i++)
    {
        ret += get_distance(pos[MY_POS],pos[i]);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_sum_of_distance()<<'\n';

    return  0;
}