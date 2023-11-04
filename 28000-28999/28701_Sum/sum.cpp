#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,sum1,sum2,sum3;

    cin>>N;
    
    sum1 = N*(N+1)/2; 
    sum2 = sum1*sum1;
    sum3 = 0;

    for (int i=1;i<=N;i++) {
        sum3 += i*i*i;
    }

    cout<<sum1<<'\n'<<sum2<<'\n'<<sum3<<'\n';
    return  0;
}