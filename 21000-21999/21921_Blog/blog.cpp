#include    <iostream>

using namespace std;

#define MAX_SIZE    (250000+1)

int X,N,sum[MAX_SIZE];

void    input(void)
{
    cin>>N>>X;

    for(int i=1;i<=N;i++)
    {
        int v;

        cin>>v;
        sum[i] = sum[i-1]+v;
    }
}

int     count(int& cnt)
{
    int ret = 0;

    for(int i=X;i<=N;i++)
    {
        int v = sum[i]-sum[i-X];

        if( v >= ret )
        {
            cnt = ((v==ret)?cnt+1:1);
            ret = sum[i]-sum[i-X];
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_num,cnt;

    input();

    cnt = 0; 
    max_num = count(cnt);

    if( max_num == 0 )
    {
        cout<<"SAD\n";
    }
    else
    {
        cout<<max_num<<'\n'<<cnt<<'\n';
    }

    return  0;
}