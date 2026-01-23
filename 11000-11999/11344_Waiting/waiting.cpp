#include <iostream>
#include <string>
#include <deque>

using namespace std;

typedef pair<string, int> Student;

void input(deque<Student>& A) {
    int N;

    for (cin >> N; N > 0; --N) {
        Student s;
        cin >> s.first >> s.second;
        A.push_back(s);
    }
}

deque<Student> simulate(deque<Student>& A) {
    int num_of_changes;
    deque<Student> B, ret;

    for (num_of_changes = 0; !A.empty();) {
        if (num_of_changes != 0 && !B.empty()) {
            --num_of_changes, B.pop_front();
        } else {
            Student s = A.front();
            
            A.pop_front();

            if (s.second == 15) {
                ++num_of_changes;
            } else {
                if (num_of_changes != 0) {
                    --num_of_changes;
                } else {
                    B.push_back(s);

                    if (B.size() > ret.size()) {
                        ret = B;
                    }
                }
            }
        }
    }

    return ret;
}

void print(deque<Student>& maxLen) {
    if (maxLen.empty()) {
        cout << "Line B stayed empty.\n";
    } else {
        for (; !maxLen.empty(); maxLen.pop_front()) {
            cout << maxLen.front().first << ' ';
        }

        cout << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; --t) {
        deque<Student> A, maxLen;

        input(A);
        maxLen = simulate(A);
        print(maxLen);
    }

    return 0;
}