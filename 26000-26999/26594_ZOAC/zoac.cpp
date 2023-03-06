#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str,s;
    char    p;

    cin>>str;
    p = ' ';

    for(int i=0;i<str.length();i++)
    {
        if( str[i] != p )
        {
            p = str[i];
            s.push_back(p);
        }
    }

    cout<<str.length()/s.length()<<'\n';

    return  0;
}