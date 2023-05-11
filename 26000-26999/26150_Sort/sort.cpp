#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

typedef pair<string,int>    Problem;

static map<int,Problem> p;

#define Sort(table,s,i,d)   ((table)[(i)]=make_pair((s),(d)))
#define Index(result,s,d)   ((result).push_back(toupper((s)[(d)-1])))

int input(void)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int     I,D;
        string  S;

        cin>>S>>I>>D;
        Sort(p,S,I,D);
    }

    return  0;
}

int solve(void)
{
    string  str;

    map<int,Problem>::iterator  it;

    for(it=p.begin();it!=p.end();it++)
    {
        string& S = it->second.first;
        int&    D = it->second.second;

        Index(str,S,D);
    }

    cout<<str<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    solve();

    return  0;
}