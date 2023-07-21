#include    <iostream>
#include    <string>
#include    <cmath>

using namespace std;

static pair<int,int>  offset[0x100];    // first:x, second:y

#define get_distance(x1,y1,x2,y2)   (abs((x1)-(x2))+abs((y1)-(y2)))

int init(void)
{
    offset['E'] = {1,0};
    offset['W'] = {-1,0};
    offset['N'] = {0,-1};
    offset['S'] = {0,1};

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Z;

    init();
    cin>>Z;

    for(int i=1;i<=Z;i++)
    {
        int     n,x,y;
        string  move;

        cin>>n>>move;
        x = y = 0;

        for(int j=0;j<n;j++)
        {
            x += offset[move[j]].first;
            y += offset[move[j]].second;
        }

        cout<<get_distance(0,0,x,y)<<'\n';
    }

    return  0;
}