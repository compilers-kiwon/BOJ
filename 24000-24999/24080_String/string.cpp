#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N;
    string      str;
    set<char>   chrs;

    cin>>N>>str;

    for(int i=0;i<N;i++)
    {
        chrs.insert(str[i]);
    }

    if( chrs.size() >= 3 )
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }

    return  0;
}