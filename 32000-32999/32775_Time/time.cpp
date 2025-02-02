#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int S, F;

    cin>>S>>F;
    cout<<((F<S)?"flight":"high speed rail")<<'\n';

    return 0;
}