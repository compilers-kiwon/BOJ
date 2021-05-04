#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

int n;

typedef pair<int,int>   Town;   // first:num_of_required_connection,second:idx

priority_queue<Town>    pq;

void    input(void)
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int d;

        cin>>d;
        pq.push(make_pair(d,i));
    }
}

void    design_connection(void)
{
    for(;!pq.empty();)
    {
        Town            s;
        vector<Town>    t;

        s = pq.top();
        pq.pop();

        for(int i=1;i<=s.first;i++)
        {
            t.push_back(pq.top());
            pq.pop();
        }

        for(int i=0;i<t.size();i++)
        {
            cout<<s.second<<' '<<t[i].second<<'\n';

            if( --t[i].first != 0 )
            {
                pq.push(t[i]);
            }
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    design_connection();

    return  0;
}