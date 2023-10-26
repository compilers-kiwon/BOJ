#include    <iostream>
#include    <queue>

using namespace std;

typedef pair<int,int>   Customer;   // first: idx, second: time
typedef pair<int,int>   Event;      // first: -(time to be free), second: cashier 

const static int MAX_NUM_OF_CUSTOMERS = 1000+1;

static int n,c;
static int assigned[MAX_NUM_OF_CUSTOMERS];

int simulate(queue<Customer>& cq)
{
    priority_queue<int> cashier_q;
    priority_queue<Event> available_q;

    for (int i=1;i<=n;i++) {
        cashier_q.push(-i);
    }

    for (int t=0;!cq.empty();t++) {
        for(;!available_q.empty()&&
                t==(-available_q.top().first);) {
            cashier_q.push(-available_q.top().second);
            available_q.pop();
        }

        for(;!cashier_q.empty()&&!cq.empty();cashier_q.pop(),cq.pop()) {
            int cashier = -cashier_q.top();
            int customer_idx = cq.front().first;
            int required_time = cq.front().second;

            assigned[customer_idx] = cashier;
            available_q.push({-(t+required_time),cashier});
        }
    }

    return  0;
}

int input(queue<Customer>& cq)
{
    cin>>n>>c;

    for (int i=1;i<=c;i++) {
        int t;
        cin>>t;
        cq.push({i,t});
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<Customer> cq;

    input(cq);
    simulate(cq);

    for (int i=1;i<=c;i++) {
        cout<<assigned[i]<<(i==c?'\n':' ');
    }

    return  0;
}