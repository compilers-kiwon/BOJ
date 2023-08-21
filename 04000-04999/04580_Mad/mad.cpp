#include    <iostream>

using namespace std;

#define MAX_NUM (26+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int k;
        int cnt[MAX_NUM] = {0,};

        cin>>k;
        if (k == 0) break;

        for (int i=1;i<=k;i++) {
            cin>>cnt[i];
        }

        for (int i=1;i<=k;i++) {
            for (int j=1;j<=cnt[i]-cnt[i-1];j++) {
                cout<<i<<' ';
            }
        }

        cout<<'\n';
    }

    return  0;
}