#include    <iostream>

using namespace std;

#define SEC_PER_DAY             (24*60*60)
#define convert_to_sec(h,m,s)   ((h)*3600+(m)*60+(s))

#define get_seconds(s)  ((s)%60)
#define get_minutes(s)  (((s)/60)%60)
#define get_hours(s)    ((s)/3600)

int get_current_seconds(int h,int m,int s)
{
    return  convert_to_sec(h,m,s);
}

int read_watch(void)
{
    int h,s,m;

    cin>>h>>m>>s;

    return  get_current_seconds(h,m,s);
}

int print_watch(int sec)
{
    int s = get_seconds(sec);
    int m = get_minutes(sec);
    int h = get_hours(sec);

    cout<<h<<' '<<m<<' '<<s<<'\n';

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int current_seconds = read_watch();
    int q;

    cin>>q;

    for(int i=1;i<=q;i++)
    {
        int T,c;

        cin>>T;

        switch(T)
        {
            case    1:
            case    2:
                cin>>c;
                current_seconds += (T==1)?c%SEC_PER_DAY:
                                    (SEC_PER_DAY-(c%SEC_PER_DAY));
                current_seconds %= SEC_PER_DAY;
                break;
            case    3:
                print_watch(current_seconds);
                break;
            default:
                // do nothing
                break;
        }
    }

    return  0;
}