#include    <iostream>
#include    <string>

using namespace std;

#define head_chr(str)   ((str)[0])

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=1;;i++)
    {
        string  str;

        getline(cin,str);

        if( head_chr(str) == '0' )
        {
            break;
        }

        cout<<"Case "<<i<<": Sorting... done!\n";
    }

    return  0;
}