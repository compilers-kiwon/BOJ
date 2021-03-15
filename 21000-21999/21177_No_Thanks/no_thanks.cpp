#include    <iostream>
#include    <queue>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,sum,h,current;
    priority_queue<int> pq;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int c;

        cin>>c;
        pq.push(-c);
    }

    h = current = -pq.top();
    pq.pop();
    
    for(sum=0;!pq.empty();pq.pop())
    {
        int next = -pq.top();

        if( current+1 != next )
        {
            sum += h;
            h = next;
        }

        current = next;
    }

    sum += h;
    cout<<sum<<'\n';

    return  0;
}