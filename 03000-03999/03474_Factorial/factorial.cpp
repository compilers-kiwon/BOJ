#include    <iostream>

using namespace std;

int get_num_of_zero(int n)
{
    int ret = 0;

    for(int m=5;m<=n;m*=5)
    {
        ret += n/m;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int N;

        cin>>N;
        cout<<get_num_of_zero(N)<<'\n';
    }

    return  0;
}