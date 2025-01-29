#include <iostream>

using namespace std;

const int COMMEMORATIVE = 2024;
const int MAX_NUM = 100000;

int main (void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    
    cin>>N;
    
    if (N <= MAX_NUM && (N % COMMEMORATIVE) == 0) {
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }

    return 0;
}