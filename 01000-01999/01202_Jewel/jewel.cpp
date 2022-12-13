#include    <iostream>
#include    <queue>

using namespace std;

typedef pair<int,int>   Jewel;  // first:-weight,second:value
typedef long long int   int64;

priority_queue<Jewel>   jewel_q;
priority_queue<int>     bag_q,candidate_q;

void    input(void)
{
    int N,K;

    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        int M,V;

        cin>>M>>V;
        jewel_q.push(make_pair(-M,V));
    }

    for(int i=1;i<=K;i++)
    {
        int C;

        cin>>C;
        bag_q.push(-C);
    }
}

int64   simulate(void)
{
    int64   ret = 0;

    for(;!bag_q.empty();bag_q.pop())
    {
        int current_bag = -bag_q.top();

        for(;!jewel_q.empty();jewel_q.pop())
        {
            int weight = -jewel_q.top().first;
            int value = jewel_q.top().second;

            if( weight > current_bag )
            {
                break;
            }

            candidate_q.push(value);
        }

        if( !candidate_q.empty() )
        {
            ret += (int64)(candidate_q.top());
            candidate_q.pop();
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}