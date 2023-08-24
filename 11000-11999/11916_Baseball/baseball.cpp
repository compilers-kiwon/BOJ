#include    <iostream>

using namespace std;

#define BALL    1
#define HIT     2
#define WILD    3

#define HITTER      0
#define FIRST       1
#define SECOND      2
#define THIRD       3
#define HOME        4
#define MAX_SIZE    5

#define FOUR_BALL   4
#define OVERLAPPED  2

int move(int cnt[],int base)
{
    for (int i=THIRD;i>=base;i--) {
        cnt[i+1] += cnt[i];
        cnt[i] = 0;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cur;
    int cnt[MAX_SIZE] = {0,};

    cin>>N;
    cur = 0;

    for (int i=1;i<=N;i++) {
        int b;

        cin>>b;

        switch(b) {
            case    WILD:
                move(cnt,FIRST);
            case    BALL:
                cur++;
            case    HIT:
                if (cur==FOUR_BALL || b==HIT) {
                    cnt[FIRST]++;cur=0;
                    for (int i=FIRST;i<=THIRD&&cnt[i]==OVERLAPPED;i++) cnt[i+1]++,cnt[i]--;
                }
                break;
            default:/*do nothing*/;break;
        }
    }

    cout<<cnt[HOME]<<'\n';
    return  0;
}