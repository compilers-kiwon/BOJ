#include    <iostream>
#include    <string>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const static string left_keys = "qwertyasdfgzxcvbQWERTYASDFGZXCVB";
const static string right_keys = "uiophjklnmUIOPHJKLNM";

#define is_included(str,c)  ((str).find((c))!=string::npos)

int get_cnt(const string& str,
        int& left_cnt,int& right_cnt)
{
    int ret;

    ret = left_cnt = right_cnt = 0;

    for(int i=0;i<str.length();i++)
    {
        ret += (str[i]==' '||IN_RANGE('A',str[i],'Z'))?1:0;
        left_cnt += is_included(left_keys,str[i])?1:0;
        right_cnt += is_included(right_keys,str[i])?1:0;
    }

    return  ret;
}

int balance_key_cnt(int& left_cnt,int& right_cnt,int& etc_cnt)
{
    for(;etc_cnt!=0&&left_cnt!=right_cnt;etc_cnt--)
    {
        if( left_cnt < right_cnt )
        {
            left_cnt++;
        }
        else
        {
            right_cnt++;
        }
    }
    
    left_cnt += (etc_cnt/2)+(etc_cnt%2);
    right_cnt += (etc_cnt/2);

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     left_cnt,right_cnt,etc_cnt;
    string  str;

    getline(cin,str);
    etc_cnt = get_cnt(str,left_cnt,right_cnt);

    balance_key_cnt(left_cnt,right_cnt,etc_cnt);
    cout<<left_cnt<<' '<<right_cnt<<'\n';

    return  0;
}