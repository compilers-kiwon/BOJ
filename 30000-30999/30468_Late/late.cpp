#include    <iostream>

using namespace std;

const static int NUM_OF_STATS = 4;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum,N;

    sum = 0;

    for (int i=1;i<=NUM_OF_STATS;i++) {
        int s;
        cin>>s;
        sum += s;    
    }

    cin>>N;
    cout<<max(NUM_OF_STATS*N-sum,0)<<'\n';

    return  0;
}