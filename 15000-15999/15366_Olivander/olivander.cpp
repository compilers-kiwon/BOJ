#include    <iostream>
#include    <queue>

using namespace std;

#define TRUE    1
#define FALSE   0

typedef priority_queue<int> pq;

int input(pq& w,pq& b)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int X;

        cin>>X;
        w.push(X);
    }

    for(int i=1;i<=N;i++)
    {
        int Y;

        cin>>Y;
        b.push(Y);
    }

    return  0;
}

int simulate(pq& w,pq& b)
{
    for(;!w.empty()&&!b.empty();w.pop(),b.pop())
    {
        if(w.top()>b.top()) return FALSE;
    }

    return  TRUE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    pq  wand,box;

    input(wand,box);
    cout<<(simulate(wand,box)?"DA":"NE")<<'\n';

    return  0;
}