#include <iostream>
#include <vector>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    double sum = 0.0;
    vector<double> data;

    cin >>  N;

    if (N == 0) {
        cout << "0\n";
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        double f;
        cin >> f;
        data.push_back(f), sum += f;
    }

    double avg = sum / (double)N;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        double& cur = data[i];

        if (!IN_RANGE(avg - 10.0f, cur, avg + 10.0f)) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}