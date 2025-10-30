#include <iostream>

using namespace std;

#define INF (0x7FFFFFFF)
#define LOWER_BOUND (48)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    bool result;

    for (cin >> n, result = true; n > 0; n--) {
        int h;
        cin >> h;
        result &= (h >= LOWER_BOUND);
    }

    cout << (result?"True":"False") << '\n';
    
    return 0;
}