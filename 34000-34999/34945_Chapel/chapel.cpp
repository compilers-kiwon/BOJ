#include <iostream>

using namespace std;

const int CUR = 2;
const int SUCCESS = 8;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int x;
    cin >> x;
    cout << (CUR+x>=SUCCESS?"Success!":"Oh My God!") << '\n';

    return 0;
}