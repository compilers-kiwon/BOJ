#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

#define ALREADY_COUNTED ' '

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt = 0;
    string  str;
 
    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        if( str[i] == ALREADY_COUNTED )
        {
            continue;
        }

        set<char>   s;

        for(int j=i+1;j<str.length();j++)
        {
            if( str[j] == ALREADY_COUNTED )
            {
                continue;
            }

            if( str[i] == str[j] )
            {
                str[i] = str[j] = ALREADY_COUNTED;
                break;
            }

            if( s.find(str[j]) == s.end() )
            {
                s.insert(str[j]);
            }
            else
            {
                s.erase(str[j]);
            }
        }

        cnt += s.size();
    }

    cout<<cnt<<'\n';

    return  0;
}