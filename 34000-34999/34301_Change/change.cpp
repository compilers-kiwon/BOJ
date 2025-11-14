#include <iostream>
#include <stack>

using namespace std;

const int bills[] = {150, 30, 15, 5, 1};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    stack<int> st;

    cin >> N;

    for (int i = 0; i < (sizeof(bills) / sizeof(int)); i++) {
        st.push(N / bills[i]);
        N %= bills[i];
    }

    for (; !st.empty(); st.pop()) {
        cout << st.top() << ((st.size()==1)?'\n':' ');
    }

    return 0;
}