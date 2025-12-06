#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<int> q;
    int n, max_size, tail;

    cin >> n, max_size = 0;

    for (int i = 1; i <= n; i++) {
        int e, a;

        cin >> e;

        if (e == 1) {
            cin >> a;
            q.push(a);

            if (q.size() >= max_size) {
                if (q.size() == max_size) {
                    tail = min(tail, a);
                } else {
                    max_size = q.size(), tail = a;
                }
            }
        } else {
            q.pop();
        }
    }

    cout << max_size << ' ' << tail << '\n';
    
    return 0;
}