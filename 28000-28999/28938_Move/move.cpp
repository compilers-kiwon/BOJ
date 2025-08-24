#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, sum;

    for (cin >> n, sum = 0; n > 0; n--) {
        int m;
        cin >> m;
        sum += m;
    }

    cout << ((sum==0)?"Stay":
            (sum<0)?"Left":"Right") << '\n';
    return 0;
}