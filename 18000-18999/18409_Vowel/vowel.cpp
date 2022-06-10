#include    <iostream>
#include    <string>

using namespace std;

const string    vowels = "aiueo";

int count_vowels(const string& str)
{
    int ret = 0;

    for(int i=0;i<vowels.length();i++)
    {
        for(int j=0;j<str.length();j++)
        {
            if( vowels[i] == str[j] )
            {
                ret++;
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  str;

    cin>>N>>str;
    cout<<count_vowels(str)<<'\n';

    return  0;
}