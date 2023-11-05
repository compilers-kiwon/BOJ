#include    <iostream>
#include    <queue>

using namespace std;

static inline bool is_holiday(int d,queue<int>& h) {
    return  (!h.empty() && d==h.front());
}

int input(queue<int>& h)
{
    int N,K;

    cin>>N>>K;

    for (int i=1;i<=K;i++) {
        int d;
        cin>>d;
        h.push(d);
    }

    return  N;
}

int simulate(int n,queue<int>& h)
{
    int ret = 0;
    bool washed = false;

    for (int i=1;i<=n;i++) {
        if (!washed || is_holiday(i,h)) {
            ret++;
            washed = true;
            if (is_holiday(i,h)) h.pop();
        } else {
            washed = false;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_days;
    queue<int>  holidays;

    num_of_days = input(holidays);
    cout<<simulate(num_of_days,holidays)<<'\n';

    return  0;
}