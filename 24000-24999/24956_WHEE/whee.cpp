#include    <iostream>

using namespace std;

#define MAX_SIZE    (200000+1)
#define MOD(n)      ((n)%1000000007)

typedef long long int   int64;

int     N;
int64   W,WH,WHE,WHEE;
char    S[MAX_SIZE+1];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>&S[1];

    for(int i=1;i<=N;i++)
    {
        switch(S[i])
        {
            case    'W':
                W++;W=MOD(W);
                break;
            case    'H':
                WH=WH+W;WH=MOD(WH);
                break;
            case    'E':
                WHEE=WHEE+WHEE+WHE;WHEE=MOD(WHEE);
                WHE=WHE+WH;WHE=MOD(WHE);
                break;
            default:
                // do nothing
                break;
        }
    }

    cout<<WHEE<<'\n';

    return  0;
}