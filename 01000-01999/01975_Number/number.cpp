#include    <iostream>

using namespace std;

#define MAX_NUM 1000

static int  sum[MAX_NUM+1];

int f(int N,int b)
{
    int i;

    for(i=0;N%b==0;N/=b,i++);
    return  i;
}

int init(int N)
{
    for(int b=2;b<=N;b++)
    {
        sum[N] += f(N,b);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    for(int i=1;i<=MAX_NUM;i++)
    {
        init(i);
    }

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int N;

        cin>>N;
        cout<<sum[N]<<'\n';
    }

    return  0;
}