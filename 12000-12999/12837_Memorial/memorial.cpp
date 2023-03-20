#include    <iostream>
#include    <queue>

using namespace std;

static queue<int>   q;

typedef long long int   int64;

#define cube(n) ((n)*(n)*(n))

int input(void)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        q.push(i);
    }

    return  0;
}

int simulate(void)
{
    for(int64 step=1;q.size()!=1;step++)
    {
        for(int64 t=1,size=q.size(),t3=cube(step)-1;t<=(t3%size);t++)
        {
            q.push(q.front());q.pop();
        }

        q.pop();
    }

    return  q.front();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}