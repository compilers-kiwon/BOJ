#include    <iostream>
#include    <string>

using namespace std;

int table[0x100];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(char c='A';c<='Z';c++)
    {
        table[c] = ((c=='T'||c=='D'||c=='L'||c=='F')?2:1);
    }

    string  str;
    int     cnt;

    cin>>str;
    cnt = 1;

    for(int i=0;i<str.length();i++)
    {
        cnt *= table[str[i]];
    }

    cout<<cnt<<'\n';

    return  0;
}