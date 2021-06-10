#include    <iostream>
#include    <string>
#include    <map>
#include    <set>

using namespace std;

#define MAX_LEN         15
#define MAX_HASH_VALUE  1000

typedef set<string> Stolen; 

int             N,M;
map<int,Stolen> stolen_passport[MAX_LEN+1];

int     get_hash_value(const string& str)
{
    int sum = 0;

    for(int i=0;i<str.length();i++)
    {
        sum += (int)str[i];
    }

    return  sum%MAX_HASH_VALUE;
}

void    read_stolen_passport(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int     n;
        string  str;

        cin>>str;
        n = get_hash_value(str);

        stolen_passport[str.length()][n].insert(str);
    }
}

int     find_passport(void)
{
    int ret = 0;

    cin>>M;

    for(int i=1;i<=M;i++)
    {
        int     n;
        string  str;

        cin>>str;
        n = get_hash_value(str);

        if( stolen_passport[str.length()][n].find(str) != stolen_passport[str.length()][n].end() )
        {
            ret++;
        }

    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_stolen_passport();
    cout<<find_passport()<<'\n';

    return  0;
}