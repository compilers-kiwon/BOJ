#include    <iostream>
#include    <queue>

using namespace std;

typedef long long int   int64;
typedef pair<int,pair<int,int>> Light;

static int64    n;
static priority_queue<Light> pq;

enum {GREEN=0,RED=1,MAX_COLOR=2};

inline static int64 get_light_color(int64 cur_time,
                        int64 light_start_time,int64 light_period_time)
{
    return  ((cur_time-light_start_time)/light_period_time)%MAX_COLOR;
}

inline static int64 get_waiting_time(int64 cur_time,
                        int64 light_start_time,int64 light_period_time)
{
    return  light_period_time-((cur_time-light_start_time)%light_period_time);
}

int input(void)
{
    int k;

    cin>>n>>k;

    for (int i=1;i<=k;i++) {
        int64   x,t,s;

        cin>>x>>t>>s;
        pq.push({-x,{t,s}});
    }

    return  0;
}

int64   simulate(void)
{
    int64   cur_pos,cur_time;

    for(cur_pos=cur_time=0;!pq.empty();pq.pop()) {
        int64   light_pos = -pq.top().first;
        int64   light_period = pq.top().second.first;
        int64   light_start = pq.top().second.second;

        cur_time += light_pos-cur_pos;
        cur_pos = light_pos;
        
        if (cur_time < light_start) {
            cur_time = light_start;
            continue;
        }

        int64   light_color = get_light_color(cur_time,light_start,light_period);
        int64   waiting_time = get_waiting_time(cur_time,light_start,light_period);
        
        if (light_color == RED) cur_time += waiting_time;
    }

    return  cur_time+(n-cur_pos);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}