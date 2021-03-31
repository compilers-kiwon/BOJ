#include    <iostream>
#include    <string>

using namespace std;

int press_key(const string& required)
{
    int     ret = 1;
    char    prev = ' ';

    for(int i=0;i<required.length();i++)
    {
        if( required[i] <= prev )
        {
            ret++;
        }

        prev = required[i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;

    cin>>str;
    cout<<press_key(str)<<'\n';

    return  0;
}