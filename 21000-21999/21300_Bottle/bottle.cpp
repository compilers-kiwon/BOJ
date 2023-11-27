#include    <iostream>

using namespace std;

const static int NUM_OF_DIRNKS = 6;
const static int REFUND = 5;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int r = 0;

    for (int i=1;i<=NUM_OF_DIRNKS;i++) {
        int container;
        cin>>container;
        r += container*REFUND;
    }

    cout<<r<<'\n';
    return  0;
}