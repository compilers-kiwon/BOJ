#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    stack<int> st;

    for (cin >> n; n > 0; n--) {
        int num;

        cin >> num;

        if (!st.empty() && (st.top() + num) % 2 == 0) {
            st.pop();
        } else {
            st.push(num);
        }
    }

    cout << st.size() << '\n';

    return 0;
}