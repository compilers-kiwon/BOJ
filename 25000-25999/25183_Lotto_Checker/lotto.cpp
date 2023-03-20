#include    <iostream>
#include    <string>

using namespace std;

bool    win(const string& str)
{
    for(int i=1;i<=4;i++)
    {
        if( str[i]+1!=str[i-1] && str[i]!=str[i-1]+1 )
        {
            return  false;
        }
    }

    return  true;
}

bool    check_lotto(const string& str)
{
    for(int i=0;i<str.length()-4;i++)
    {
        string  s = str.substr(i,5);

        if( win(s) == true )
        {
            return  true;
        }
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  lotto;

    cin>>N>>lotto;
    cout<<(check_lotto(lotto)?"YES":"NO")<<'\n';

    return  0;
}