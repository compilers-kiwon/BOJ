#include <iostream>

using namespace std;

int main(void) {
    int bS, bC, bO, bN;

    cin>>bS>>bC>>bO>>bN;
    cout<<min((bS + bN) / 3, (bC + (2 * bO)) / 6)<<'\n';

    return 0;
}