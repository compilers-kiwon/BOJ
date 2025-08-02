#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define MAX_SIZE (50+1)

unordered_map<string, bool> visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];

bool is_visited(int A, int B, int C, char penultimate, char last) {
    string s;

    s.push_back(penultimate);
    s.push_back(last);

    return visited[A][B][C][s];
}

void set_visited(int A, int B, int C, char penultimate, char last) {
    string s;

    s.push_back(penultimate);
    s.push_back(last);

    visited[A][B][C][s] = true;
}

bool dfs(int A_num, int B_num, int C_num, string& cur, char penultimate, char last) {
    if (A_num == 0 && B_num == 0 && C_num == 0) {
        return true;
    }

    if (A_num != 0 && !is_visited(A_num - 1, B_num, C_num, last, 'A')) {
        set_visited(A_num - 1, B_num, C_num, last, 'A');
        
        cur.push_back('A');

        if (dfs(A_num - 1, B_num, C_num, cur, last, 'A') == true) {
            return true;
        }

        cur.pop_back();
    }

    if (B_num != 0 && last != 'B' && !is_visited(A_num, B_num - 1, C_num, last, 'B')) {
        set_visited(A_num, B_num - 1, C_num, last, 'B');
        
        cur.push_back('B');

        if (dfs(A_num, B_num - 1, C_num, cur, last, 'B') == true) {
            return true;
        }

        cur.pop_back();
    }

    if (C_num != 0 && penultimate != 'C' && last != 'C'
            && !is_visited(A_num, B_num, C_num - 1, last, 'C')) {
        set_visited(A_num, B_num, C_num - 1, last, 'C');
        
        cur.push_back('C');

        if (dfs(A_num, B_num, C_num - 1, cur, last, 'C') == true) {
            return true;
        }

        cur.pop_back();
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    string s, ans;
    int cnt[0x100] = {0, };
    
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        cnt[s[i]]++;
    }

    if (dfs(cnt['A'], cnt['B'], cnt['C'], ans, ' ', ' ') == false) {
        ans = "-1";
    }

    cout << ans << '\n';

    return 0;
}