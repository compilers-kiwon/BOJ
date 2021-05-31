#include    <iostream>

using namespace std;

#define MAX_SIZE    (500+1)
#define TBD         -1
#define MOD(n)      ((n)%1000000007)

#define CONS        0
#define VOWEL       1
#define MAX_LETTER  2

typedef long long int   int64;

int     C,V,L;
int64   dp[MAX_SIZE][MAX_LETTER];

int64   get_dp(int pos,int letter)
{
    int64&  ret = dp[pos][letter];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = get_dp(pos-1,VOWEL)*(int64)(letter==CONS?C:V);

    if( letter ==  VOWEL )
    {
        ret += get_dp(pos-1,CONS)*(int64)(letter==CONS?C:V);
    }

    return  (ret=MOD(ret));
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        cin>>C>>V>>L;

        for(int i=2;i<=L;i++)
        {
            dp[i][CONS] = dp[i][VOWEL] = TBD;
        }

        dp[1][CONS] = C;
        dp[1][VOWEL] = V;

        cout<<"Case #"<<t<<": "<<get_dp(L,VOWEL)<<'\n';
    }

    return  0;
}