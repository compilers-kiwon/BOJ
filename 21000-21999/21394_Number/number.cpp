#include    <iostream>

using namespace std;

#define MAX_NUM     9
#define MAX_SIZE    (1000+1)

int init(int x[])
{
    int ret = 0;

    for (int i=1;i<=MAX_NUM;i++) {
        cin>>x[i];
        ret += x[i];
    }

    x[9]+=x[6];x[6]=0;
    return  ret;
}

int simulate(int num_of_cards,int x[],int ordered[])
{
    int left_pos = 1;
    int right_pos = num_of_cards;

    for (int i=1,num=9;i<=num_of_cards;) {
        if (x[num] == 0) {
            num--;
            continue;
        }

        if (i%2 == 1) {
            ordered[left_pos++] = num;
        } else {
            ordered[right_pos--] = num;
        }

        i++;x[num]--;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int  n,x[MAX_NUM+1],cards[MAX_SIZE],left_pos,right_pos;

        n = init(x);
        simulate(n,x,cards);

        for (int i=1;i<=n;i++) {
            cout<<cards[i]<<(i==n?'\n':' ');
        }
    }

    return  0;
}