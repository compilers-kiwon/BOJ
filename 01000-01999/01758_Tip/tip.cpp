#include    <iostream>
#include    <queue>

using namespace std;

typedef long long int   int64;

void input(priority_queue<int64>& pq)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++) {
        int64 t;
        cin>>t;
        pq.push(t);
    }
}

int64 simulate(priority_queue<int64>& pq)
{
    int64 ret = 0;

    for (int64 i=0;!pq.empty();i++,pq.pop()) {
        ret += max(0LL,pq.top()-i);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    priority_queue<int64> pq;

    input(pq);
    cout<<simulate(pq)<<'\n';
    return  0;
}