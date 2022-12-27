#include    <iostream>
#include    <vector>

using namespace std;

typedef pair<int,int>   Purchase;

void    input(int& X,vector<Purchase>& p)
{
    int N;

    cin>>X>>N;

    for(int i=1;i<=N;i++)
    {
        int a,b;

        cin>>a>>b;
        p.push_back(make_pair(a,b));
    }
}

int     calculate(const vector<Purchase>& p)
{
    int ret = 0;

    for(int i=0;i<p.size();i++)
    {
        ret += p[i].first*p[i].second;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int                 total_price;
    vector<Purchase>    items;

    input(total_price,items);
    cout<<(total_price==calculate(items)?"Yes\n":"No\n");

    return  0;
}