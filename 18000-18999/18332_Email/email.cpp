#include    <iostream>
#include    <string>
#include    <vector>
#include    <set>

using namespace std;

int         n;
set<string> valid;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define lower2upper(c)      ('A'+((c)-'a'))

void    get_username_and_domain(string& str,string& username,string& domain)
{
    int i;

    for(i=0;i<str.length()&&str[i]!='@';i++)
    {
        username.push_back(str[i]);
    }

    for(++i;i<str.length();i++)
    {
        domain.push_back(str[i]);
    }
}

bool    parse_username(string& username,string& parsed)
{
    if( username.front()=='.' || username.back()=='.' )
    {
        return  false;
    }

    for(int i=0;i<username.length();i++)
    {
        char    c = username[i];

        if( !IN_RANGE('a',c,'z') && !IN_RANGE('A',c,'Z') && !IN_RANGE('0',c,'9') && c!='_' && c!='.' )
        {
            return  false;
        }

        if( c == '.' )
        {
            if( username[i-1] == '.' )
            {
                return  false;
            }
            else
            {
                continue;
            }
        }

        if( IN_RANGE('a',c,'z') == true )
        {
            c = lower2upper(c);
        }

        parsed.push_back(c);
    }

    return  IN_RANGE(6,parsed.length(),30);
}

bool    parse_domain(string& domain,string& parsed)
{
    if( domain.front()=='.' || domain.back()=='.' )
    {
        return  false;
    }

    string  tmp;

    domain.push_back('.');

    for(int i=0;i<domain.length();i++)
    {
        char    c = domain[i];

        if( !IN_RANGE('a',c,'z') && !IN_RANGE('A',c,'Z') && !IN_RANGE('0',c,'9') && c!='-' && c!='.' )
        {
            return  false;
        }

        if( c == '.' )
        {
            if( tmp.empty() )
            {
                return  false;
            }

            parsed += tmp;
            parsed.push_back('.');

            tmp.clear();
            continue;
        }

        if( IN_RANGE('a',c,'z') == true )
        {
            c = lower2upper(c);
        }

        tmp.push_back(c);
    }

    parsed.erase(parsed.length()-1,1);

    return  IN_RANGE(3,parsed.length(),30);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        string  str,u,d,parsed_username,parsed_domain;

        cin>>str;
        get_username_and_domain(str,u,d);

        if( parse_username(u,parsed_username) && parse_domain(d,parsed_domain) )
        {
            valid.insert(parsed_username+"@"+parsed_domain);
        }
    }

    cout<<valid.size()<<'\n';

    return  0;
}