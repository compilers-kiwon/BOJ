#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

#define MAX_SIZE    1000
#define MOD(n)      ((n)%1000000007)
#define TBD         -1

int dp[0x100][MAX_SIZE];

int     get_dp(const string& str,char c,int pos)
{
    int&    ret = dp[(int)c][pos];

    if( ret != TBD )
    {
        return  ret;
    }

    // pos,pos-1,pos-2
    set<char>   p;

    for(int i=0;i<=2;i++)
    {
        if( pos-i < 0 )
        {
            break;
        }

        p.insert(str[pos-i]);
    }

    set<char>::iterator it;

    for(ret=0,it=p.begin();it!=p.end();it++)
    {
        ret = MOD(ret+get_dp(str,*it,pos-1));
    }

    return  ret;
}

void    init(const string& str)
{
    for(char c='a';c<='z';c++)
    {
        fill(&dp[(int)c][0],&dp[(int)c][str.length()],TBD);
    }

    dp[str[0]][0] = dp[str[1]][0] = 1;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        string  str;

        cin>>str;
        cout<<"Case #"<<t<<": ";

        if( str.length() == 1 )
        {
            cout<<"1\n";
            continue;
        }

        int w1,w2;

        init(str);
        w1 = get_dp(str,str[str.length()-1],str.length()-1);

        if( str[str.length()-1] != str[str.length()-2] )
        {
            w2 = get_dp(str,str[str.length()-2],str.length()-1);
        }
        else
        {
            w2 = 0;
        }
        
        cout<<MOD(w1+w2)<<'\n';
    }

    return  0;
}