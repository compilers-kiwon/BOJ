#include <iostream>

using namespace std;

#define MAX_SIZE (1000+100)

bool visited[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, p;

    for (cin >> n >> p; n > 1; n--) {
        int S;
        cin >> S;
        visited[S] = true;
    }

    for (; visited[p] != false;p++);
    cout << p << '\n';

    return 0;
}