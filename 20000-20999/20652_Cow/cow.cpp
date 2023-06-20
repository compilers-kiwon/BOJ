#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    (50+1)
#define INF         0x7FFFFFFF

typedef struct{char d;int x,y;} Cow;

static int  N,eat[MAX_SIZE];
static Cow  c[MAX_SIZE];

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        eat[i] = INF;
        cin>>c[i].d>>c[i].x>>c[i].y;
    }

    return  0;
}

int simulate(int me,int other)
{
    int ret;

    if( c[me].d == c[other].d )
    {
        if( c[me].d == 'E' )
        {
            if(c[me].y!=c[other].y||!(c[me].x<c[other].x)) ret=INF;
            else ret=INF;
        }
        else
        {
            if(c[me].x!=c[other].x||!(c[me].y<c[other].y)) ret=INF;
            else ret=INF;
        }
    }
    else
    {
        int north_x,north_y,east_x,east_y;

        if( c[me].d == 'N' )
        {
            north_x = c[me].x;
            north_y = c[me].y;
            east_x = c[other].x;
            east_y = c[other].y;
        }
        else
        {
            north_x = c[other].x;
            north_y = c[other].y;
            east_x = c[me].x;
            east_y = c[me].y;
        }

        if( north_x<east_x || north_y>east_y )
        {
            ret = INF;
        }
        else
        {
            int x = north_x;
            int y = east_y;
            int me_dist = (x-c[me].x)+(y-c[me].y);
            int other_dist = (x-c[other].x)+(y-c[other].y);

            if(other_dist>eat[other]||me_dist<=other_dist) ret=INF;
            else ret=me_dist;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    bool    updated;

    for(updated=true;updated!=false;)
    {
        updated = false;

        for(int i=1;i<=N;i++)
        {
            int min_num_of_cells = INF;

            for(int j=1;j<=N;j++)
            {
                if( i == j )
                {
                    continue;
                }

                min_num_of_cells = min(min_num_of_cells,simulate(i,j));
            }

            if( min_num_of_cells != eat[i] )
            {
                updated = true;
                eat[i] = min_num_of_cells;
            }
        }
    }

    for(int i=1;i<=N;i++)
        cout<<(eat[i]==INF?"Infinity":to_string(eat[i]))<<'\n';

    return  0;
}