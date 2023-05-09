#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define NONE    "-"
#define TRUE    1
#define FALSE   0

#define INF         0x7FFFFFFF
#define MAX_DIFF    12

#define DAYS_PER_WEEK       7
#define NUM_OF_TIME_ZONE    4

const static int time_zone[NUM_OF_TIME_ZONE+1] = {0,4,6,4,10};

static map<string,int>  time_table;

int input(void)
{
    int N;

    cin>>N;

    for(int w=1;w<=N;w++)
    {
        for(int t=1;t<=NUM_OF_TIME_ZONE;t++)
        {
            for(int d=1;d<=DAYS_PER_WEEK;d++)
            {
                string  name;

                cin>>name;

                if( name != NONE )
                {
                    time_table[name] += time_zone[t];
                }
            }
        }
    }

    return  0;
}

int compare_worktime(void)
{
    int min_time = INF;
    int max_time = 0;

    map<string,int>::iterator   it;

    for(it=time_table.begin();it!=time_table.end();it++)
    {
        min_time = min(min_time,it->second);
        max_time = max(max_time,it->second);
    }

    return  (max_time-min_time)<=MAX_DIFF?TRUE:FALSE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<(compare_worktime()?"Yes":"No")<<'\n';

    return  0;
}