#include    <iostream>

using namespace std;

typedef struct{int y,m,d;}  Date;

#define ENDLESS_YEARS       1000
#define DAYS_OF_LEAP_YEAR   366
#define DAYS_OF_NORMAL_YEAR 365

#define FEBRUARY        2
#define include_today() 1

#define condition_of_normal_year() \
    ((year%4!=0)||((year%100==0)&&(year%400!=0)))

const int   days_of_month[12+1]
    = {0,31,28,31,30,31,30,31,31,30,31,30,31};

void    input(Date& from,Date& to)
{
    cin>>from.y>>from.m>>from.d;
    cin>>to.y>>to.m>>to.d;
}

bool    is_endless(const Date& from,const Date& to)
{
    if( to.y-from.y != ENDLESS_YEARS )
    {
        return  (to.y-from.y>ENDLESS_YEARS);
    }

    if( to.m != from.m )
    {
        return  (to.m>from.m);
    }

    return  (to.d>=from.d);
}

bool    is_leap_year(int year)
{
    return  !condition_of_normal_year();
}

int     get_head(const Date& date)
{
    int ret = date.d;

    for(int month=1;month<date.m;month++)
    {
        ret += days_of_month[month]+
            ((month==FEBRUARY&&is_leap_year(date.y))?1:0);
    }

    return  ret;
}

int     get_tail(const Date& date)
{
    int ahead_days = get_head(date);
    int days_of_this_year = (is_leap_year(date.y)?
                    DAYS_OF_LEAP_YEAR:DAYS_OF_NORMAL_YEAR);
    
    return  days_of_this_year-(ahead_days+include_today());
}

int     get_num_of_days(const Date& from,const Date& to)
{
    int ret = -(get_head(from)+get_tail(to)+include_today());
    
    for(int y=from.y;y<=to.y;y++)
    {
        ret += (is_leap_year(y)?
            DAYS_OF_LEAP_YEAR:DAYS_OF_NORMAL_YEAR);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Date    today,target_day;

    input(today,target_day);

    if( is_endless(today,target_day) == true )
    {
        cout<<"gg\n";
        return  0;
    }

    cout<<"D-"<<get_num_of_days(today,target_day)<<'\n';

    return  0;
}