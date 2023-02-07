#include    <iostream>
#include    <set>

using namespace std;

#define MAX_NUM_OF_USERS    (100000+1)

typedef pair<int,int>   Event;  // first:time,second:leave_time or -PC

static int  cnt[MAX_NUM_OF_USERS];

#define pop_head(s) ((s).erase((s).begin()))
#define is_event_to_return_pc(e)    ((e)<0)

int input(set<Event>& events,set<int>& available)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int P,Q;

        cin>>P>>Q;
        
        events.insert(make_pair(P,Q));
        available.insert(i);
    }
    
    return  0;
}

int print_num_of_users(int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<cnt[i]<<' ';
    }

    cout<<'\n';

    return  0;
}

int simulate(set<Event>& events,set<int>& available)
{
    int ret = 0;
    
    for(;!events.empty();pop_head(events))
    {
        int e = events.begin()->second;

        if( is_event_to_return_pc(e) )
        {
            available.insert(-e);
        }
        else
        {
            int new_pc = *(available.begin());
            int leave_time = e;

            events.insert(make_pair(e,-new_pc));
            pop_head(available);

            ret = max(ret,new_pc);
            cnt[new_pc]++;
        }
    }

    return  ret;    
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    set<Event>  events;
    set<int>    available;

    int num_of_used;

    input(events,available);
    num_of_used = simulate(events,available);

    cout<<num_of_used<<'\n';
    print_num_of_users(num_of_used);

    return  0;
}