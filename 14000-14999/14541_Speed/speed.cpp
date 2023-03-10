#include    <iostream>
#include    <vector>

using namespace std;

#define TRUE    1
#define FALSE   0

int input(vector<int>& speed,vector<int>& time)
{
    int n;

    cin>>n;

    if( n == -1 )
    {
        return  FALSE;
    }

    int prev_time = 0;

    for(int i=1;i<=n;i++)
    {
        int s,t;

        cin>>s>>t;

        speed.push_back(s);
        time.push_back(t-prev_time);

        prev_time = t;
    }

    return  TRUE;
}

int get_total_distance(vector<int>& speed,vector<int>& time)
{
    int ret = 0;

    for(int i=0;i<speed.size();i++)
    {
        ret += speed[i]*time[i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        vector<int> speed,time;

        if( input(speed,time) == FALSE )
        {
            break;
        }

        cout<<get_total_distance(speed,time)<<" miles\n";
    }

    return  0;
}