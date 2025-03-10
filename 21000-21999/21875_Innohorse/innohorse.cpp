#include <iostream>
#include <string>

using namespace std;

int get_diff(int a, int b) {
    return (max(a,b) - min(a,b));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    string A, B;
    int d1, d2;

    cin>>A>>B;

    d1 = get_diff(A.back(), B.back());
    d2 = get_diff(A.front(), B.front());

    cout<<min(d1,d2)<<' '<<max(d1,d2)<<'\n';
    return 0;
}