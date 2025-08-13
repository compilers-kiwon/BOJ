#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K;
    string str;

    cin >> N >> str >> K;

    if (str == "annyong") {
        K += ((K%2)==1)?0:1;
        K -= (K>N)?2:0;
    } else {
        K += ((K%2)==0)?0:1;
        K -= (K>N)?2:0;
    }

    cout << K << '\n';
    return 0;
}