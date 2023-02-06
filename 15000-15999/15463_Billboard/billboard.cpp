#include    <iostream>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

typedef struct{int x1,y1,x2,y2;}    Pos;

#define input(p)    (cin>>(p).x1>>(p).y1>>(p).x2>>(p).y2)
#define get_area(p) (((p).x2-(p).x1)*((p).y2-(p).y1))

#define IN_AREA(x,y,p) \
    (IN_RANGE((p).x1,(x),(p).x2)&&IN_RANGE((p).y1,(y),(p).y2))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos b1,b2,t;
    int total_area;

    input(b1);input(b2);input(t);
    total_area = get_area(b1)+get_area(b2);

    for(int x=t.x1;x<t.x2;x++)
    {
        for(int y=t.y1;y<t.y2;y++)
        {
            if( IN_AREA(x,y,b1) || IN_AREA(x,y,b2) )
            {
                total_area--;
            }
        }
    }

    cout<<total_area<<'\n';

    return  0;
}