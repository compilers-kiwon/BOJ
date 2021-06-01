#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

char    N;

int     str2int(const string& str)
{
    int ret = 0;

    for(int i=0;i<str.length();i++)
    {
        ret = ret*10+(int)(str[i]-'0');
    }

    return  ret;
}

int     calculate(vector<char>& exp)
{
    int     ret,sign;
    string  tmp;

    ret=0;sign=1;
    exp.push_back('+');

    for(int i=0;i<exp.size();i++)
    {
        char&   c = exp[i];

        if( c == ' ' )
        {
            continue;
        }

        if( c=='+' || c=='-' )
        {
            ret += sign*str2int(tmp);
            tmp.clear();

            sign = (c=='+')?1:-1;
        }
        else
        {
            tmp.push_back(c);
        }
    }
    
    exp.pop_back();

    return  ret;
}

void    print_exp(const vector<char>& exp)
{
    for(int i=0;i<exp.size();i++)
    {
        cout<<exp[i];
    }
}

void    dfs(vector<char>& exp,char current)
{
    if( current > N )
    {
        if( calculate(exp) == 0 )
        {
            print_exp(exp);cout<<'\n';
        }

        return;
    }

    exp.push_back(' ');exp.push_back(current);
    dfs(exp,current+1);
    exp.pop_back();exp.pop_back();

    exp.push_back('+');exp.push_back(current);
    dfs(exp,current+1);
    exp.pop_back();exp.pop_back();

    exp.push_back('-');exp.push_back(current);
    dfs(exp,current+1);
    exp.pop_back();exp.pop_back();
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        cin>>N;

        vector<char> exp;

        exp.push_back('1');
        dfs(exp,'2');

        cout<<'\n';
    }

    return  0;
}