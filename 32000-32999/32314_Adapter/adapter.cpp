#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int a, w, v;

    cin>>a>>w>>v;
    cout<<((w/v)>=a?1:0)<<'\n';

    return 0;
}