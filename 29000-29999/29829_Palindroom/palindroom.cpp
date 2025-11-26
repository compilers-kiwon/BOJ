#include <iostream>
#include <vector>

using namespace std;

int get_num_of_diffs(vector<int>& nums) {
    int ret = 0;

    for (int h = 0, t = nums.size() - 1; h < t; h++, t--) {
        if (nums[h] != nums[t]) {
            nums[h] = nums[t], ret++;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> n;
    
    for (int num; cin >> num; n.push_back(num));

    if (get_num_of_diffs(n) <= 1) {
        cout << "JAH\n";

        for (int i = 0; i < n.size(); i++) {
            cout << n[i] << ((i==n.size()-1)?'\n':' ');
        }
    } else {
        cout << "EI\n";
    }

    return 0;
}