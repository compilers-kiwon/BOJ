#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int x, y;

    cin>>x>>y;
    cout<<((x>y)?x+y:y-x)<<'\n';

    return 0;
}