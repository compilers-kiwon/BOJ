#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=0;;i++)
    {
        string  str;

        getline(cin,str);

        if( str.empty() )
        {
            cout<<i<<'\n';
            break;
        }
    }

    return  0;
}