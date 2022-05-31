#include    <string>
#include    <iostream>

using namespace std;

#define NaN                 -1
#define chr2int(c)          ((int)((c)-'0'))
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int str2int(const string& str)
{
    int ret = 0;

    for(int i=0;i<str.length();i++)
    {
        if( !IN_RANGE('0',str[i],'9') )
        {
            ret = NaN;
            break;
        }
        else
        {
            ret = ret*10+chr2int(str[i]);
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  x,y;
    int     n,m;

    cin>>x>>y;

    n = str2int(x);
    m = str2int(y);

    if( n==NaN || m==NaN )
    {
        cout<<"NaN\n";
    }
    else
    {
        cout<<n-m<<'\n';
    }

    return  0;
}