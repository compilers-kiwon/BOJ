#include <iostream>
#include <stack>

using namespace std;

#define MAX_SIZE (1000000)

int robot[MAX_SIZE+1], num_of_parts[MAX_SIZE+1];

int get_robot(int part_num) {    
    stack<int> st;

    for (; robot[part_num] != part_num; part_num = robot[part_num]) {
        st.push(part_num);
    }

    for (; !st.empty(); st.pop()) {
        robot[st.top()] = part_num;
    }
    
    return part_num;
}

void assemble(int p1, int p2) {
    int r1 = get_robot(p1);
    int r2 = get_robot(p2);

    if (r1 == r2) {
        return;
    }

    robot[max(r1, r2)] = min(r1, r2);
    num_of_parts[min(r1, r2)] += num_of_parts[max(r1, r2)];
}

int get_num_of_parts(int p) {
    return num_of_parts[get_robot(p)];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin >> N;

    for (int i = 1; i <= MAX_SIZE; i++) {
        robot[i] = i, num_of_parts[i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        char m;
        int a, b, c;

        cin >> m;

        if (m == 'I') {
            cin >> a >> b;
            assemble(a, b);
        } else {
            cin >> c;
            cout << get_num_of_parts(c) << '\n';
        }
    }

    return 0;
}