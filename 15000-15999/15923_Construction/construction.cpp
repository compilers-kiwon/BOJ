#include    <iostream>
#include    <vector>
#include    <cmath>

using namespace std;

typedef pair<int,int>   Pos;    // first:x,second:y

#define get_length(p1,p2) \
    (abs((p1).first-(p2).first)+abs((p1).second-(p2).second))

int input(vector<Pos>& p)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int x,y;

        cin>>x>>y;
        p.push_back(make_pair(x,y));
    }

    return  0;
}

int calculate(const vector<Pos>& p)
{
    int ret = 0;

    for(int i=0;i<p.size();i++)
    {
        ret += get_length(p[i],p[(i+1)%p.size()]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> p;

    input(p);
    cout<<calculate(p)<<'\n';

    return  0;
}