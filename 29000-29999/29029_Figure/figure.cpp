#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,max_cnt;
    int     cnt[0x100] = {0,};
    string  figures;

    cin>>N>>figures;
    max_cnt = 0;

    for (int i=0;i<figures.length();i++) {
        max_cnt = max(max_cnt,++cnt[figures[i]]);
    }

    cout<<N-max_cnt<<'\n';
    return  0;
}