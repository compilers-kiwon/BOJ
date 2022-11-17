#include    <iostream>
#include    <string>
#include    <vector>
#include    <queue>
#include    <map>
#include    <set>

using namespace std;

#define START               "Baba"
#define is_included(s,e)    ((s).find(e)!=(s).end())

void    input(map<string,vector<string>>& op)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  p,is,q;

        cin>>p>>is>>q;
        op[p].push_back(q);
    }
}

void    run(map<string,vector<string>>& op,set<string>& converted)
{
    queue<string>   q;

    for(q.push(START);!q.empty();q.pop())
    {
        string          current = q.front();
        vector<string>& adj = op[current];

        for(int i=0;i<adj.size();i++)
        {
            if( is_included(converted,adj[i]) == false )
            {
                q.push(adj[i]);
                converted.insert(adj[i]);
            }
        }
    }
}

void    print(set<string>& converted)
{
    for(set<string>::iterator it=converted.begin();it!=converted.end();it++)
    {
        cout<<*it<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    map<string,vector<string>>  operation;
    set<string> converted;

    input(operation);
    run(operation,converted);
    print(converted);

    return  0;
}