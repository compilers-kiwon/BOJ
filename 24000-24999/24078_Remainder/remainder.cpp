#include <iostream>

using namespace std;

const int MOD_NUM = 21;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int X;
    cin >> X;
    cout << X % MOD_NUM << '\n';
    
    return 0;
}