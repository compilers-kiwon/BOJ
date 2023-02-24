#include    <iostream>
#include    <cmath>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define will_find_cow(p1,p2,c) \
    IN_RANGE(min((p1),(p2)),(c),max((p1),(p2)))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int total,x,y;

    cin>>x>>y;
    total = 0;

    for(int current=x,offset=1,dir=1;;offset*=2,dir*=-1)
    {
        int next = x+(offset*dir);

        if( will_find_cow(current,next,y) )
        {
            total += abs(current-y);
            break;
        }

        total += abs(next-current);
        current = next;
    }

    cout<<total<<'\n';

    return  0;
}