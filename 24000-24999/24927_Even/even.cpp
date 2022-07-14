#include    <iostream>

using namespace std;

int get_num_of_two(int x)
{
    int ret;

    for(ret=0;(x>0)&&(x%2==0);x/=2)
    {
        ret++;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,K,num_of_two;

    cin>>N>>K;
    num_of_two = 0;

    for(int i=1;i<=N;i++)
    {
        int x;

        cin>>x;
        num_of_two += get_num_of_two(x);
    }

    cout<<(num_of_two>=K?1:0)<<'\n';

    return  0;
}