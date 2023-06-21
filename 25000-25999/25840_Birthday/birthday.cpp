#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

int input(set<string>& days)
{
    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        string  d;

        cin>>d;
        days.insert(d);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    set<string> s;

    input(s);
    cout<<s.size()<<'\n';

    return  0;
}