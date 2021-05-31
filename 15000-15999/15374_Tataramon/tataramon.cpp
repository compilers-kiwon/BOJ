#include    <iostream>
#include    <algorithm>
#include    <vector>
#include    <map>

using namespace std;

#define MAX_CAPTURED    2

typedef pair<int,int>       Tataramon;  // first:order, second:id
typedef vector<Tataramon>   Capture;
typedef vector<int>         Candidate;

void    input(map<int,Candidate>& m)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int A;

        cin>>A;

        if( m[-A].size() < MAX_CAPTURED )
        {
            m[-A].push_back(i);
        }
    }
}

void    put_mon_into_ball(map<int,Candidate>& m,vector<Tataramon>& ball)
{
    map<int,Candidate>::iterator  it;

    for(it=m.begin();it!=m.end();it++)
    {
        int         id = -(it->first);
        Candidate&  order = it->second;

        for(int i=0;i<order.size();i++)
        {
            ball.push_back(make_pair(order[i],id));
        }
    }

    sort(ball.begin(),ball.end());
}

void    print(const vector<Tataramon>& ball)
{
    for(int i=0;i<ball.size();i++)
    {
        cout<<ball[i].second<<' ';
    }
    cout<<'\n';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        map<int,Candidate>  mon;
        vector<Tataramon>   ball;

        input(mon);
        put_mon_into_ball(mon,ball);
        print(ball);
    }

    return  0;
}