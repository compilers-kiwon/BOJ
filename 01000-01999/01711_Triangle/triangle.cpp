#include    <iostream>

using namespace std;

#define MAX_SIZE    (1500+1)

typedef long long int       int64;
typedef struct{int64 x,y;}  Pos;

int N;
Pos p[MAX_SIZE];

#define get_distance(a,b)   ((p[(a)].x-p[(b)].x)*(p[(a)].x-p[(b)].x)+(p[(a)].y-p[(b)].y)*(p[(a)].y-p[(b)].y))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>p[i].x>>p[i].y;
    }

    int cnt = 0;

    for(int a=1;a<=N-2;a++)
    {
        for(int b=a+1;b<=N-1;b++)
        {
            for(int c=b+1;c<=N;c++)
            {
                int64   d1 = get_distance(a,b);
                int64   d2 = get_distance(b,c);
                int64   d3 = get_distance(c,a);

                if( d1+d2+d3-max(d1,max(d2,d3)) == max(d1,max(d2,d3)) )
                {
                    cnt++;
                }
            }
        }
    }

    cout<<cnt<<'\n';

    return  0;
}