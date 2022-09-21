#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string      str;
    set<string> sub;

    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        for(int len=1;len<=str.length()-i;len++)
        {
            sub.insert(str.substr(i,len));
        }
    }

    cout<<sub.size()<<'\n';

    return  0;
}