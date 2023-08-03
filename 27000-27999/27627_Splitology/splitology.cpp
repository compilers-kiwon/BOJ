#include    <iostream>
#include    <string>

using namespace std;

bool    is_palindrome(const string& str)
{
    for(int h=0,t=str.length()-1;h<t;h++,t--)
    {
        if( str[h] != str[t] )
        {
            return  false;
        }
    }

    return  true;
}

int split(const string& str)
{
    for(int i=1;i<str.length();i++)
    {
        string  a = str.substr(0,i);
        string  b = str.substr(i,str.length()-i);

        if( is_palindrome(a) && is_palindrome(b) )
        {
            cout<<a<<' '<<b<<'\n';
            return  0;
        }
    }

    cout<<"NO\n";
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;

    cin>>str;
    split(str);

    return  0;
}