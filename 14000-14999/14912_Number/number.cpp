#include    <iostream>

using namespace std;

int count_digit(int n,int d)
{
    int ret = 0;

    for(;n>0;n/=10)
    {
        ret += ((n%10==d)?1:0);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,d,cnt;

    cin>>n>>d;
    cnt = 0;

    for(int i=1;i<=n;i++)
    {
        cnt += count_digit(i,d);
    }

    cout<<cnt<<'\n';

    return  0;
}