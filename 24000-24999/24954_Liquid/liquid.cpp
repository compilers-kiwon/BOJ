#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (10+1)
#define MIN_COST    1
#define INF         0x7FFFFFFF

typedef pair<int,int>   Discount;

static int  N,c[MAX_SIZE];
static vector<Discount> discount[MAX_SIZE];

int simulate(const vector<int>& order)
{
    int ret = 0;
    int discounted_price[MAX_SIZE] = {0,};

    for(int i=0;i<order.size();i++)
    {
        int p = order[i];

        ret += max(MIN_COST,c[p]-discounted_price[p]);
        
        for(int j=0;j<discount[p].size();j++)
        {
            int&    d_product = discount[p][j].first;
            int&    d_cost = discount[p][j].second;

            discounted_price[d_product] += d_cost;
        }
    }

    return  ret;
}

int get_min_cost(void)
{
    int ret = INF;
    vector<int> order;

    for(int i=1;i<=N;i++)
    {
        order.push_back(i);
    }

    do{
        ret = min(ret,simulate(order));
    }while(next_permutation(order.begin(),order.end()));

    return  ret;
}

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>c[i];
    }

    for(int i=1;i<=N;i++)
    {
        int p;

        cin>>p;

        for(int j=1;j<=p;j++)
        {
            int a,d;

            cin>>a>>d;
            discount[i].push_back(make_pair(a,d));
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_min_cost()<<'\n';

    return  0;
}