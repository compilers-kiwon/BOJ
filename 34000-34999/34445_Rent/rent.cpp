#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM_OF_ROOMATES (100000+1)

int N, c[MAX_NUM_OF_ROOMATES], R;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum_of_others;
    vector<int> contribution;

    cin >> N;
    sum_of_others = 0;

    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        sum_of_others += c[i];
    }

    cin >> R;

    int each_contribution = (R + sum_of_others) / N;

    if ((each_contribution * N) != (R + sum_of_others)) {
        each_contribution++;
    }

    for (int i = 1; i <= N; i++) {
        if (c[i] > each_contribution) {
            cout << "not possible\n";
            return 0;
        } else {
            contribution.push_back(each_contribution - c[i]);
        }
    }

    for (int i = 0; i < contribution.size(); i++) {
        cout << contribution[i] << '\n';
    }

    return 0;
}