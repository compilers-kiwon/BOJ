#include    <iostream>

using namespace std;

int pow_int(int n,int e)
{
    int ret = 1;
    for (int i=1;i<=e;i++) ret*=n;
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,exp,sum;

    cin>>N>>exp;
    sum = 0;

    for (int i=1;i<=N;i++) {
        int m;
        
        cin>>m;
        sum = max(sum,
                max(pow_int(m,exp),
                    sum+pow_int(m,exp)));
    }

    cout<<sum<<'\n';
    return  0;
}