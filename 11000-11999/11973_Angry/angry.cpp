#include    <iostream>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (50000+1)
#define MIN_RANGE   0
#define MAX_RANGE   (1000000000/2)

int N,K,x[MAX_SIZE];

void    input(void)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>x[i];
    }
}

int     simulate(int radius)
{
    int ret = 0;

    for(int i=1;i<=N;ret++)
    {
        for(int end=2*radius+x[i];i<=N&&x[i]<=end;i++);
    }

    return  ret;
}

int     solve(void)
{
    int ret;

    for(int R_min=MIN_RANGE,R_max=MAX_RANGE;R_min<=R_max;)
    {
        int R_mid = (R_min+R_max)/2;
        int num_of_expolosions = simulate(R_mid);

        if( num_of_expolosions > K )
        {
            R_min = R_mid+1;
        }
        else
        {
            if( num_of_expolosions == K )
            {
                ret = R_mid;
            }

            R_max = R_mid-1;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    sort(&x[1],&x[N+1]);

    cout<<solve()<<'\n';

    return  0;
}