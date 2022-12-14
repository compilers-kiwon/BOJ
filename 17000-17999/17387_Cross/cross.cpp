#include    <iostream>

using namespace std;

typedef long long int       int64;
typedef pair<int64,int64>   Pos;
typedef pair<Pos,Pos>       Line;

#define x   first
#define y   second

void    input(Line& l1,Line& l2)
{
    Pos&    p1 = l1.first;
    Pos&    p2 = l1.second;
    Pos&    p3 = l2.first;
    Pos&    p4 = l2.second;

    cin>>p1.x>>p1.y>>p2.x>>p2.y;
    cin>>p3.x>>p3.y>>p4.x>>p4.y;
}

int64   get_ccw(Pos p1,Pos p2,Pos p3)
{
    int64   v1 = p1.x*p2.y+p2.x*p3.y+p3.x*p1.y;
    int64   v2 = p1.y*p2.x+p2.y*p3.x+p3.y*p1.x;

    return  ((v1-v2)==0?0:(v1-v2)>0?1:-1);
}

bool    is_cross(Line& l1,Line& l2)
{
    bool    ret;

    int64   c1 = get_ccw(l1.first,l1.second,l2.first)
                    *get_ccw(l1.first,l1.second,l2.second);
    int64   c2 = get_ccw(l2.first,l2.second,l1.first)
                    *get_ccw(l2.first,l2.second,l1.second);

    if( c1==0 && c2==0 )
    {
        if( l1.first > l1.second )
        {
            swap(l1.first,l1.second);
        }

        if( l2.first > l2.second )
        {
            swap(l2.first,l2.second);
        }

        ret = ((l2.first<=l1.second)&&(l1.first<=l2.second));
    }
    else
    {
        ret = (c1<=0&&c2<=0);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Line    l1,l2;

    input(l1,l2);
    cout<<(is_cross(l1,l2)?1:0)<<'\n';

    return  0;
}