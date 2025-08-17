#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, excluded;

    for (cin >> n, excluded = 0; n > 0; n--) {
        int d;
        cin >> d;
        excluded += (d%2==1)?1:0;
    }

    cout << excluded << '\n';
    return 0;
}