#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  s1,s2;

    cin>>s1>>s2;s1+=s2;
    sort(s1.begin(),s1.end());

    cout<<s1<<'\n';
    return  0;
}