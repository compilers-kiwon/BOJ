#include    <iostream>

using namespace std;

const static int NUM_OF_DAYS_PER_WEEK = 7;
const static int NUM_OF_DAYS_IN_NOV = 30;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A,B;
    cin>>A>>B;
    cout<<(A+B*NUM_OF_DAYS_PER_WEEK
            <=NUM_OF_DAYS_IN_NOV?1:0)<<'\n';

    return  0;
}