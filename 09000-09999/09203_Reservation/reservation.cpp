#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

const static int START_YEAR = 2013;
const static int LEAPYEAR = 2016;
const static int LEAPMONTH = 2;
const static int DAYS_PER_YEAR = 365;
const static int MINUTES_PER_HOUR = 60;
const static int MINUTES_PER_DAY = 24*60;
const static int DAYS_PER_MONTH[12+1] =
    {0,31,28,31,30,31,30,31,31,30,31,30,31};

const static int OCCPIED = 1;
const static int RELEASED = -1;

typedef pair<int,int> Event;    // first:-time, second:occupied(+1) or released(-1)

int convert_days_to_minutes(int y,int m,int d)
{
    int num_of_days = 0;

    for (int i=START_YEAR;i<y;i++) {
        num_of_days += DAYS_PER_YEAR;
    }

    for (int i=1;i<m;i++) {
        num_of_days += 
            DAYS_PER_MONTH[i]+((i==LEAPMONTH&&y==LEAPYEAR)?1:0);
    }

    return  ((num_of_days+d-1)*MINUTES_PER_DAY);
}

int get_minutes(const string& d,const string& t)
{
    int year,month,day,hour,minute;

    sscanf(d.c_str(),"%d-%d-%d",&year,&month,&day);
    sscanf(t.c_str(),"%d:%d",&hour,&minute);
    
    return  (hour*MINUTES_PER_HOUR+minute+
                convert_days_to_minutes(year,month,day));
}

void input(vector<Event>& e)
{
    int B,C;

    cin>>B>>C;

    for (int i=1;i<=B;i++) {
        string code;
        string checkin_day,checkin_time;
        string checkout_day,checkout_time;

        cin>>code>>checkin_day>>
            checkin_time>>checkout_day>>checkout_time;
        
        int in_minutes,out_minutes;

        in_minutes = get_minutes(checkin_day,checkin_time);
        out_minutes = get_minutes(checkout_day,checkout_time);

        e.push_back({in_minutes,OCCPIED});
        e.push_back({out_minutes+C,RELEASED});
    }

    sort(e.begin(),e.end());
}

int simulate(const vector<Event>& e)
{
    int cur,ret;

    cur = ret = 0;

    for (int i=0;i<e.size();i++) {
        cur += e[i].second;
        ret = max(ret,cur);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        vector<Event>   e;

        input(e);
        cout<<simulate(e)<<'\n';
    }

    return  0;
}