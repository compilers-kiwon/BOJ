#include    <iostream>
#include    <string>
#include    <vector>
#include    <map>

using namespace std;

typedef vector<string>  AND;

#define INF 0x7FFFFFFF

void    get_condition(string& str,string& name,int& time)
{
    int i;

    str.push_back(':');

    for(i=0;str[i]!=':';i++)
    {
        name.push_back(str[i]);
    }

    for(++i,time=0;str[i]!=':';i++)
    {
        time = time*10+(int)(str[i]-'0');
    }
}

void    parse_condition(string& str,map<string,int>& cond)
{
    string  tmp;

    str.push_back(',');

    for(int i=0;i<str.length();i++)
    {
        char&   c = str[i];

        if( c == ',' )
        {
            string  n;
            int     t;

            get_condition(tmp,n,t);
            cond[n] = t;

            tmp.clear();
        }
        else
        {
            tmp.push_back(c);
        }
    }
}

void    get_combination(string& str,AND& result)
{
    string  tmp;

    str.push_back('&');

    for(int i=0;i<str.length();i++)
    {
        char&   c = str[i];

        if( c == '&' )
        {
            result.push_back(tmp);
            tmp.clear();
        }
        else
        {
            tmp.push_back(c);
        }
    }
}

void    parse_combination(string& str,vector<AND>& combi)
{
    string  tmp;

    str.push_back('|');

    for(int i=0;i<str.length();i++)
    {
        char&   c = str[i];

        if( c == '|' )
        {
            AND a;

            get_combination(tmp,a);
            combi.push_back(a);

            tmp.clear();
        }
        else
        {
            tmp.push_back(c);
        }
    }
}

int     get_max_time(const AND& a,map<string,int>& t)
{
    int ret = 0;

    for(int i=0;i<a.size();i++)
    {
        ret = max(ret,t[a[i]]);
    }

    return  ret;
}

int     calculate(const vector<AND>& a,map<string,int>& t)
{
    int ret = INF;

    for(int i=0;i<a.size();i++)
    {
        ret = min(ret,get_max_time(a[i],t));
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        string          condition,combination;
        vector<AND>     comb_exp;
        map<string,int> time_table;

        cin>>condition>>combination;

        parse_condition(condition,time_table);
        parse_combination(combination,comb_exp);

        cout<<calculate(comb_exp,time_table)<<'\n';
    }

    return  0;
}