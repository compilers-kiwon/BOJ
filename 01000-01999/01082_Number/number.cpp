#include <iostream>
#include <string>

using namespace std;

#define TBD (" ")
#define MAX_NUMBER (9)
#define MAX_SIZE (50+1)

int N, M, cost[MAX_NUMBER+1];
string dp[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> cost[i];
    }

    cin >> M;
    fill(&dp[0], &dp[M+1], TBD);
}

bool is_greater_or_equal(const string& n1, const string& n2) {
    if (n1.length() != n2.length()) {
        return (n1.length() > n2.length());
    }

    if (n1 == n2) {
        return true;
    }

    bool ret;

    for (int i = 0; i < n1.length(); ++i) {
        if (n1[i] != n2[i]) {
            ret = (n1[i] > n2[i]);
            break;
        }
    }

    return ret;
}

string build_number(const string& base, const string& new_digit) {
    if (base == "0" && new_digit == "0") {
        return "0";
    }

    if (base == "0") {
        return (new_digit + "0");
    }

    if (new_digit == "0") {
        return (base + "0");
    }

    string ret, head, tail;

    head = new_digit + base;
    tail = base + new_digit;
    ret  = is_greater_or_equal(head, tail)?head:tail;

    return ret;
}

string get_dp(int available) {
    string& ret = dp[available];

    if (ret != TBD) {
        return ret;
    }

    ret = "";

    for (int i = 0; i < N; ++i) {
        if (available < cost[i]) {
            continue;
        }

        string cur_num = to_string(i);
        string prev_num = get_dp(available - cost[i]);
        string tmp = build_number(prev_num, cur_num);

        if (ret.empty() || is_greater_or_equal(ret, tmp) == false) {
            ret = tmp;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string ans;

    input();
    ans = get_dp(M);
    cout << (ans.empty()?"0":ans) << '\n';

    return 0;
}