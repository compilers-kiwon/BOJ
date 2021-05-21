#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)
#define NO_PATH     0
#define INF         0x7FFFFFFF

int N,M,d[MAX_SIZE][MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int A,B;

        cin>>A>>B;
        d[A][B] = d[B][A] = 1;
    }
}

void    get_path(void)
{
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if( i == j )
                {
                    continue;
                }

                if( d[i][k]!=NO_PATH && d[k][j]!=NO_PATH )
                {
                    if( d[i][j]==NO_PATH || d[i][j]>d[i][k]+d[k][j] )
                    {
                        d[i][j] = d[j][i] = d[i][k]+d[k][j];
                    }
                } 
            }
        }
    }
}

int     get_sum_of_min_distance(int s1,int s2)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        ret += min(d[s1][i],d[s2][i]);
    }

    return  ret;
}

int     find_optimal_pos(int& p1,int& p2)
{
    int ret = INF;

    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            int d_sum = get_sum_of_min_distance(i,j);

            if( d_sum < ret )
            {
                ret = d_sum;
                p1 = i;
                p2 = j;
            }
        }
    }

    return  (ret*2);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_path();

    int c1,c2,min_sum;

    min_sum = find_optimal_pos(c1,c2);
    cout<<c1<<' '<<c2<<' '<<min_sum<<'\n';

    return  0;
}