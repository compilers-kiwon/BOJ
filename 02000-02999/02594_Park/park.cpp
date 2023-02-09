#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define START_TIME  1000
#define END_TIME    2200

typedef pair<int,int>   Time;

#define get_minutes(t)  (((t)/100)*60+((t)%100))

#define EXTRA_WORK_MINUTE   10

#define get_rest_time(t1,t2)    ((t1)-(t2))

int input(vector<Time>& t)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int s,e;

        cin>>s>>e;
        t.push_back(make_pair(get_minutes(s)-EXTRA_WORK_MINUTE,
            min(get_minutes(e)+EXTRA_WORK_MINUTE,get_minutes(END_TIME))));
    }

    sort(t.begin(),t.end());

    return  0;
}

int simulate(const vector<Time>& t)
{
    int ret = 0;
    int prev_end_time = get_minutes(START_TIME);

    for(int i=0;i<t.size()&&prev_end_time<get_minutes(END_TIME);i++)
    {
        int start_time = t[i].first;
        int end_time = t[i].second;
        
        ret = max(ret,get_rest_time(start_time,prev_end_time));
        prev_end_time = max(prev_end_time,end_time);
    }

    ret = max(ret,get_rest_time(get_minutes(END_TIME),prev_end_time));

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Time>    work_time;

    input(work_time);
    cout<<simulate(work_time)<<'\n';

    return  0;
}