#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    size_t K;
    string str = "AKA";

    cin>>K;
    
    for (size_t i = 1; i <= K; i++) {
        str += "RAKA";
    }

    cout <<str<<'\n';

    return 0;
}