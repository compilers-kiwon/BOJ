#include    <iostream>
#include    <queue>

using namespace std;

#define NUM_OF_BILL_KINDS   6

const static int bill[NUM_OF_BILL_KINDS] = {1,5,10,20,50,100};

typedef pair<int,pair<int,int>> State;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<State>   pq;

    for(int i=0;i<NUM_OF_BILL_KINDS;i++)
    {
        int n;

        cin>>n;
        pq.push({n*bill[i],{-n,bill[i]}});
    }

    cout<<pq.top().second.second<<'\n';
    return  0;
}