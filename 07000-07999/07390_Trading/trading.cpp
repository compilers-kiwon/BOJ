#include    <iostream>

using namespace std;

#define MAX_SIZE    (10000+1)

int     m,n,k;
double  p[MAX_SIZE],sum[MAX_SIZE];
bool    bullish[MAX_SIZE],bearish[MAX_SIZE];

void    input(void)
{
    cin>>m>>n>>k;

    for(int i=1;i<=k;i++)
    {
        cin>>p[i];
        sum[i] = sum[i-1]+p[i];
    }
}

double  get_average(int from,int period)
{
    return  (sum[from]-sum[from-period])/(double)period;
}

void    get_trend(void)
{
    for(int i=n;i<=k;i++)
    {
        double  avg_m,avg_n;

        avg_m = get_average(i,m);
        avg_n = get_average(i,n);

        if( avg_m > avg_n )
        {
            bullish[i] = true;
        }

        if( avg_m < avg_n )
        {
            bearish[i] = true;
        }
    }
}

void    generate_signal(void)
{
    if( bullish[n] == true )
    {
        cout<<"BUY ON DAY "<<n<<'\n';
    }

    if( bearish[n] == true )
    {
        cout<<"SELL ON DAY "<<n<<'\n';
    }

    for(int i=n+1;i<=k;i++)
    {
        if( bullish[i]==true && bearish[i-1]==true )
        {
            cout<<"BUY ON DAY "<<i<<'\n';
        }

        if( bearish[i]==true && bullish[i-1]==true )
        {
            cout<<"SELL ON DAY "<<i<<'\n';
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_trend();
    generate_signal();

    return  0;
}