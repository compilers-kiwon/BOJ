#include    <iostream>

using namespace std;

int get_sum(int num,int shift)
{
    int ret = num;

    for(int i=1;i<=shift;i++)
    {
        num *= 10;
        ret += num;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,k;

    cin>>N>>k;
    cout<<get_sum(N,k)<<'\n';

    return  0;
}