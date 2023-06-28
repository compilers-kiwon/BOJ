#include    <iostream>
#include    <string>

using namespace std;

#define to_upper_str(str) \
    for(int i=0;i<(str).length();i++)(str)[i]=toupper((str)[i]);

string  encode(const string& str,int min_length)
{
    char    cur = str.front();
    int     cnt = 1;
    bool    replaced[0x100] = {false,};
    string  ret;

    for(int i=1;i<str.length();i++)
    {
        if( str[i] == cur )
        {
            cnt++;
        }
        else
        {
            if( replaced[cur] == false )
            {
                replaced[cur] = true;
                ret.push_back(cnt>=min_length?'1':'0');
            }

            cur = str[i];
            cnt = 1;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    string  str;
    int     K;

    cin>>str>>K;
    to_upper_str(str);

    str.push_back(' ');
    cout<<encode(str,K)<<'\n';

    return  0;
}