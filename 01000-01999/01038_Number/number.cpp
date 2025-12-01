#include <iostream>
#include <queue>
#include <string>
#include <set>

using namespace std;

typedef long long int int64;

int64 get_num (set<int64>& numbers, int idx) {
    if (numbers.size() < (idx + 1)) {
        return -1LL;
    }

    auto it = numbers.begin();
    for (int i = 0; i < idx; i++, it++);
    return (*it);
}

void simulate(set<int64>& numbers, int num_of_numbers) {
    queue<string> q;

    for (int64 i = 0; i <= 9; i++) {
        q.push(to_string(i)), numbers.insert(i);
    }

    for (;!q.empty() && numbers.size() < (num_of_numbers + 1);) {
        for (int i = 1, size = q.size(); i <= size; i++, q.pop()) {
            string cur_num = q.front();

            for (char c = cur_num.front() + 1; c <= '9'; c++) {
                string next = string(1, c) + cur_num;
                int64 val = stoll(next);

                if (numbers.find(val) == numbers.end()) {
                    q.push(next), numbers.insert(val);
                }
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin >> N;

    if (N == 0) {
        cout << "0\n";
        return 0;
    }

    set<int64> num;
    
    simulate(num, N);
    cout << get_num(num, N) << '\n';

    return 0;
}