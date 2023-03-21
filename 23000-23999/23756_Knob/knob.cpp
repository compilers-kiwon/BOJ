#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (100+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A[MAX_SIZE],sum;

    cin>>N;
    sum = 0;

    for(int i=0;i<=N;i++)
    {
        cin>>A[i];
    }

    for(int i=1;i<=N;i++)
    {
        int d1 = abs(A[i-1]-A[i]);
        int d2 = 360-d1;

        sum += min(d1,d2);
    }

    cout<<sum<<'\n';

    return  0;
}