#include    <iostream>
#include    <string>
#include    <queue>

using namespace std;

#define MAX_NUM_OF_PASSENGERS   (10000+1)
#define SHIP_ARRIVAL_EVENT      MAX_NUM_OF_PASSENGERS

#define LEFT    0
#define RIGHT   1
#define MAX_DIR 2
#define CROSS   3

#define other_side(s)   (((s)+1)%MAX_DIR)

typedef pair<int,pair<int,int>>  Event;  // first:-time,second:<first:type,second:side>

static int  N,t,M,arrival_time[MAX_NUM_OF_PASSENGERS];
static priority_queue<Event>    evt_q;

#define file_ship_arrival_event(time,arrival_pos,ship_state) \
    {evt_q.push({-(time),{-SHIP_ARRIVAL_EVENT,(arrival_pos)}});(ship_state)=CROSS;}

int input(void)
{
    cin>>M>>t>>N;

    for(int i=1;i<=N;i++)
    {
        int     time;
        string  side;

        cin>>time>>side;
        evt_q.push({-time,{-i,(side=="left")?LEFT:RIGHT}});
    }

    return  0;
}

int get_off_ship(queue<int>& s,int time)
{
    for(;!s.empty();s.pop())
    {
        arrival_time[s.front()] = time;
    }

    return  0;
}

int get_on_ship(queue<int>& w,queue<int>& s)
{
    for(;!w.empty()&&s.size()!=M;w.pop())
    {
        s.push(w.front());
    }

    return  0;
}

int simulate(void)
{
    int         ship_pos;
    queue<int>  ship,waiting[MAX_DIR];

    file_ship_arrival_event(0,LEFT,ship_pos);

    for(;!evt_q.empty();)
    {
        int event_time = -evt_q.top().first;
        int event_type = -evt_q.top().second.first;
        int event_pos = evt_q.top().second.second;

        evt_q.pop();

        if( event_type == SHIP_ARRIVAL_EVENT )
        {
            ship_pos = event_pos;

            get_off_ship(ship,event_time);
            get_on_ship(waiting[ship_pos],ship);

            if( !ship.empty() || !waiting[other_side(ship_pos)].empty() )
            {
                file_ship_arrival_event(event_time+t,other_side(ship_pos),ship_pos);
            }
        }
        else
        {
            for(waiting[event_pos].push(event_type);!evt_q.empty();evt_q.pop())
            {
                int concurrent_event_time = -evt_q.top().first;
                int concurrent_event_type = -evt_q.top().second.first;
                int concurrent_event_pos = evt_q.top().second.second;

                if( concurrent_event_time != event_time ||
                        concurrent_event_type == SHIP_ARRIVAL_EVENT )
                {
                    break;
                }

                waiting[concurrent_event_pos].push(concurrent_event_type);
            }

            if( ship_pos != CROSS )
            {
                get_on_ship(waiting[ship_pos],ship);
                file_ship_arrival_event(event_time+t,other_side(ship_pos),ship_pos);
            }
        }
    }

    return  0;
}

int print(void)
{
    for(int i=1;i<=N;i++)
    {
        cout<<arrival_time[i]<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();

    return  0;
}