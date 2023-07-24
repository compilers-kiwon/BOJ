#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_NUM 2000

typedef pair<int,int>   State;  // first:-appearance, second:value

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cnt[MAX_NUM+1];

    cin>>N;
    fill(&cnt[1],&cnt[MAX_NUM+1],0);

    for(int i=1;i<=N;i++)
    {
        int A;

        cin>>A;
        cnt[A]++;
    }

    priority_queue<State>   pq;

    for(int i=1;i<=MAX_NUM;i++)
    {
        if(cnt[i]==0) continue;
        pq.push({-cnt[i],-i});
    }

    cout<<-pq.top().second<<'\n';
    return  0;
}