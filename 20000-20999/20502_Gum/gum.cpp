#include    <iostream>
#include    <set>

using namespace std;

typedef pair<int,int>   Article;    // first: rank, second: idx

#define EMPTY       "-1\n"
#define MAX_SIZE    (100+1)

int input(set<Article> s[])
{
    int N,M,my_rank[MAX_SIZE],m,k;

    cin>>N>>M;
    for (int i=1;i<=N;i++) cin>>my_rank[i];

    for (int i=1;i<=N;i++) {
        cin>>m;
        for (int j=1;j<=m;j++) {
            cin>>k;
            s[k].insert({my_rank[i],i});
        }
    }

    return  0;
}

int print_articles(set<Article>& a)
{
    set<Article>::iterator  it;

    for (it=a.begin();it!=a.end();it++) {
        cout<<it->second<<' ';
    }

    cout<<'\n';
    return  0;
}

int do_query(set<Article> s[])
{
    int Q,k;

    cin>>Q;

    for (int i=1;i<=Q;i++)
    {
        cin>>k;
        if (s[k].empty()) cout<<EMPTY;
        else print_articles(s[k]);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    set<Article>    articles[MAX_SIZE];

    input(articles);
    do_query(articles);

    return  0;
}