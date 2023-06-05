#include    <iostream>
#include    <climits>

using namespace std;

typedef long long int   int64;

int64   get_cost(int64 price,int64 time,int64 cost,int64 total)
{
    int64   T = (total-1)/time;
    return  price+cost*T*(T+1)/2;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,min_product;
    int64   Q,min_cost;

    cin>>N>>Q;
    min_cost = LLONG_MAX;

    for(int i=1;i<=N;i++)
    {
        int64   P,K,C,cur_cost;

        cin>>P>>K>>C;
        cur_cost = get_cost(P,K,C,Q);

        if( cur_cost < min_cost )
        {
            min_product = i;
            min_cost = cur_cost;
        }
    }

    cout<<min_product<<' '<<min_cost<<'\n';
    return  0;
}