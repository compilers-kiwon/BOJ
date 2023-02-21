#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

const vector<pair<char,string>> r = {
    {'A',"BCDF"},{'B',"CDF"},{'C',"DF"}
};

#define is_included(s,c)    ((s).find((c))!=string::npos)

int replace(string& str,int r_idx)
{
    for(int i=0;i<str.length();i++)
    {
        char&   c = str[i];

        if( is_included(r[r_idx].second,c) )
        {
            c = r[r_idx].first;
        }
    }

    return  0;
}

int simulate(string& str)
{
    for(int i=0;i<r.size();i++)
    {
        if( is_included(str,r[i].first) )
        {
            replace(str,i);
            return  0;
        }
    }

    for(int i=0;i<str.length();i++)
    {
        str[i] = 'A';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;

    cin>>str;
    simulate(str);
    cout<<str<<'\n';

    return  0;
}