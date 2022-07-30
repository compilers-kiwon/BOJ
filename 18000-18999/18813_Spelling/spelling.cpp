#include    <iostream>
#include    <string>

using namespace std;

#define get_index(p)    ((int)((p)-'A')+1)

bool    find_duplicated_chrs(const string& str)
{
    string  prev;

    for(int i=0;i<str.length();i++)
    {
        char    c = str[i];

        if( prev.find(c) != string::npos )
        {
            return  true;
        }

        prev.push_back(c);
    }

    return  false;
}

bool    check_range_of_problems(const string& str,int upper)
{
    for(int i=0;i<str.length();i++)
    {
        char    c = str[i];

        if( get_index(c) > upper )
        {
            return  false;
        }
    }

    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,m,cnt;

    cin>>n>>m;
    cnt = 0;

    for(int i=1;i<=n;i++)
    {
        string  word;

        cin>>word;

        if( find_duplicated_chrs(word)==false
                && check_range_of_problems(word,m)==true )
        {
            cnt++;
        }
    }

    cout<<cnt<<'\n';

    return  0;
}