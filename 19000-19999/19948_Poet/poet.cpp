#include    <iostream>
#include    <string>

using namespace std;

#define SUCCESS 0
#define FAIL    1

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define make_upper(c)       ((c)==' '||IN_RANGE('A',(c),'Z')?(c):(c)-32)

static int  cnt[0x100];

#define return_fail_if_cannot_type(c)   {if((cnt[(c)]--)==0)return FAIL;}

int type(const string& p,string& title)
{
    bool    t = true;

    for(int i=0;i<p.length();i++)
    {
        char    c = make_upper(p[i]);

        return_fail_if_cannot_type(c);

        if( c == ' ' )
        {
            t = true;
        }
        else
        {
            if( t == true )
            {
                return_fail_if_cannot_type(c);
                title.push_back(c);
                t = false;
            }
        }
    }

    return  SUCCESS;
}

int parse(const string& poet,string& parsed)
{
    for(int i=0;i<poet.length();i++)
    {
        if( parsed.empty() || parsed.back()!=poet[i] )
        {
            parsed.push_back(poet[i]);
        }
    }

    return  0;
}

int init(string& str)
{
    getline(cin,str);
    cin>>cnt[' '];
    for(char c='A';c<='Z';c++) cin>>cnt[c];

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  body,title,parsed;

    init(body);
    parse(body,parsed);

    if( type(parsed,title) == SUCCESS )
    {
        cout<<title<<'\n';
    }
    else
    {
        cout<<"-1\n";
    }

    return  0;
}