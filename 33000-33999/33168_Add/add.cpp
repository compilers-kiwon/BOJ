#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> A;

    for (cin >> N; N > 0; N--) {
        int num;
        cin >> num;
        A.push_back(num);
    }

    for (; A.size() != 1;) {
        int arr_size = A.size();

        for (int i = 0; i < (arr_size - 1); i++) {
            int sum = A[i] + A[i+1];
            cout << sum << ' ';
            A.push_back(sum);
        }

        cout << '\n';
        A.erase(A.begin(), A.begin() + arr_size);
    }

    return 0;
}