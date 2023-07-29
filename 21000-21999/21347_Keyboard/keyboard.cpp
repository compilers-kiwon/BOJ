#include    <iostream>
#include    <string>

using namespace std;

#define count(str,val,table) \
    {for(int i=0;i<(str).length();i++)(table)[(str)[i]]+=val;}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  s,t;
    int cnt[0x100] = {0,};

    getline(cin,s);count(s,1,cnt);
    getline(cin,t);count(t,-1,cnt);

    for (int i=0;i<0x100;i++)
    {
        if (cnt[i] != 0) cout<<(char)i;
    }

    cout<<'\n';
    return  0;
}