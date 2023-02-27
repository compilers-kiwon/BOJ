#include    <iostream>

using namespace std;

#define INF 0x7FFFFFFF;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,prev_min,max_profit;

    cin>>N;
    prev_min = INF;
    max_profit = 0;

    for(int i=1;i<=N;i++)
    {
        int a;

        cin>>a;

        prev_min = min(prev_min,a);
        max_profit = max(max_profit,a-prev_min);
    }

    cout<<max_profit<<'\n';
    
    return  0;
}