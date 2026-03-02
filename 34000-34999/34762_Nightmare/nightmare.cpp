#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K, M;
    vector<int> S;
    
    cin >> N >> K >> M;
    
    for (int i = 1; i <= M; ++i) {
        int s;
        cin >> s;
        S.push_back(s);
    }

    S.push_back(N + 1);

    for (int i = 0; i < S.size() - 1; ++i) {
        int cur = S[i];
        int next = S[i+1];
        int diff = next - cur;

        if (!(diff == 1 || diff > (K + 1))) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}