#include    <iostream>
#include    <string>

using namespace std;

#define init_str(str,c) \
    {(str).clear();(str).push_back((c));}

#define REQUIRED_LEN        3
#define need_to_count(str)  ((str).length()==REQUIRED_LEN)

#define is_continuous(prev,current) (((current)-(prev))==1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     cnt = 0;
    string  str,buf;

    cin>>str;
    
    str.push_back(0);
    init_str(buf,0);

    for(int i=0;i<str.length();i++)
    {
        if( is_continuous(buf.back(),str[i]) )
        {
            buf.push_back(str[i]);
        }
        else
        {
            cnt += need_to_count(buf)?1:0;
            init_str(buf,str[i]);
        }
    }

    cout<<cnt<<'\n';

    return  0;
}