#include    <iostream>

using namespace std;

#define MAX_SCORE   (100)
#define MAX_SIZE    (100000+1)

static int  s[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,cnt[MAX_SCORE+1],r[MAX_SCORE+1];

    cin>>n;
    fill(&cnt[0],&cnt[MAX_SCORE+1],0);

    for (int i=1;i<=n;i++) {
        cin>>s[i];
        cnt[s[i]]++;
    }

    int cur_rank = 1;

    for (int i=MAX_SCORE;i>=0;i--) {
        r[i] = cur_rank;
        cur_rank += cnt[i];
    }

    for (int i=1;i<=n;i++) {
        cout<<r[s[i]]<<'\n';
    }

    return  0;
}