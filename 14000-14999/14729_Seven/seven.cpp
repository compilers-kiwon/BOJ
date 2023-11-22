#include    <iostream>
#include    <queue>

using namespace std;

const static int NUM_OF_LOW_SCORE = 7;

typedef pair<int,int>   Number;

int main(void)
{
    int N;
    priority_queue<Number> pq;

    scanf("%d",&N);

    for (int i=1;i<=NUM_OF_LOW_SCORE;i++) {
        Number n;
        scanf("%d.%d",&n.first,&n.second);
        pq.push(n);
    }

    for (int i=NUM_OF_LOW_SCORE+1;i<=N;i++) {
        Number n;
        scanf("%d.%d",&n.first,&n.second);
        
        if (n > pq.top()) continue;
        pq.pop();pq.push(n);
    }

    Number  buf[NUM_OF_LOW_SCORE+1];

    for (int i=NUM_OF_LOW_SCORE;i>=1;i--,pq.pop()) {
        buf[i] = pq.top();
    }

    for (int i=1;i<=NUM_OF_LOW_SCORE;i++) {
        printf("%d.%03d\n",buf[i].first,buf[i].second);
    }

    return  0;
}