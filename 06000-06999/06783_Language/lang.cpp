#include    <iostream>
#include    <string>

using namespace std;

static int  cnt[0x100];

#define is_English(table) \
    ((table)['t']+(table)['T']>(table)['s']+(table)['S'])

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  str;

    for(cin>>N;cin>>str;)
    {
        for(int i=0;i<str.length();i++) cnt[str[i]]++;
    }

    cout<<(is_English(cnt)?"English":"French")<<'\n';
    return  0;
}