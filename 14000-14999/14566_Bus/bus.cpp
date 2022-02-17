#include    <iostream>
#include    <queue>

using namespace std;

#define INF 0x7FFFFFFF

int main(void)
{
    int n,min_distance,cnt;
    priority_queue<int> stop;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int A;

        cin>>A;
        stop.push(A);
    }

    int prev_pos;

    prev_pos = stop.top();
    stop.pop();

    for(min_distance=INF;!stop.empty();stop.pop())
    {
        int current_pos = stop.top();
        int distance = prev_pos-current_pos;

        if( distance <= min_distance )
        {
            if( distance < min_distance )
            {
                cnt = 0;
            }

            min_distance = distance;
            cnt++;
        }

        prev_pos = current_pos;
    }

    cout<<min_distance<<' '<<cnt<<'\n';

    return  0;
}