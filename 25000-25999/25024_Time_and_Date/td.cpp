#include    <iostream>
#include    <string>

using namespace std;

const static int num_of_days[12+1] =
    {0,31,29,31,30,31,30,31,31,30,31,30,31};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define is_hour(n)      IN_RANGE(0,(n),23)
#define is_minute(n)    IN_RANGE(0,(n),59)
#define is_month(n)     IN_RANGE(1,(n),12)
#define is_day(m,n)     IN_RANGE(1,(n),num_of_days[(m)])

string  is_time(const string& x,const string& y)
{
    int h = stoi(x);
    int m = stoi(y);

    return  ((is_hour(h)&&is_minute(m))?"Yes":"No");
}

string  is_date(const string& x,const string& y)
{
    int m = stoi(x);
    int d = stoi(y);

    return  ((is_month(m)&&is_day(m,d))?"Yes":"No");
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        string  x,y;

        cin>>x>>y;

        cout<<is_time(x,y)<<' ';
        cout<<is_date(x,y)<<'\n';
    }

    return  0;
}