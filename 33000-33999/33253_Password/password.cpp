#include <iostream>
#include <string>

using namespace std;

void count_letters(const string& str, int table[]) {
    for (int i = 0; i < str.length(); i++) {
        table[str[i]]++;
    }
}

int get_num_of_new_letters(const string& new_str, int prev_str_table[]) {
    int ret = 0;

    for (int i = 0; i < new_str.length(); i++) {
        int& cnt_of_cur_letter = prev_str_table[new_str[i]];

        if (cnt_of_cur_letter > 0) {
            cnt_of_cur_letter--;
        } else {
            ret++;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, old_pw_letters[0x100];
    string old_pw, new_pw;

    cin >> n >> old_pw >> new_pw;
    fill(&old_pw_letters['a'], &old_pw_letters['z'] + 1, 0);

    count_letters(old_pw, old_pw_letters);
    cout << get_num_of_new_letters(new_pw, old_pw_letters) << '\n';

    return 0;
}