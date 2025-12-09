#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    deque<int> line;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        line.push_back(i);
    }

    bool reversed = false;

    for (int i = 1; i <= M; i++) {
        char c;

        cin >> c;

        if (c == 'A') {
            if (reversed == true) {
                line.push_front(line.back());
                line.pop_back();
            } else {
                line.push_back(line.front());
                line.pop_front();
            }
        } else {
            reversed = !reversed;
        }
    }

    for (; !line.empty();) {
        if (reversed == true) {
            cout << line.back() << '\n';
            line.pop_back();
        } else {
            cout << line.front() << '\n';
            line.pop_front();
        }
    }

    return 0;
}