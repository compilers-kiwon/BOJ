#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     cnt[0x100] = {0,};
    string  str;

    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        cnt[str[i]]++;
    }

    cout<<cnt['A']<<" : "<<cnt['B']<<'\n';

    return  0;
}