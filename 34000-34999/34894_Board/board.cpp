#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const string displayed = "UOSPC";

typedef long long int int64;

#define TBD (-1LL)
#define NONE (5000000000LL+1LL)
#define MAX_SIZE (300000)

int N;
string S;
int64 a[MAX_SIZE];
unordered_map<string, int64> dp[MAX_SIZE];

void input(void) {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    dp[0]["U"] = dp[0]["UO"] = dp[0]["UOS"] =
            dp[0]["UOSP"] = dp[0]["UOSPC"] = NONE;
    
    if (S[0] == 'U') {
        dp[0]["U"] = a[0];
    }
}

int64 simulate(void) {
    int64 ret = NONE;

    for (int i = 1; i < N; i++) {
        char c = S[i];
        unordered_map<string, int64>& cur = dp[i];

        cur = dp[i-1];
        
        switch (c) {
            case 'U':
                cur["U"] = min(cur["U"], a[i]);
                break;
            case 'O':
                cur["UO"] = min(cur["UO"], cur["U"] + a[i]);
                break;
            case 'S':
                cur["UOS"] = min(cur["UOS"], cur["UO"] + a[i]);
                break;
            case 'P':
                cur["UOSP"] = min(cur["UOSP"], cur["UOS"] + a[i]);
                break;
            case 'C':
                cur["UOSPC"] = min(cur["UOSPC"], cur["UOSP"] + a[i]);
                break;
            default :
                // do nothing
                break;
        }
    }

    return dp[N-1]["UOSPC"];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 min_cost;

    input();
    min_cost = simulate();
    cout << ((min_cost==NONE)?-1LL:min_cost) << '\n';

    return 0;
}