#include <iostream>
#include <string>

using namespace std;

typedef long long int int64;

int64 get_score(const string& str) {
    int64 score, ret;

    score = ret = 1;

    for (size_t i = 1; i < str.length(); i++) {
        char prev = str[i-1];
        char cur = str[i];
        
        score = (prev<cur)?score+1:1; 
        ret += score;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S;
    cin >> S;
    cout << get_score(S) << '\n';

    return 0;
}