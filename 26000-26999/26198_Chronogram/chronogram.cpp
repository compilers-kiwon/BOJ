#include    <iostream>
#include    <string>

using namespace std;

static int  convert[0x100];

int init(void)
{
    convert['I'] = 1;
    convert['V'] = 5;
    convert['X'] = 10;
    convert['L'] = 50;
    convert['C'] = 100;
    convert['D'] = 500;
    convert['M'] = 1000;

    return  0;
}

int decode(const string& str)
{
    int ret = 0;

    for(int i=0;i<str.length();i++)
    {
        ret += convert[str[i]];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     T;
    string  str;

    init();
    
    getline(cin,str);
    T = stoi(str);

    for(int t=1;t<=T;t++)
    {
        getline(cin,str);
        cout<<decode(str)<<'\n';
    }

    return  0;
}