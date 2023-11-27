#include    <iostream>

using namespace std;

const static int NUM_OF_UNITS = 6;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,quantity[NUM_OF_UNITS],T,P;

    cin>>N;
    for (int i=0;i<NUM_OF_UNITS;i++) cin>>quantity[i];
    cin>>T>>P;

    int sum = 0;

    for (int i=0;i<NUM_OF_UNITS;i++) {
        sum += quantity[i]/T+((quantity[i]%T==0)?0:1);
    }

    cout<<sum<<'\n'<<N/P<<' '<<N%P<<'\n';
    return  0;
}