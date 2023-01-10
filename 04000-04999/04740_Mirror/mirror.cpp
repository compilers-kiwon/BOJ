#include    <iostream>
#include    <string>

using namespace std;

#define END_OF_INPUT    "***"

void    print_backwards(const string& str)
{
    for(int i=str.length()-1;i>=0;i--)
    {
        cout<<str[i];
    }

    cout<<'\n';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        string  str;

        getline(cin,str);

        if( str == END_OF_INPUT )
        {
            break;
        }
        else
        {
            print_backwards(str);
        }
    }

    return  0;
}