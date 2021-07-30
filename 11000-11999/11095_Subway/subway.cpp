#include    <iostream>
#include    <string>
#include    <vector>
#include    <map>
#include    <set>

using namespace std;

typedef set<string> Station;

map<string,Station> connected;
map<string,bool>    visited;
string              from,to;

void    parse(const string& str,vector<string>& stations)
{
    string  s;

    for(int i=0;i<str.length();i++)
    {
        if( str[i] == ' ' )
        {
            stations.push_back(s);
            s.clear();
        }
        else
        {
            s.push_back(str[i]);
        }
    }
}

void    input(void)
{
    int N;

    cin>>N;getchar();

    for(int i=1;i<=N;i++)
    {
        string          str;
        vector<string>  s;

        getline(cin,str);
        
        str.push_back(' ');
        parse(str,s);

        for(int i=1;i<s.size();i++)
        {
            string& s1 = s.front();
            string& s2 = s[i];

            connected[s1].insert(s2);
            connected[s2].insert(s1);
        }

        for(int i=0;i<s.size();i++)
        {
            visited[s[i]] = false;
        }
    }

    cin>>from>>to;
}

bool    dfs(const string& current,vector<string>& passed)
{
    if( current == to )
    {
        return  true;
    }

    Station::iterator it;

    for(it=connected[current].begin();it!=connected[current].end();it++)
    {
        if( visited[*it] == true )
        {
            continue;
        }

        passed.push_back(*it);
        visited[*it] = true;

        if( dfs(*it,passed) == true )
        {
            return  true;
        }

        visited[*it] = false;
        passed.pop_back();
    }

    return  false;
}

int     main(void)
{
    input();

    vector<string>  visited_stations;

    visited[from] = true;
    visited_stations.push_back(from);

    if( dfs(from,visited_stations) == true )
    {
        for(int i=0;i<visited_stations.size()-1;i++)
        {
            cout<<visited_stations[i]<<' ';
        }
        cout<<visited_stations.back()<<'\n';
    }
    else
    {
        cout<<"no route found\n";
    }

    return  0;
}