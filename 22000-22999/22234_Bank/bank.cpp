#include    <iostream>
#include    <queue>

using namespace std;

typedef pair<int,int>   Customer;

static queue<Customer>  wait;
static priority_queue<pair<int,Customer>>    arrival;

#define get_arrival_time(pq)    (-(pq).top().first)
#define get_customer_info(pq)   ((pq).top().second)
#define get_service_time(t1,t2) ((t1)-(t2))

#define handle_customer_request(c)  ((c).second--)
#define finish_customer_request(c)  ((c).second==0)

#define take_new_customer(q,c)          {(q).pop();(c)=(q).front();}
#define return_customer_to_wait(q,c)    ((q).push((c)))

int input(int& working_time)
{
    int N,T,W,M;

    cin>>N>>T>>W;

    for(int i=1;i<=N;i++)
    {
        Customer    c;

        cin>>c.first>>c.second;
        wait.push(c);
    }

    cin>>M;

    for(int i=1;i<=M;i++)
    {
        int P,t,c;

        cin>>P>>t>>c;
        arrival.push({-c,{P,t}});
    }

    working_time = W;
    return  T;
}

int arriving_customer(int current_time)
{
    if( get_arrival_time(arrival) == current_time )
    {
        wait.push(get_customer_info(arrival));
        arrival.pop();
    }

    return  0;
}

int simulate(int time_to_process,int time_to_simulate)
{
    int         i;
    Customer    current;

    for(i=0,current=wait.front();i<time_to_simulate;i++)
    {
        arriving_customer(i+1);
        handle_customer_request(current);

        cout<<current.first<<'\n';

        if( finish_customer_request(current) )
        {
            take_new_customer(wait,current);
            continue;
        }

        if( get_service_time(wait.front().second,current.second) == time_to_process )
        {
            return_customer_to_wait(wait,current);
            take_new_customer(wait,current);
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int time_to_process,time_to_simulate;

    time_to_process = input(time_to_simulate);
    simulate(time_to_process,time_to_simulate);

    return  0;
}