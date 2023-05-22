#include    <iostream>
#include    <string>

using namespace std;

#define NUM_OF_ZONES    7

static string   name[NUM_OF_ZONES] = {
    "Ottawa","Victoria","Edmonton","Winnipeg",
    "Toronto","Halifax","St. John's"
};

static int  minute_offset[NUM_OF_ZONES] = {
    0,-180,-120,-60,0,60,90
};

#define MINUTES_PER_DAY (24*60)

#define get_current_minute(cur,offset) \
    (((cur)+MINUTES_PER_DAY+(offset))%MINUTES_PER_DAY)

#define get_hour(m)     ((m)/60)
#define get_minute(m)   ((m)%60)

#define convert_minutes(t)  (((t)/100*60)+((t)%100))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int time,minutes;

    cin>>time;
    minutes = convert_minutes(time);

    for(int i=0;i<NUM_OF_ZONES;i++)
    {
        int h,m,t;

        t = get_current_minute(minutes,minute_offset[i]);
        h = get_hour(t);
        m = get_minute(t);

        cout<<(h>0?to_string(h):"")
            <<(m<10?"0":"")<<m<<" in "<<name[i]<<'\n';
    }

    return  0;
}