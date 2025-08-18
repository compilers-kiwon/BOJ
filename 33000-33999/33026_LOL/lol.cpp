#include <iostream>
#include <string>

using namespace std;

const char BREAD = 'L';
const char ONION = 'O';

int count(const string& s, const char& c) {
    int ret = 0;

    for (int i = 0; i < s.length(); i++) {
        ret += (s[i]==c)?1:0;
    }

    return ret;
}

int get_num_of_breads(const string& s) {
    return count(s, BREAD);
}

int get_num_of_onions(const string& s) {
    return count(s, ONION);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, ans;
    string food;

    ans = -1;
    cin >> n >> food;

    for (int i = 1; i < food.length(); i++) {
        string s1 = food.substr(0, i);
        string s2 = food.substr(i);

        if (get_num_of_breads(s1) != get_num_of_breads(s2)
                && get_num_of_onions(s1) != get_num_of_onions(s2)) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}