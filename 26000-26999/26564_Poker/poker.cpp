#include    <iostream>
#include    <string>

using namespace std;

#define NUM_OF_CARDS    5

const string rank = "A123456789TJQK";

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for (int i=1;i<=n;i++) {
        int max_strength = 0;
        int cnt[0x100] = {0,};

        for (int j=1;j<=NUM_OF_CARDS;j++) {
            string  card;
            cin>>card;
            max_strength = max(max_strength,++cnt[card.front()]);
        }

        cout<<max_strength<<'\n';
    }

    return  0;
}