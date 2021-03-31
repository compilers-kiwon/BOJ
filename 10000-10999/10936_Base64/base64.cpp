#include    <iostream>
#include    <string>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define BASE64_A    0
#define BASE64_a    26
#define BASE64_0    52
#define BASE64_ADD  62
#define BASE64_DIV  63

#define BASE64_SIZE 6
#define ASCII_SIZE  8

int     get_byte_value(char base64)
{
    int ret;

    if( IN_RANGE('A',base64,'Z') )
    {
        ret = BASE64_A+(int)(base64-'A');
    }

    if( IN_RANGE('a',base64,'z') )
    {
        ret = BASE64_a+(int)(base64-'a');
    }

    if( IN_RANGE('0',base64,'9') )
    {
        ret = BASE64_0+(int)(base64-'0');
    }

    if( base64 == '+' )
    {
        ret = BASE64_ADD;
    }

    if( base64 == '/' )
    {
        ret = BASE64_DIV;
    }

    return  ret;
}

void    byte2str(string& ret,int n)
{
    for(int i=BASE64_SIZE-1;i>=0;i--)
    {
        int bit;

        bit = n&(1<<i);

        if( bit == 0 )
        {
            ret.push_back('0');
        }
        else
        {
            ret.push_back('1');
        }
    }
}

void    decode_base64(const string& base64,string& bin)
{
    for(int i=0;i<base64.length()&&base64[i]!='=';i++)
    {
        int n;

        n = get_byte_value(base64[i]);
        byte2str(bin,n);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  base64,ascii;

    cin>>base64;
    decode_base64(base64,ascii);
    
    if( ascii.length()%ASCII_SIZE != 0 )
    {
        ascii.erase((ascii.length()/ASCII_SIZE)*ASCII_SIZE,ascii.length()%ASCII_SIZE);
    }

    for(int i=0;i<ascii.length();i+=ASCII_SIZE)
    {
        char    c = 0;

        for(int j=0;j<ASCII_SIZE;j++)
        {
            c = (c<<1)+(ascii[i+j]=='0'?0:1);
        }

        cout<<c;
    }

    cout<<'\n';
    return  0;
}