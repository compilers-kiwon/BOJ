#include <iostream>
#include <stack>

using namespace std;

#define INF (-1)
#define MAX_SIZE (400000+1)

typedef pair<int, int> Price; // <day, value>

int n, p[MAX_SIZE], day[MAX_SIZE];
stack<Price> st;

void input(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    st.push({1, p[1]});
}

void simulate(void) {
    for (int cur_day = 2; cur_day <= n; cur_day++) {
        int cur_val = p[cur_day];

        for (; !st.empty(); st.pop()) {
            int prev_day = st.top().first;
            int prev_val = st.top().second;

            if (prev_val < cur_val) {
                break;
            }

            day[prev_day] = cur_day - prev_day;
        }

        st.push({cur_day, cur_val});
    }

    for (; !st.empty(); st.pop()) {
        day[st.top().first] = INF;
    }
}

void print(void) {
    for (int i = 1; i <= n; i++) {
        if (day[i] != INF) {
            cout << day[i] << '\n';
        } else {
            cout << "infinity\n";
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();

    return 0;
}