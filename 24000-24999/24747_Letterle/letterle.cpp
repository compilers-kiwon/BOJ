#include    <iostream>
#include    <string>

using namespace std;

#define NUM_OF_GUESSES  7

char    find_chr(const string& str,char c,int pos)
{
    if( str[pos] == c )
    {
        return  'G';
    }

    if( str.find(c,0) != string::npos )
    {
        return  'Y';
    }

    return  'X';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  letterle;
    bool    win = false;

    cin>>letterle;

    for(int i=1;i<=NUM_OF_GUESSES;i++)
    {
        string  g,result;

        cin>>g;

        if( letterle == g )
        {
            win = true;
            break;
        }

        if( i == NUM_OF_GUESSES )
        {
            break;
        }

        for(int j=0;j<g.length();j++)
        {
            result.push_back(find_chr(letterle,g[j],j));
        }

        cout<<result<<'\n';
    }

    if( win == true )
    {
        cout<<"WINNER\n";
    }
    else
    {
        cout<<"LOSER\n";
    }

    return  0;
}