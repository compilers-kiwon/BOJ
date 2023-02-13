#include    <iostream>
#include    <cstring>

using namespace std;

#define NUM_OF_SIDES    6
#define SIZE_OF_SIDE    4

#define OK  1
#define NOK 0

#define FORWARD     1
#define BACKWARD    3

#define get_adj(i,dir)  (((i)+(dir))%SIZE_OF_SIDE)

static const int side[NUM_OF_SIDES][SIZE_OF_SIDE] = {
    {1,2,3,4},{5,6,7,8},{9,10,11,12},
    {13,14,15,16},{17,18,19,20},{21,22,23,24}
};

static const pair<int,int> connected[NUM_OF_SIDES][SIZE_OF_SIDE] = {
    {{1,2},{18,20},{12,11},{15,13}},
    {{3,4},{17,19},{10,9},{16,14}},
    {{22,21},{18,17},{6,5},{14,13}},
    {{7,8},{19,20},{23,24},{15,16}},
    {{2,4},{6,8},{10,12},{23,21}},
    {{7,5},{3,1},{22,24},{11,9}}
};

static int color[NUM_OF_SIDES*SIZE_OF_SIDE+1];

int same_color(int state[],const int cells[])
{
    for(int i=0;i<SIZE_OF_SIDE;i++)
    {
        int c1 = state[cells[i]];
        int c2 = state[cells[get_adj(i,FORWARD)]];
        
        if( c1 != c2 )
        {
            return  NOK;
        }
    }

    return  OK;
}

int check_color(int state[])
{
    for(int i=0;i<NUM_OF_SIDES;i++)
    {
        if( same_color(state,&side[i][0]) != OK )
        {
            return  NOK;
        }
    }

    return  OK;
}

int rotate(int r,int d)
{
    int rotated[NUM_OF_SIDES*SIZE_OF_SIDE+1];

    memcpy(rotated,color,sizeof(color));

    for(int i=0;i<SIZE_OF_SIDE;i++)
    {
        int from = i;
        int to = get_adj(i,d);

        rotated[connected[r][to].first] =
                color[connected[r][from].first];
        rotated[connected[r][to].second] =
                color[connected[r][from].second];
    }

    return  check_color(rotated);
}

int simulate(void)
{
    for(int i=0;i<NUM_OF_SIDES;i++)
    {
        if( rotate(i,FORWARD)==OK || rotate(i,BACKWARD)==OK )
        {
            return  OK;
        }
    }

    return  NOK;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=1;i<=NUM_OF_SIDES*SIZE_OF_SIDE;i++)
    {
        cin>>color[i];
    }

    cout<<simulate()<<'\n';

    return  0;
}