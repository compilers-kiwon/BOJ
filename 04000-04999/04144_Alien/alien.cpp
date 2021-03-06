#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

const string    n = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#define get_digit_num(a)    (n[(a)])
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef unsigned int    uint32;

uint32  get_dec_value(const char& c)
{
    uint32 ret;

    if( IN_RANGE('0',c,'9') )
    {
        ret = (uint32)(c-'0');
    }
    else
    {
        ret = (uint32)(c-'A')+10;
    }

    return  ret;
}

uint32  str2dec(const string& str,uint32 b)
{
    uint32  ret = 0;

    for(int i=0;i<str.length();i++)
    {
        ret = ret*b+get_dec_value(str[i]);
    }

    return  ret;
}

void    dec2str(uint32 d,uint32 b,string& result)
{
    if( d == 0 )
    {
        result.push_back('0');
        return;
    }
    
    for(;d>0;d/=b)
    {
        result.push_back(get_digit_num(d%b));
    }

    for(int h=0,t=result.length()-1;h<t;h++,t--)
    {
        swap(result[h],result[t]);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        uint32  x,y,d;
        string  z,converted;

        cin>>x>>y>>z;
        d = str2dec(z,x);

        dec2str(d,y,converted);
        cout<<converted<<'\n';
    }

    return  0;
}