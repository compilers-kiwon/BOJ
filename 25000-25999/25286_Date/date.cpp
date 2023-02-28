#include    <iostream>

using namespace std;

const int last_day[12+1] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

#define is_leap_year(y) (((y)%400)==0||((y)%100!=0&&(y)%4==0))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int y,m;

        cin>>y>>m;
        (m==1)?y--,m=12:m--;

        cout<<y<<' '<<m<<' '<<last_day[m]+(m==2&&is_leap_year(y)?1:0)<<'\n';
    }

    return  0;
}