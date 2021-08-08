#include    <iostream>
#include    <vector>
#include    <string>
#include    <map>

using namespace std;

#define MAX_COST    1000000001
#define MAX_SIZE    (50+1)
#define NONE        0

typedef pair<int,string>    Material;
typedef unsigned long long  uint64;

int                 N,M;
vector<Material>    exp[MAX_SIZE];
map<string,int>     dp;

#define char2int(c)         ((int)((c)-'0'))
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int     str2int(const string& str)
{
    int ret = 0;

    for(int i=0;i<str.length();i++)
    {
        ret = ret*10+char2int(str[i]);
    }

    return  ret;
}

void    get_material(string& str,Material& m)
{
    string  num,name;

    for(int i=0;i<str.length();i++)
    {
        char&   c = str[i];

        if( IN_RANGE('0',c,'9') )
        {
            num.push_back(c);
        }
        else
        {
            name.push_back(c);
        }
    }

    m.first = max(1,str2int(num));
    m.second = name;
}

void    parse(string& str,vector<Material>& v)
{
    string  tmp;

    str.push_back('+');

    for(int i=0;i<str.length();i++)
    {
        char&   c = str[i];

        if( c=='=' || c=='+' )
        {
            Material    m;

            get_material(tmp,m);
            v.push_back(m);
            tmp.clear();
        }
        else
        {
            tmp.push_back(c);
        }
    }
}

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        string  str;
        int     n;

        cin>>str>>n;
        dp[str] = n;
    }

    for(int i=1;i<=M;i++)
    {
        string              str;
        vector<Material>&   m = exp[i];

        cin>>str;
        parse(str,m);
    }
}

bool    is_completed(vector<Material>& m)
{
    for(int i=1;i<m.size();i++)
    {
        string& liquid = m[i].second;

        if( dp[liquid] == NONE )
        {
            return  false;
        }
    }

    return  true;
}

int     multiply(const int& n,const string& str)
{
    int     ret = 0;
    int&    c = dp[str];

    for(int i=1;i<=n;i++)
    {
        ret += c;

        if( ret >= MAX_COST )
        {
            return  MAX_COST;
        }
    }

    return  ret;
}

int     get_cost(vector<Material>& m)
{
    int ret = 0;

    for(int i=1;i<m.size();i++)
    {
        int&    coef = m[i].first;
        string& liquid = m[i].second;
        
        ret += multiply(coef,liquid);

        if( ret >= MAX_COST )
        {
            return  MAX_COST;
        }
    }

    return  ret;
}

void    calculate_liquid(void)
{
    for(;;)
    {
        bool    updated = false;

        for(int i=1;i<=M;i++)
        {
            vector<Material>&   current = exp[i];
            string&             left = current.front().second;

            if( is_completed(current) == false )
            {
                continue;
            }

            int c = get_cost(current);

            if( dp[left]==NONE || c<dp[left] )
            {
                dp[left] = c;
                updated = true;
            }
        }

        if( updated == false )
        {
            break;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    calculate_liquid();
    
    int answer = dp["LOVE"];

    if( answer == NONE )
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<answer<<'\n';
    }

    return  0;
}