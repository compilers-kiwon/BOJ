#include    <iostream>
#include    <string>

using namespace std;

#define find_str(src,target)    \
    ((src).find((target))!=string::npos)


int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    string  str;

    getline(cin,str);
    cout<<((find_str(str,"D2")||find_str(str,"d2"))?"D2\n":"unrated\n");

    return  0;
}