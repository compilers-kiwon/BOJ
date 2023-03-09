#include    <iostream>
#include    <string>

using namespace std;

string  remove_consecutive_letters(const string& str)
{
    string  ret = " ";

    for(int i=0;i<str.length();i++)
    {
        if( ret.back() != str[i] )
        {
            ret.push_back(str[i]);
        }
    }

    ret.erase(ret.begin());
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  str;

        cin>>str;
        cout<<remove_consecutive_letters(str)<<'\n';
    }

    return  0;
}