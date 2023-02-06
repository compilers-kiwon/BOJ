#include    <iostream>
#include    <string>

using namespace std;

#define MAX_LEN 20
#define SCALER  100.0

#define SECONDS_PER_MINUTE  60.0
#define MINUTES_PER_HOUR    60.0
#define HOURS_PER_DAY       24.0

const double days_per_month[12+1] =
    {0.0,31.0,28.0,31.0,30.0,31.0,
        30.0,31.0,31.0,30.0,31.0,30.0,31.0};

const string month[12+1] =
    {"","January","February","March","April","May","June",
        "July","August","September","October","November","December"};

#define is_leaf_year(y) \
    ((y)%400==0||((y)%4==0&&(y)%100!=0))

#define days2seconds(days) \
    ((days)*HOURS_PER_DAY*MINUTES_PER_HOUR*SECONDS_PER_MINUTE)

double  get_seconds_per_year(int y)
{
    return  (is_leaf_year(y)?days2seconds(366.0):days2seconds(365.0));
}

double  get_current_seconds(int y,string mon,
                                int d,int h,int m)
{
    double  ret;
    double  num_of_days = 0.0;

    for(int i=1;i<=12&&mon!=month[i];i++)
    {
        num_of_days += days_per_month[i];

        if( i==2 && is_leaf_year(y) )
        {
            num_of_days += 1.0;
        }
    }

    num_of_days += (double)(d-1);
    ret = days2seconds(num_of_days);

    for(int i=0;i!=h;i++)
    {
        ret += MINUTES_PER_HOUR*SECONDS_PER_MINUTE;
    }

    for(int i=0;i!=m;i++)
    {
        ret += SECONDS_PER_MINUTE;
    }

    return  ret;
}

double  calculate_progress(double total,double current)
{
    return  current*SCALER/total;
}

int     main(void)
{
    int     y,d,h,m;
    char    mon[MAX_LEN];

    scanf("%s %d, %d %d:%d",mon,&d,&y,&h,&m);
    printf("%.9f\n",calculate_progress(get_seconds_per_year(y),
                        get_current_seconds(y,string(mon),d,h,m)));
    
    return  0;
}