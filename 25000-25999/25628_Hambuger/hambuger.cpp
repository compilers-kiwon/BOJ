#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B;
    cin>>A>>B;
    
    cout<<min(A/2, B)<<'\n';
    return 0;
}