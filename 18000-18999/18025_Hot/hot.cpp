#include    <iostream>

using namespace std;

#define INF             (0x7FFFFFFF)
#define MAX_NUM_OF_DAYS (50+1)

int input(int t[])
{
    int n;

    cin>>n;
    for (int i=1;i<=n;i++) cin>>t[i];
    t[n+1] = t[n+2] = INF;

    return  n;
}

int get_start_day(int n,int t[],int& min_temp)
{
    int ret;

    min_temp = INF;

    for (int i=1;i<=n;i++) {
        if (max(t[i],t[i+2]) < min_temp) {
            ret = i;
            min_temp = max(t[i],t[i+2]);
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_days,t[MAX_NUM_OF_DAYS+2];
    int start_day,min_temperature;

    num_of_days = input(t);
    start_day = get_start_day(num_of_days,t,min_temperature);

    cout<<start_day<<' '<<min_temperature<<'\n';
    return  0;
}