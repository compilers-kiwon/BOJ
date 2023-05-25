#include    <iostream>
#include    <cstring>

using namespace std;

#define INF 0x7FFFFFFF
#define MAX_NUM_OF_DAYS 100

static int  C,D,d;
static int  N,X[MAX_NUM_OF_DAYS+1];
static int  M,Y[MAX_NUM_OF_DAYS+1];
static int  dp[MAX_NUM_OF_DAYS][MAX_NUM_OF_DAYS][2][2];

#define TRUE    1
#define FALSE   0

int read_schedule(int& num_of_days,int city_to_visit[])
{
    for(num_of_days=1;;num_of_days++)
    {
        cin>>city_to_visit[num_of_days];

        if( city_to_visit[num_of_days] == 0 )
        {
            num_of_days--;
            break;
        }
    }

    return  0;
}

int input(void)
{
    cin>>C>>D>>d;

    read_schedule(N,X);
    read_schedule(M,Y);

    memset(dp,-1,sizeof(dp));

    return  0;
}

int get_dp(int X_done,int Y_done,int X_rest,int Y_rest)
{
    if( X_done==N && Y_done==M )
    {
        return  0;
    }

    int&    ret = dp[X_done][Y_done][X_rest][Y_rest];
    
    if( ret != -1 )
    {
        return  ret;
    }

    ret = INF;

    // 1. X train & Y rest
    if( X_done < N )
    {
        ret = min(ret,
                  get_dp(X_done+1,Y_done,FALSE,TRUE)+C+d+((Y_rest)?0:D));
    }

    // 2. X train & Y rest
    if( Y_done < M )
    {
        ret = min(ret,
                  get_dp(X_done,Y_done+1,TRUE,FALSE)+C+d+((X_rest)?0:D));
    }

    // 3. X train & Y train
    if( X_done<N && Y_done<M )
    {
        ret = min(ret,
                  get_dp(X_done+1,Y_done+1,FALSE,FALSE)+
                        ((X[X_done+1]==Y[Y_done+1])?C:C+C));
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        input();
        cout<<get_dp(0,0,FALSE,FALSE)<<'\n';
    }

    return  0;
}