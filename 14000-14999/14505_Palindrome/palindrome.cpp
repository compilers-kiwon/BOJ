#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    30
#define TBD         -1

int dp[MAX_SIZE][MAX_SIZE];

void    init(string& str)
{
    cin>>str;

    for(int left=0;left<str.length();left++)
    {
        for(int right=0;right<str.length();right++)
        {
            dp[left][right] = TBD;
        }
    }
}

int     get_dp(int left,int right,const string& str)
{
    if( left > right )
    {
        return  0;
    }

    int&    ret = dp[left][right];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = 0;

    for(int i=left;i<right;i++)
    {
        if( str[i] == str[right] )
        {
            ret = ret+1+get_dp(i+1,right-1,str);
        }
    }

    ret = ret+1+get_dp(left,right-1,str);

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;

    init(str);
    cout<<get_dp(0,str.length()-1,str)<<'\n';

    return  0;
}