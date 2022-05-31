#include    <iostream>
#include    <cmath>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,prev_x,prev_y,sum;

    cin>>N>>prev_x>>prev_y;
    sum = 0;

    for(int i=2;i<=N;i++)
    {
        int x,y;

        cin>>x>>y;
        sum += abs(prev_x-x)+abs(prev_y-y);
        
        prev_x = x;
        prev_y = y;
    }

    cout<<sum<<'\n';

    return  0;
}