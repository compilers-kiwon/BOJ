#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,cnt;

    cin>>n;
    cnt = 0;

    for(int left=1;left<=5;left++)
    {
        for(int right=left;right<=5;right++)
        {
            cnt += (left+right==n?1:0);
        }
    }

    cnt += (n<=5?1:0);
    cout<<cnt<<'\n';

    return  0;
}