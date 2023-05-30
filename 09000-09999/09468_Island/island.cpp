#include    <iostream>

using namespace std;

#define SEQ_LEN 15

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int P;

    cin>>P;

    for(int p=1;p<=P;p++)
    {
        int K,num[SEQ_LEN],cnt;

        cin>>K;
        cnt = 0;

        for(int i=0;i<SEQ_LEN;i++)
        {
            cin>>num[i];
        }

        for(int i=1;i<SEQ_LEN;i++)
        {
            cnt += (num[i-1]<num[i])?1:0;
        }

        cout<<K<<' '<<cnt<<'\n';
    }

    return  0;
}