#include <iostream>
#include <vector>

using namespace std;

typedef long long int int64;

void input(vector<int>& A, vector<int>& B) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        A.push_back(num);
    }

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        B.push_back(num);
    }
}

int64 build_number(const vector<int>& num) {
    int64 ret = 0;

    for (int i = 0; i < num.size(); i++) {
        int cur = num[i];
        ret = ret*(cur<10?10:100) + cur;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> A, B;
    int64 X, Y;

    input(A, B);
    X = build_number(A);
    Y = build_number(B);

    cout << min(X, Y) << '\n';
    return 0;
}