#include    <iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

using namespace std;

#define is_upper(c)     ('A'<=(c)&&(c)<='Z')
#define get_lower(c)    ((c)+('a'-'A'))

typedef pair<string,string> Song;   // first:lower,second:original

void    get_lower_name(string& origin,string& result)
{
    for(int i=0;i<origin.length();i++)
    {
        char&   c = origin[i];

        if( is_upper(c) == true )
        {
            result.push_back(get_lower(c));
        }
        else
        {
            result.push_back(c);
        }
    }
}

bool    input(vector<Song>& list)
{
    int N;

    cin>>N;
    getchar();

    if( N == 0 )
    {
        return  false;
    }

    for(int i=1;i<=N;i++)
    {
        Song    s;

        getline(cin,s.second);
        get_lower_name(s.second,s.first);

        list.push_back(s);
    }

    return  true;
}

int     main(void)
{
    for(int i=1;;i++)
    {
        vector<Song>    list;

        if( input(list) == false )
        {
            break;
        }

        sort(list.begin(),list.end());

        cout<<i<<'\n';

        for(int j=0;j<list.size();j++)
        {
            cout<<list[j].second<<'\n';
        }
    }

    return  0;
}