#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

int             n,k;    
map<string,int> title;

void    parse_title(const string& str)
{
    string  current;
    int     cnt = 1;

    for(int i=0;i<str.length();i++)
    {
        if( str[i] == ' ' )
        {
            cnt++;
            current.clear();
        }
        else
        {
            current.push_back(str[i]);
        }
    }

    if( title.find(current)==title.end() || title[current]<cnt )
    {
        title[current] = cnt;
    }
}

int     get_min_num_of_emails(void)
{
    int ret = 0;

    for(map<string,int>::iterator it=title.begin();it!=title.end();it++)
    {
        ret += it->second;
    }

    return  ret;
}

int     main(void)
{
    cin>>n>>k;
    getchar();

    for(int i=1;i<=k;i++)
    {
        string  str;

        getline(cin,str);
        parse_title(str);
    }

    if( get_min_num_of_emails() <= n )
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }

    return  0;
}