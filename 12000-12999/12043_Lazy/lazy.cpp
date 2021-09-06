#include    <iostream>
#include    <string>

using namespace std;

#define MOD(n)              ((n)%1000000007)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int get_num_of_candidates(const string& str,int pos)
{
    int     ret = 0;
    bool    counted[0x100];

    fill(&counted['a'],&counted['z'+1],false);

    for(int offset=-1;offset<=1;offset++)
    {
        if( !IN_RANGE(0,pos+offset,str.length()-1) || counted[str[pos+offset]]==true )
        {
            continue;
        }

        counted[str[pos+offset]] = true;
        ret++;
    }

    return  ret;
}

int get_dp(const string& str,int pos)
{
    if( pos == -1 )
    {
        return  1;
    }

    int ret,n,dp;
    
    ret = 0;
    n = get_num_of_candidates(str,pos);
    dp = get_dp(str,pos-1);

    for(int i=1;i<=n;i++)
    {
        ret = MOD(ret+dp);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        string  str;

        cin>>str;
        cout<<"Case #"<<t<<": "<<get_dp(str,str.length()-1)<<'\n';
    }

    return  0;
}