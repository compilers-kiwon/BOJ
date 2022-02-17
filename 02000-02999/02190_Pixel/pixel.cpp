#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

typedef long long int       int64;
typedef pair<int64,int64>   Pos;    // first:x,second:y

int     N;
int64   x[MAX_SIZE],y[MAX_SIZE],A,B;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int count_num_of_pixels(int64 min_x,int64 min_y,int64 max_x,int64 max_y)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        if( IN_RANGE(min_x,x[i],max_x) && IN_RANGE(min_y,y[i],max_y) )
        {
            ret++;
        }
    }

    return  ret;
}

void    input(void)
{
    cin>>N>>A>>B;

    for(int i=1;i<=N;i++)
    {
        cin>>x[i]>>y[i];
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    int max_num_of_pixels = 0;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int64   min_x = x[i];
            int64   max_x = x[i]+A;
            int64   min_y = y[j];
            int64   max_y = y[j]+B;

            max_num_of_pixels = max(max_num_of_pixels,count_num_of_pixels(min_x,min_y,max_x,max_y));
        }
    }

    cout<<max_num_of_pixels<<'\n';

    return  0;
}