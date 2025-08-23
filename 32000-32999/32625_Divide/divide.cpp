#include <iostream>
#include <vector>

using namespace std;

void analyze(const vector<int>& num, int head, 
                int tail, int& min_num, int& max_num) {
    min_num = 0x7FFFFFFF, max_num = 0;

    for (int i = head; i < tail; i++) {
        min_num = min(min_num, num[i]);
        max_num = max(max_num, num[i]);
    }
}

bool divide(const vector<int>& num, int size) {
    int i, sum;

    for (i = sum = 0; i < num.size(); i += size) {
        int min_num, max_num;

        analyze(num, i, i + size, min_num, max_num);

        if (sum != 0 && sum != (min_num + max_num)) {
            return false;
        }

        sum = min_num + max_num;
    }

    return true;
}

bool simulate(const vector<int>& num) {
    for (int i = 1; i < num.size(); i++) {
        if ((num.size() % i) != 0) {
            continue;
        }

        if (divide(num, i) == true) {
            return true;
        }
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> num;

    for (cin >> N; N > 0; N--) {
        int A;
        cin >> A;
        num.push_back(A);
    }

    cout << (simulate(num)?1:0) << '\n';
    return 0;
}