#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;
    int     N,s,t;

    cin>>N>>str;
    s = t = 0;

    for(int i=0;i<N;i++)
    {
        (str[i]=='s')?s++:t++;
    }

    for(int i=0;i<N;i++)
    {
        if( s == t )
        {
            cout<<str.substr(i,s+t);
            break;
        }

        (str[i]=='s')?s--:t--;
    }

    return  0;
}