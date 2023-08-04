#include    <iostream>
#include    <string>
#include    <vector>
#include    <set>
#include    <map>
#include    <algorithm>

using namespace std;

typedef pair<int,set<string>>       State;
typedef struct{int n;string s,h;}   Group;

static map<string,State>    group;

bool    compare(const Group& g1,const Group& g2)
{
    if( g1.n != g2.n )
    {
        return  g1.n>g2.n;
    }

    return  g1.h<g2.h;
}

int input(void)
{
    for(string str;cin>>str;)
    {
        string  sorted = str;

        sort(sorted.begin(),sorted.end());

        group[sorted].first++;
        group[sorted].second.insert(str);
    }

    return  0;
}

int sort_group(vector<Group>& g)
{
    map<string,State>::iterator it;

    for(it=group.begin();it!=group.end();it++)
    {
        g.push_back({it->second.first,
            it->first,*(it->second.second.begin())});
    }

    sort(g.begin(),g.end(),compare);
    return  0;
}

int print(const vector<Group>& g)
{
    int num_of_groups = min(5,(int)g.size());

    for(int i=0;i<num_of_groups;i++)
    {
        set<string>& anagram = group[g[i].s].second;
        set<string>::iterator it = anagram.begin();

        cout<<"Group of size "<<g[i].n<<": ";
        for(;it!=anagram.end();it++) cout<<*(it)<<' ';
        cout<<".\n";
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Group>   anagram_groups;

    input();
    sort_group(anagram_groups);
    print(anagram_groups);

    return  0;
}