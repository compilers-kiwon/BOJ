#include    <iostream>

using namespace std;

#define MAX_DAYS    10000

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int coins[MAX_DAYS+1] = {0,};

    for(int N=1,day=1;day<=MAX_DAYS;N++)
    {
        for(int i=1;i<=N&&day<=MAX_DAYS;i++,day++)
        {
            coins[day] = coins[day-1]+N;
        }
    }

    for(;;)
    {
        int d;

        cin>>d;

        if( d == 0 )
        {
            break;
        }

        cout<<d<<' '<<coins[d]<<'\n';
    }

    return  0;
}