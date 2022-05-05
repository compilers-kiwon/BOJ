#include    <iostream>

using namespace std;

#define FRONT   0
#define BACK    1
#define MAX_CNT 2

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,cnt[MAX_CNT];

    cin>>n;
    cnt[FRONT] = cnt[BACK] = 0;

    for(int i=1;i<=n;i++)
    {
        int a;

        cin>>a;
        cnt[a]++;
    }

    cout<<min(cnt[FRONT],cnt[BACK])<<'\n';

    return  0;
}