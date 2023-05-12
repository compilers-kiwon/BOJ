#include    <iostream>
#include    <string>

using namespace std;

#define MAX_NUM_OF_WORKERS  (50+1)
#define TOTAL_MINUTES       (24*60)
#define UTC_LEN             3

#define get_minute(m,offset)    (((m)+(offset))%TOTAL_MINUTES)

static int  N,meeting_time,offset[MAX_NUM_OF_WORKERS];

int parse(string str)
{
    int sign = (str.front()=='+')?1:-1;
    int hour,minute;

    if( str.find('.') == string::npos )
    {
        hour = stoi(str.substr(1));
        minute = 0;
    }
    else
    {
        hour = stoi(str.substr(1,str.find('.')-1));
        minute = 30;
    }

    return  get_minute(TOTAL_MINUTES,sign*(hour*60+minute));
}

int input(void)
{
    string  str;
    int     h,m,u;

    cin>>N>>str;
    sscanf(str.c_str(),"%d:%d",&h,&m);

    cin>>str;
    u = parse(str.substr(UTC_LEN));

    meeting_time = get_minute(h*60+m,TOTAL_MINUTES-u);

    for(int i=1;i<=N;i++)
    {
        cin>>str;
        offset[i] = parse(str.substr(UTC_LEN));
    }

    return  0;
}

int convert_utc_time(void)
{
    for(int i=1;i<=N;i++)
    {
        int m = get_minute(meeting_time,offset[i]);
        printf("%02d:%02d\n",m/60,m%60);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    convert_utc_time();

    return  0;
}