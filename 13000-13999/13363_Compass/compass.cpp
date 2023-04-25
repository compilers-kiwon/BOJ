#include    <iostream>

using namespace std;

#define CLOCKWISE           1
#define COUNTERCLOCKWISE    -1

int get_distance(int from,int to,int dir)
{
    int ret;

    for(ret=0;;from+=dir,ret++)
    {
        from = (from==360)?0:(from==-1)?359:from;

        if( from == to )
        {
            break;
        }
    }

    return  ret;
}

int simulate(int from,int to)
{
    int clockwise_dist = get_distance(from,to,CLOCKWISE);
    int counterclockwise_dist = get_distance(from,to,COUNTERCLOCKWISE);

    return  (clockwise_dist<=counterclockwise_dist)?
                    clockwise_dist:-counterclockwise_dist;
}

int main(void)
{
    int n1,n2;

    cin>>n1>>n2;
    cout<<simulate(n1,n2)<<'\n';

    return  0;
}