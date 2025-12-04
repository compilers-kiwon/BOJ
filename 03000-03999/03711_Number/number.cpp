#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

size_t get_num_of_mods(const vector<int>& numbers, int m) {
    unordered_set<int> s;

    for (int i = 0; i < numbers.size(); i++) {
        s.insert(numbers[i] % m);
    }

    return s.size();
}

void input(vector<int>& numbers) {
    int G;

    for (cin >> G; G > 0; G--) {
        int n;
        cin >> n;
        numbers.push_back(n);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        vector<int> nums;

        input(nums);

        for (int i = nums.size();; i++) {
            if (get_num_of_mods(nums, i) == nums.size()) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}