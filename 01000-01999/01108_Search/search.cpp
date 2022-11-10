#include    <iostream>
#include    <string>
#include    <map>
#include    <set>

using namespace std;

typedef long long int   int64;
typedef set<string>     WebSite;

string              q;
set<string>         all;
map<string,WebSite> to,from,visitable;
map<string,int64>   dp;

void    input(void)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  w;
        int     a;

        cin>>w>>a;all.insert(w);

        for(int j=1;j<=a;j++)
        {
            string  s;

            cin>>s;all.insert(s);
            from[w].insert(s);to[s].insert(w);
        }
    }

    cin>>q;
}

void    dfs(string current,set<string>& v)
{
    if( v.find(current) != v.end() )
    {
        return;
    }

    v.insert(current);

    WebSite&    adj = to[current];

    for(WebSite::iterator it=adj.begin();it!=adj.end();it++)
    {
        dfs(*it,v);
    }
}

void    get_visitable(void)
{
    for(WebSite::iterator it=all.begin();it!=all.end();it++)
    {
        dfs(*it,visitable[*it]);
    }
}

int64   get_dp(string site)
{
    if( dp.find(site) != dp.end() )
    {
        return  dp[site];
    }

    dp[site] = 1;

    WebSite&    adj = from[site];

    for(WebSite::iterator it=adj.begin();it!=adj.end();it++)
    {
        if( visitable[site].find(*it) == visitable[site].end() )
        {
            dp[site] += get_dp(*it);
        }
    }

    return  dp[site];
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();get_visitable();
    cout<<get_dp(q)<<'\n';

    return  0;
}