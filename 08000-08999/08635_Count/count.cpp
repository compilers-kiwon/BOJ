#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    int N,cnt[0x100];

    cin>>N;getchar();
    fill(cnt,cnt+0x100,0);

    for(int i=1;i<=N;i++)
    {
        string  str;

        getline(cin,str);
        for(int j=0;j<str.length();j++) cnt[(int)str[j]]++;
    }

    for(char c='a';c<='z';c++)
        if( cnt[(int)c]!=0 ) cout<<c<<' '<<cnt[(int)c]<<'\n';

    for(char c='A';c<='Z';c++)
        if( cnt[(int)c]!=0 ) cout<<c<<' '<<cnt[(int)c]<<'\n';

    return  0;
}