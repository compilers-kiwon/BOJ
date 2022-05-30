#include    <iostream>
#include    <string>

using namespace std;

void    compress_str(string& str)
{
    char    prev_chr = ' ';
    int     cnt = 0;

    str.push_back(' ');

    for(int i=0;i<str.length();i++)
    {
        char&   c = str[i];

        if( prev_chr==' ' || prev_chr!=c )
        {
            if( cnt != 0 )
            {
                cout<<cnt<<' '<<prev_chr<<' ';
            }

            cnt = 1;
            prev_chr = c;
        }
        else
        {
            cnt++;
        }
    }

    cout<<'\n';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  str;

        cin>>str;
        compress_str(str);
    }

    return  0;
}