#include    <iostream>

using namespace std;

#define MAX_DAYS    10000

#define DAYS_PER_NORMAL_YEAR    365
#define DAYS_PER_LEAP_YEAR      (DAYS_PER_NORMAL_YEAR+1)

#define is_leap_year(y) (((y)%4==0&&(y)%100!=0)||(y)%400==0)

#define days_of_this_year(y) \
    (is_leap_year((y))?DAYS_PER_LEAP_YEAR:DAYS_PER_NORMAL_YEAR)

#define leap_tail(y,m)  ((is_leap_year((y))&&(m)==2)?1:0)

const int days_per_month[12+1] =
    {0,31,28,31,30,31,30,31,31,30,31,30,31};

#define days_of_this_month(y,m) (days_per_month[(m)]+leap_tail((y),(m)))

#define START_YEAR  2014
#define START_MONTH 4
#define START_DAY   2

typedef struct{int y,m,d;}  Date;

Date    date[MAX_DAYS];

int init(void)
{
    date[0] = {START_YEAR,START_MONTH,START_DAY};

    for(int i=1;i<MAX_DAYS;i++)
    {
        date[i] = date[i-1];
        
        int&    current_year = date[i].y;
        int&    current_month = date[i].m;
        int&    current_day = date[i].d;

        if( ++current_day > 
                days_of_this_month(current_year,current_month) )
        {
            current_day = 1;
            
            if( ++current_month > 12 )
            {
                current_month = 1;
                current_year++;
            }
        }
    }

    return  0;
}

int main(void)
{
    int N;

    init();
    
    scanf("%d",&N);
    printf("%04d-%02d-%02d\n",
                date[N-1].y,date[N-1].m,date[N-1].d);

    return  0;
}