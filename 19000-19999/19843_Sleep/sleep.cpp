#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

static map<string,int> time_table = {
    {"Mon",0},{"Tue",24},{"Wed",48},{"Thu",72},{"Fri",96}
};

#define get_time(d,h)   (time_table[(d)]+h)

int get_slept_time(int num_of_sleeps)
{
    int ret = 0;

    for(int i=1;i<=num_of_sleeps;i++)
    {
        string  D1,D2;
        int     H1,H2;

        cin>>D1>>H1>>D2>>H2;
        ret += get_time(D2,H2)-get_time(D1,H1);
    }

    return  ret;
}

int simulate(int required_time,int num_of_sleeps)
{
    int ret = required_time-get_slept_time(num_of_sleeps);

    ret = (ret<=0)?0:(ret>48)?-1:ret;
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T,N;

    cin>>T>>N;
    cout<<simulate(T,N)<<'\n';

    return  0;
}