#include    <iostream>
#include    <string>

using namespace std;

#define CHAR_SIZE   2

int main(void)
{
    string  str;

    cin>>str;

    for(int i=0;i<str.length();i+=CHAR_SIZE)
    {
        int     n;
        string  s;
        
        s = str.substr(i,CHAR_SIZE);
        sscanf(s.c_str(),"%X",&n);

        cout<<(char)n;
    }

    cout<<'\n';
    return  0;
}