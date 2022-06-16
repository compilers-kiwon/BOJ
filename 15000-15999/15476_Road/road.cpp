#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (25+1)

int H,W,map[MAX_SIZE][MAX_SIZE];

int get_distance(int r1,int c1,int r2,int c2)
{
    int d1 = abs(r1-r2);
    int d2 = abs(c1-c2);

    return  min(d1,d2);
}

int get_total_distance(int row,int col)
{
    int ret = 0;

    for(int r=1;r<=H;r++)
    {
        for(int c=1;c<=W;c++)
        {
            ret += get_distance(row,col,r,c)*map[r][c];
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>H>>W;

    for(int row=1;row<=H;row++)
    {
        for(int col=1;col<=W;col++)
        {
            cin>>map[row][col];
        }
    }

    int min_distance = 0x7FFFFFFF;

    for(int row=1;row<=H;row++)
    {
        for(int col=1;col<=W;col++)
        {
            min_distance = min(min_distance,get_total_distance(row,col));
        }
    }

    cout<<min_distance<<'\n';

    return  0;
}