#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,ptr;
    string  str;

    cin>>str;
    
    for(n=ptr=0;ptr<str.length();)
    {
        string  s = to_string(++n);
        
        for(int i=0;ptr<str.length()&&i<s.length();i++)
        {
            (s[i]==str[ptr])?ptr++:0;
        }
    }

    cout<<n<<'\n';

    return  0;
}