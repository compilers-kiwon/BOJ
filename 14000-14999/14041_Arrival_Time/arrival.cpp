#include    <iostream>

using namespace std;

#define convert_time_to_minutes(h,m)    ((h)*60+(m))
#define distance_for_attendance         (2*120)

#define step_of_normal_time 2
#define step_of_rush_hour   1

#define MAX_RUSH_HOUR   2

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

#define get_hour(m)     (((m)/60)%24)
#define get_minutes(m)  ((m)%60)

const struct{
    int h1,m1,h2,m2;
} rush_hour_info[MAX_RUSH_HOUR] = {{7,0,10,0},{15,0,19,0}};

bool    is_rush_hour(int current_min,int idx_of_ruch_hour)
{
    int start_hour = rush_hour_info[idx_of_ruch_hour].h1;
    int strat_min = rush_hour_info[idx_of_ruch_hour].m1;

    int end_hour = rush_hour_info[idx_of_ruch_hour].h2;
    int end_min = rush_hour_info[idx_of_ruch_hour].m2;

    int start_of_rush_hour = convert_time_to_minutes(start_hour,strat_min);
    int end_of_rush_hour = convert_time_to_minutes(end_hour,end_min);

    return  IN_RANGE(start_of_rush_hour,current_min,end_of_rush_hour);
}

int     main(void)
{
    int h,m,current;

    scanf("%d:%d",&h,&m);
    current = convert_time_to_minutes(h,m);

    for(int d=0;d<distance_for_attendance;)
    {
        bool    result = false;

        for(int j=0;j<MAX_RUSH_HOUR;j++)
        {
            if( is_rush_hour(current,j) == true )
            {
                result = true;
                break;
            }
        }

        d += (result?step_of_rush_hour:step_of_normal_time);
        current++;
    }

    printf("%02d:%02d",get_hour(current),get_minutes(current));

    return  0;
}