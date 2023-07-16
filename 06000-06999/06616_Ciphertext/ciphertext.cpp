#include    <iostream>
#include    <string>

using namespace std;

int get_raw_str(const string& str,string& raw)
{
    for(int i=0;i<str.length();i++)
    {
        if (isspace(str[i])) continue;
        raw.push_back(toupper(str[i]));
    }

    return  0;
}

int do_cipher(int offset,const string& src,string& dst)
{
    int src_pos = 0;

    for(int s=0;s<offset;s++)
    {
        for(int p=s;p<src.length();p+=offset)
        {
            dst[p] = src[src_pos++];
        }
    }

    return  0;
}

int main(void)
{
    for(;;)
    {
        int     N;
        string  str,raw,cipher;

        cin>>N;getchar();
        if (N==0) break;

        getline(cin,str);
        get_raw_str(str,raw);

        cipher = string(raw.length(),' ');
        do_cipher(N,raw,cipher);

        cout<<cipher<<'\n';
    }

    return  0;
}