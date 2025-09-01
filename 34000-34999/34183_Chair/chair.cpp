#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M, A, B;

    cin >> N >> M >> A >> B;

    int num_of_required_chairs = max(0, (N * 3) - M);

    cout << ((num_of_required_chairs==0)?0:
                (num_of_required_chairs * A) + B) << '\n';

    return 0;
}