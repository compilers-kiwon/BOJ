#include    <iostream>
#include    <string>

using namespace std;

const static int SCALER = 100;
const static int TICKS_PER_SEC = 4;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,t;

    cin>>n;
    n *= SCALER;
    t = TICKS_PER_SEC*SCALER;

    cout<<n/t<<'.'<<(n%t)/TICKS_PER_SEC<<'\n';
    return  0;
}