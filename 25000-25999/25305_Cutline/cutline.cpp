#include    <iostream>
#include    <queue>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,k;

    cin>>N>>k;

    priority_queue<int> pq;

    for(int i=1;i<=N;i++)
    {
        int x;

        cin>>x;
        pq.push(x);
    }

    for(int i=1;i<k;i++)
    {
        pq.pop();
    }

    cout<<pq.top()<<'\n';

    return  0;
}