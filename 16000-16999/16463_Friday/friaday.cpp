#include    <iostream>

using namespace std;

#define NUM_OF_MONTHS   12

const static int num_of_days[NUM_OF_MONTHS+1] = 
                {0,31,28,31,30,31,30,31,31,30,31,30,31};

#define is_leap_year(y) (((y)%400==0)||(((y)%100!=0)&&((y)%4==0)))

#define FIRST_YEAR      2019
#define FIRST_MONTH     1
#define FIRST_FRIDAY    4

#define NUM_OF_DAYS_PER_WEEK    7

#define February    2
#define DAY_13      13

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cnt;

    cin>>N;
    cnt = 0;

    for(int y=FIRST_YEAR,m=FIRST_MONTH,d=FIRST_FRIDAY;y<=N;d+=NUM_OF_DAYS_PER_WEEK)
    {
        int days_of_this_month = 
                num_of_days[m]+((m==February&&is_leap_year(y))?1:0);

        if( d > days_of_this_month )
        {
            if( ++m > NUM_OF_MONTHS )
            {
                y++;
                m = FIRST_MONTH;
            }

            d -= days_of_this_month;
        }

        cnt += (d==DAY_13)?1:0;
    }

    cout<<cnt<<'\n';

    return  0;
}