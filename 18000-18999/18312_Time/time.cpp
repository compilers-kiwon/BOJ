#include    <iostream>

using namespace std;

#define HOUR        0
#define MINUTE      1
#define SECOND      2
#define MAX_UNIT    3

bool    is_included(int* time,int n)
{
    for(int i=HOUR;i<=SECOND;i++)
    {
        int d1,d2;

        d1 = time[i]%10;
        d2 = time[i]/10;

        if( d1==n || d2==n )
        {
            return  true;
        }
    }

    return  false;
}

int    check_time_unit(int end_hour,int digit)
{
    int current_time[MAX_UNIT],ret=0;

    for(int hour=0;hour<=end_hour;hour++)
    {
        current_time[HOUR] = hour;

        for(int minute=0;minute<60;minute++)
        {
            current_time[MINUTE] = minute;

            for(int second=0;second<60;second++)
            {
                current_time[SECOND] = second;

                if( is_included(current_time,digit) == true )
                {
                    ret++;
                }
            }        
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,K;

    cin>>N>>K;
    cout<<check_time_unit(N,K)<<'\n';
    
    return  0;
}