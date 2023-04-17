#include    <iostream>
#include    <string>

using namespace std;

int hex2str(const string& str,string& result)
{
    for(int i=0;i<str.length();i+=2)
    {
        string  tmp;
        int     n;

        tmp.push_back(str[i]);
        tmp.push_back(str[i+1]);

        sscanf(tmp.c_str(),"%X",&n);
        result.push_back((char)n);
    }

    return  0;
}

int main(void)
{
    for(;;)
    {
        string  str,ret;

        cin>>str;

        if( str.empty() )
        {
            break;
        }

        hex2str(str,ret);
        cout<<ret<<'\n';
    }

    return  0;
}