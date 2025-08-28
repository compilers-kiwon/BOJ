#include <iostream>
#include <string>
#include <deque>
#include <stack>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    deque<char> cur;
    stack<int> st;

    for (cin >> N; N > 0; N--) {
        int num;
        char c;

        cin >> num;

        switch (num) {
            case 1:
                cin >> c;
                cur.push_back(c), st.push(num);
                break;
            case 2:
                cin >> c;
                cur.push_front(c), st.push(num);
                break;
            case 3:
                if (!cur.empty()) {
                    if (st.top() == 1) {
                        cur.pop_back();
                    } else {
                        cur.pop_front();
                    }

                    st.pop();
                }
                break;
            default:
                // do nothing
                break;
        }
    }

    string str;

    for (; !cur.empty(); cur.pop_front()) {
        str.push_back(cur.front());
    }

    cout << (str.empty()?"0":str) << '\n';
    return 0;
}