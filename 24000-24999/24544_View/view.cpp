#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,score[MAX_SIZE],sum;

    cin>>N;
    sum = 0;

    for(int i=1;i<=N;i++)
    {
        cin>>score[i];
        sum += score[i];
    }

    cout<<sum<<'\n';

    for(int i=1;i<=N;i++)
    {
        int registered;

        cin>>registered;
        sum -= (registered==1)?score[i]:0;
    }

    cout<<sum<<'\n';

    return  0;
}