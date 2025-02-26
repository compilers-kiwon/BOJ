#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double a;

    cin>>a;
    cout<<fixed;cout.precision(6);
    cout<<sqrt(a)*4.0f<<'\n';

    return 0;
}