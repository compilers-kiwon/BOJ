#include    <iostream>
#include    <string>

using namespace std;

#define is_included(str,c)  ((str).find((c))!=string::npos)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;

    cin>>str;

    for(char c='A';c<='Z';c++)
    {
        if( !is_included(str,c) )
        {
            cout<<c<<'\n';
            break;
        }
    }

    return  0;
}