#include    <iostream>
#include    <string>

using namespace std;

#define get_offset(c)   ((int)((c)-'A')+1)

string  decode(const string& str)
{
    string  ret;
    int     pos;

    for(pos=0;pos<str.length();pos+=get_offset(str[pos]))
    {
        ret.push_back(str[pos]);
    }

    return  ret;
}

int main(void)
{
    string  str;

    cin>>str;
    cout<<decode(str)<<'\n';

    return  0;
}