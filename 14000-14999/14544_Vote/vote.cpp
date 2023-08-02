#include    <iostream>
#include    <string>
#include    <queue>
#include    <map>

using namespace std;

int input(map<string,int>& v)
{
    int n,m;

    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        string  name;

        cin>>name;
        v[name] = 0;
    }

    for(int i=1;i<=m;i++)
    {
        string  X,C;
        int     R;

        cin>>X>>R>>C;
        v[X] += R;
    }

    return  0;
}

int get_ranking(map<string,int>& v,
                priority_queue<pair<int,string>>& pq)
{
    map<string,int>::iterator   it;

    for(it=v.begin();it!=v.end();it++)
    {
        pq.push({it->second,it->first});
    }

    return  0;
}

int get_winner(int idx,priority_queue<pair<int,string>>& pq)
{
    if( pq.size() == 1 )
    {
        cout<<"VOTE "<<idx<<": THE WINNER IS "<<
                pq.top().second<<' '<<pq.top().first<<'\n';
        return  0;
    }

    pair<int,string>    first,second;

    first = pq.top();
    pq.pop();
    second = pq.top();

    if( first.first == second.first )
    {
        cout<<"VOTE "<<idx<<": THERE IS A DILEMMA\n";
    }
    else
    {
        cout<<"VOTE "<<idx<<": THE WINNER IS "<<
                first.second<<' '<<first.first<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int P;

    cin>>P;

    for(int i=1;i<=P;i++)
    {
        map<string,int> vote;
        priority_queue<pair<int,string>> rank;

        input(vote);
        get_ranking(vote,rank);
        get_winner(i,rank);
    }

    return  0;
}