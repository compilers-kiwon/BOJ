#include    <iostream>
#include    <string>

using namespace std;

#define HEAD_CHR    'C'

char    get_key(char from,char to)
{
    char    ret;

    for(ret=0x0;ret<0x100;ret++)
    {
        if( (from^ret) == to )
        {
            break;
        }
    }

    return  ret;
}

string  decode_str(const string& str,char key)
{
    string  ret;

    for(int i=0;i<str.length();i++)
    {
        for(char c=0x0;c<0x100;c++)
        {
            if( (c^key) == str[i] )
            {
                ret.push_back(c);
                break;
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char    k;
    string  str;
    
    cin>>str;
    k = get_key(HEAD_CHR,str.front());

    cout<<decode_str(str,k)<<'\n';

    return  0;
}