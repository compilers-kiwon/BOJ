#include    <iostream>
#include    <string>
#include    <vector>
#include    <queue>
#include    <map>

using namespace std;

#define REMOVABLE   2

void    parse(string& src,vector<int>& result)
{
    result.push_back(1);

    for(int i=1;i<src.length();i++)
    {
        char&   prev_char = src[i-1];
        char&   current_char = src[i];

        if( prev_char == current_char )
        {
            result.back()++;
        }
        else
        {
            result.push_back(1);
        }
    }
}

void    remove_consecutive_letters(string& src,vector<int>& table,
                                   map<string,bool>& visited,queue<string>& q)
{
    int pos = 0;

    for(int i=0;i<table.size();i++)
    {
        if( table[i] >= REMOVABLE )
        {
            string  new_str;

            new_str = src.substr(0,pos)
                +src.substr(pos+table[i],src.length()-(pos+table[i]));

            if( visited[new_str] == false )
            {
                visited[new_str] = true;
                q.push(new_str);
            }
        }

        pos += table[i];
    }
}

int     simulate(string& str)
{
    queue<string>       str_q;
    map<string,bool>    visited;

    str_q.push(str);
    visited[str] = true;

    for(;!str_q.empty();str_q.pop())
    {
        string      current;
        vector<int> sub_str_table;

        current = str_q.front();

        if( current.empty() == true )
        {
            return  1;
        }

        parse(current,sub_str_table);
        remove_consecutive_letters(current,sub_str_table,visited,str_q);
    }

    return  0;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        string              str;

        cin>>str;
        cout<<simulate(str)<<'\n';
    }

    return  0;
}