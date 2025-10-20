#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    deque<int> in, A;

    for (cin >> N; N > 0; N--) {
        in.push_front(N);
    }

    for (int i = 0; !in.empty(); i++) {
        if ((i % 2) == 0) {
            A.push_front(in.back());
            in.pop_back(); 
        } else {
            A.push_front(in.front());
            in.pop_front();
        }
    }

    for (; !A.empty(); A.pop_front()) {
        cout << A.front() << ' ';
    }

    return 0;
}