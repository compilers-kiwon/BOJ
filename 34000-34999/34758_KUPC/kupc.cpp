#include <iostream>
#include <vector>

using namespace std;

void simulate(int X, int Y, vector<int>& result) {
    int N;

    for (cin >> N; N > 0; --N) {
        int x, y;
        cin >> x >> y;
        result.push_back((x==X||y==Y)?0:1);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X, Y;
    vector<int> num_of_turns;

    cin >> X >> Y;
    simulate(X, Y, num_of_turns);

    for (int i = 0; i < num_of_turns.size(); ++i) {
        cout << num_of_turns[i] << '\n';
    }

    return 0;
}