#include    <iostream>
#include    <queue>

using namespace std;

int input(priority_queue<int>& pq,
            queue<int>& wq,queue<int>& vq)
{
    int N,M;

    cin>>N>>M;

    for (int i=1;i<=N;i++) {
        int a;

        cin>>a;
        
        if (i <= M) {
            pq.push(-a);
        } else {
            wq.push(-a);
        }
    }

    for (int i=1;i<=N-M+1;i++) {
        int v;

        cin>>v;
        vq.push(v);
    }
    
    return  0;
}

int simulate(priority_queue<int>& pq,
                queue<int>& wq,queue<int>& vq)
{
    for (;!vq.empty();vq.pop()) {
        int v = vq.front();
        queue<int>  buffer;
        
        for (int i=1;i<v;i++) {
            buffer.push(pq.top());
            pq.pop();
        }
        
        for (pq.pop();!buffer.empty();buffer.pop()) {
            pq.push(buffer.front());
        }

        if (!wq.empty()) {
            pq.push(wq.front());
            wq.pop();
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int> pq;
    queue<int>  wq,vq;

    input(pq,wq,vq);
    simulate(pq,wq,vq);

    for (;!pq.empty();pq.pop()) {
        cout<<-pq.top()<<' ';
    }

    cout<<'\n';
    return  0;
}