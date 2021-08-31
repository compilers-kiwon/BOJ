#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define ADD -1
#define MUL -2

int morse2int(const string& m)
{
    int ret = 0;

    for(int i=0;i<m.length();i++)
    {
        int n;

        switch(m[i])
        {
            case    '.':
                n = 1;
                break;
            case    '-':
                n = 5;
                break;
            case    ':':
                n = 2;
                break;
            case    '=':
                n = 10;
                break;
            default:
                // do nothing
                break;
        }

        ret += n;
    }

    return  ret;
}

void    input(vector<int>& result)
{
    int     N;
    string  str;
    char    c;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>str>>c;

        result.push_back(morse2int(str));
        result.push_back((c=='+')?ADD:MUL);
    }

    cin>>str;
    result.push_back(morse2int(str));
}

int     calculate(vector<int>& e)
{
    vector<int> buf;

    buf.push_back(e[0]);

    for(int i=1;i<e.size();i++)
    {
        int&    n = e[i];

        if( buf.back() == MUL )
        {
            buf.pop_back();
            buf.back() *= n;
        }
        else
        {
            buf.push_back(n);
        }
    }

    for(;buf.size()!=1;)
    {
        int n1,n2;

        n1 = buf.back();
        buf.pop_back();

        buf.pop_back();

        n2 = buf.back();
        buf.pop_back();

        buf.push_back(n1+n2);
    }

    return  buf.front();
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> exp;

    input(exp);
    cout<<calculate(exp)<<'\n';

    return  0;
}