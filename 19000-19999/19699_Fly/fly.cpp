#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX_NUM_OF_COWS (9)
#define MAX_WEIGHT_OF_COW (1000)

void get_prime_table(vector<bool>& prime_table) {
    prime_table[1] = false;

    for (int i = 2; i < prime_table.size(); ++i) {
        if (prime_table[i] == false) {
            continue;
        }

        for (int j = i + i; j < prime_table.size(); j += i) {
            prime_table[j] = false;
        }
    }
}

int get_sum_of_weight(const vector<int>& weights) {
    int ret = 0;

    for (int i = 0; i < weights.size(); ++i) {
        ret += weights[i];
    }

    return ret;
}

void simulate(vector<int>& w, vector<int>& selected, set<int>& sum,
                int selectable_size, const vector<bool>& prime_table) {
    if (selected.size() == selectable_size) {
        int sum_of_weight = get_sum_of_weight(selected);

        if (prime_table[sum_of_weight] == true) {
            sum.insert(sum_of_weight);
        }

        return;
    }

    for (int i = 0; i < w.size(); ++i) {
        if (w[i] == 0) {
            continue;
        }

        selected.push_back(w[i]);
        w[i] = 0;

        simulate(w, selected, sum, selectable_size, prime_table);

        w[i] = selected.back();
        selected.pop_back();
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    set<int> sum_of_weights;
    vector<int> weights, selected;
    vector<bool> prime_table(MAX_NUM_OF_COWS * MAX_WEIGHT_OF_COW + 1, true);

    cin >> N >> M;
    get_prime_table(prime_table);

    for (int i = 1; i <= N; ++i) {
        int H;
        cin >> H;
        weights.push_back(H);
    }

    simulate(weights, selected, sum_of_weights, M, prime_table);

    if (sum_of_weights.empty()) {
        sum_of_weights.insert(-1);
    }

    for (auto it = sum_of_weights.begin(); it != sum_of_weights.end(); ++it) {
        cout << *it << ' ';
    }

    return 0;
}