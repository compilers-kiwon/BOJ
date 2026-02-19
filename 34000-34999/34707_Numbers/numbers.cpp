#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define DUMMY_NUM (-1)

bool is_semi_consecutive(const set<int>& n) {
    int diff = *(n.rbegin()) - *(n.begin());
    return ((diff + 1) == n.size());
}

void print_numbers(const vector<int>& n, int begin, int end) {
    for (int i = begin; i < end; ++i) {
        cout << n[i] << ' ';
    }
}

void input(int& N, int& K, vector<int>& numbers) {
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        numbers.push_back(n);
    }

    numbers.push_back(DUMMY_NUM);
}

bool simulate(int N, int K, int& h, int& t,
                    const vector<int>& numbers) {
    set<int> s;
    bool ret = false;

    for (int i = 0; i < K; ++i) {
        s.insert(numbers[i]);
    }

    for (h = 0, t = K; t <= N; ++h, ++t) {
        if (is_semi_consecutive(s) == true) {
            ret = true;
            break;
        }

        s.erase(numbers[h]);
        s.insert(numbers[t]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K, head, tail;
    vector<int> numbers;

    input(N, K, numbers);

    if (simulate(N, K, head, tail, numbers) == true) {
        cout << "YES\n";
        print_numbers(numbers, head, tail);
    } else {
        cout << "NO\n";
    }
    
    return 0;
}