#include <iostream>

using namespace std;

typedef pair<int, int> Time;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char c;
    Time alram, woke_up;

    cin >> alram.first >> c >> alram.second;
    cin >> woke_up.first >> c >> woke_up.second;

    cout << ((alram<woke_up)?"YES":"NO") << '\n';

    return 0;
}