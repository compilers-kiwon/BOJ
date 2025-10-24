#include <iostream>

using namespace std;

#define is_odd(n) (((n)%2)!=0)

int simulate(int num) {
    int num_of_steps;

    for (num_of_steps = 0; num != 1; num_of_steps++) {
        if (is_odd(num)) {
            num += (num * 2) + 1; 
        } else {
            num /= 2;
        }
    }

    return num_of_steps;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    cout << simulate(N) << '\n';

    return 0;
}